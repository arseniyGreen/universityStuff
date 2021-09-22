#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Element
{
    //элемент связного списка
private:
    //указатель на предыдущий и следующий элемент
    Element* next;
    Element* prev;

    //информация, хранимая в поле
    T field;
public:
    Element(){ next = prev = nullptr; };
    Element(T value){ next = prev = nullptr; field = value; }

    //доступ к полю *next
    virtual Element* getNext() { return next; }
    virtual void setNext(Element* value) { next = value; }

    //доступ к полю *prev
    virtual Element* getPrevious() { return prev; }
    virtual void setPrevious(Element* value) { prev = value; }

    //доступ к полю с хранимой информацией field
    virtual T getValue() { return field; }
    virtual void setValue(T value) { field = value; }

    template<class T1> friend ostream& operator<< (ostream& ustream, Element<T1>& obj);
};

template<class T>
ostream& operator << (ostream& ustream, Element<T>& obj)
{
    ustream << obj.field;
    return ustream;
}

template <class T>
class LinkedListParent
{
protected:
    //достаточно хранить начало и конец
    Element<T>* head;
    Element<T>* tail;
    //для удобства храним количество элементов
    int num;
public:
    virtual int Number() { return num; }

    virtual Element<T>* getBegin() { return head; }

    virtual Element<T>* getEnd() { return tail; }

    LinkedListParent()
    {
        //конструктор без параметров
        cout << "\nParent constructor";
        head = nullptr;
        num = 0;
    }

    //чисто виртуальная функция: пока не определимся с типом списка, не сможем реализовать добавление
    virtual Element<T>* push(T value) = 0;

    //чисто виртуальная функция: пока не определимся с типом списка, не сможем реализовать удаление
    virtual Element<T>* pop() = 0;

    virtual ~LinkedListParent()
    {
        //деструктор - освобождение памяти
        cout << "\nParent destructor";
    }

    //получение элемента по индексу - какова асимптотическая оценка этого действия?
    virtual Element<T>* operator[](int i)
    {
        //индексация
        if (i<0 || i>num) return nullptr;
        int k = 0;

        //ищем i-й элемент - вставем в начало и отсчитываем i шагов вперед
        Element<T>* cur = head;
        for (k = 0; k < i; k++)
        {
            cur = cur->getNext();
        }
        return cur;
    }

    template<class T1>  friend ostream& operator<< (ostream& ustream, LinkedListParent<T1>& obj);
    template<class T1>  friend istream& operator>> (istream& ustream, LinkedListParent<T1>& obj);
};

template<class T1>
ostream& operator << (ostream& ustream, LinkedListParent<T1>& obj)
{
    if (typeid(ustream).name() == typeid(ofstream).name())
    {
        ustream << obj.Number() << "\n";
        for (Element<T1>* current = obj.getBegin(); current != nullptr; current = current->getNext())
            ustream << current->getValue() << " ";
        return ustream;
    }

    ustream << "\nLength: " << obj.Number() << "\n";
    int i = 0;
    for (Element<T1>* current = obj.getBegin(); current != nullptr; current = current->getNext(), i++)
        ustream << "arr[" << i << "] = " << current->getValue() << "\n";

    return ustream;
}

template<class T1>
istream& operator >> (istream& ustream, LinkedListParent<T1>& obj)
{
    //чтение из файла и консоли совпадают
    int len;
    ustream >> len;
    //здесь надо очистить память под obj, установить obj.num = 0
    double v = 0;
    for (int i = 0; i < len; i++)
    {
        ustream >> v;
        obj.push(v);
    }
    return ustream;
}

//дописать класс итератора по списку
template<typename ValueType>
class ListIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:

public:
    //конструкторы
    ListIterator() { ptr = nullptr; }
    ListIterator(Element<ValueType>* p) { ptr = p; }
    ListIterator(const ListIterator& it) { ptr = it.ptr; }

    //методы работы с итераторами
    //присваивание
    ListIterator& operator=(const ListIterator& it) { ptr = it.ptr; return *this; }
    ListIterator& operator=(Element<ValueType>* p) { ptr = p; return *this; }

    //проверка итераторов на равенство
    bool operator!=(ListIterator const& other) const { return ptr != other.ptr; }
    bool operator==(ListIterator const& other) const { return ptr == other.ptr; }
    //получить значение
    Element<ValueType>& operator*()
    {
        return *ptr;
    }
    Element<ValueType>& operator->()
    {
        return this->getValue();
    }

    //перемещение с помощью итераторов
    ListIterator& operator++() //prefix ++p
    {
        (ptr != nullptr && ptr->getNext() != nullptr) ? ptr = ptr->getNext() : ptr = ptr;
        return *this;
    }
    ListIterator& operator++(int v) //postfix p++
    {
        (ptr != nullptr && ptr->getNext() != nullptr) ? ptr = ptr->getNext() : ptr = ptr;
        return *this;
    }
private:
    //текущий элемент
    Element<ValueType>* ptr;
};

//класс итерируемый список - наследник связного списка, родитель для Очереди и Стека
template <class T>
class IteratedLinkedList : public LinkedListParent<T>
{
public:
    IteratedLinkedList() : LinkedListParent<T>() { cout << "\nIteratedLinkedList constructor"; }
    virtual ~IteratedLinkedList() { cout << "\nIteratedLinkedList destructor"; }

    ListIterator<T> iterator;

    ListIterator<T> begin() { ListIterator<T> it = LinkedListParent<T>::head; return it; }
    ListIterator<T> end() { ListIterator<T> it = LinkedListParent<T>::tail; return it; }
};

bool condition(int value)
{
    return value % 2 == 0;
}

template <class T>
class Stack : public IteratedLinkedList<T>
{
public:
    Stack() : IteratedLinkedList<T>() { std::cout << "\nStack constructor"; }
    virtual ~Stack(){ std::cout << "\nStack distructor";}

    virtual Element<T>* push(T value) override
    {
        if(LinkedListParent<T>::num != 0)
        {
            Element<T>* newElem = new Element<T>(value);
            LinkedListParent<T>::tail->setNext(newElem);
            newElem->setPrevious(LinkedListParent<T>::tail);
            LinkedListParent<T>::tail = LinkedListParent<T>::tail->getNext();
        }
        else
        {
            LinkedListParent<T>::tail = new Element<T>(value);
            LinkedListParent<T>::head = LinkedListParent<T>::tail;
        }
        LinkedListParent<T>::num++;
        return LinkedListParent<T>::tail;
    }

    virtual Element<T>* pop() override
    {
        //TODO
        return nullptr;
    }

    Stack<T> filter(bool (*func_ptr)(T))
    {
        Stack<T> result;
        ListIterator<T> it = IteratedLinkedList<T>::begin();
        while(it != IteratedLinkedList<T>::end())
        {
            if(func_ptr((*it).getValue())) result.push((*it).getValue());
            it++;
        }
        return result;
    }
};

int main()
{
    Stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    cout << S;
    cout << "\n";
    //Element* e1 = S.pop();
    //cout << "\nElement = " << e1->getValue();
    cout << S;
    cout << "\nIndex in the Stack class: " << S[1]->getValue();

    cout << S;
    cout << "\nIterators:\n";
    S.iterator = S.begin();
    while (S.iterator != S.end())
    {
        cout << *S.iterator << " ";
        S.iterator++;
    }
    cout << *S.iterator << " ";

    Stack<int> S1 = S.filter(condition);
    cout << "\nFilter : " << S1;

    return 0;
}
