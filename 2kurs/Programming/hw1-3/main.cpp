/* Аркадсков А.Е. КТСО-02-20 */

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
    Element(T value){ field = value; };

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
        head = NULL;
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
        if (i<0 || i>num) return NULL;
        int k = 0;

        //ищем i-й элемент - вставем в начало и отсчитываем i шагов вперед
        Element<T>* cur = head;
        for (k = 0; k < i; k++)
        {
            cur = cur->getNext();
        }
        return cur;
    }

    template<class T1> friend ostream& operator<< (ostream& ustream, LinkedListParent<T1>& obj);
    template<class T1> friend istream& operator>> (istream& ustream, LinkedListParent<T1>& obj);
};

template<class T>
ostream& operator << (ostream& ustream, LinkedListParent<T>& obj)
{
    if (typeid(ustream).name() == typeid(ofstream).name())
    {
        ustream << obj.num << "\n";
        for (Element<T>* current = obj.getBegin(); current != NULL; current = current->getNext())
            ustream << current->getValue() << " ";
        return ustream;
    }

    ustream << "\nLength: " << obj.num << "\n";
    int i = 0;
    for (Element<T>* current = obj.getBegin(); current != NULL; current = current->getNext(), i++)
        ustream << "arr[" << i << "] = " << current->getValue() << "\n";

    return ustream;
}

template<class T>
istream& operator >> (istream& ustream, LinkedListParent<T>& obj)
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
    ListIterator() { ptr = NULL; }
    ListIterator(Element<ValueType>* p) { ptr = p; }
    ListIterator(const ListIterator& it) { ptr = it.ptr; }

    //методы работы с итераторами
    //присваивание
    ListIterator& operator=(const ListIterator& it) { ptr = it.ptr; return *this; }
    ListIterator& operator=(Element<ValueType>* p) { ptr = p; return *this; }

    //проверка итераторов на равенство
    bool operator!=(ListIterator const& other) const {  }
    bool operator==(ListIterator const& other) const {  }
    //получить значение
    Element<ValueType>& operator*()
    {
        return *ptr;
    }
    //перемещение с помощью итераторов
    ListIterator& operator++() {  return *this; }
    ListIterator& operator++(int v) { return *this; }
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

/* Начало ДЗ */
template<class T>
class Stack : public IteratedLinkedList<T>
{
public:
    Stack() : IteratedLinkedList<T>(){ std::cout << "\nStack constructor"; }
    ~Stack(){ std::cout << "\nStack distructor"; }

    Element<T>* push(T value) override
    {
        if(IteratedLinkedList<T>::num != 0)
        {
            Element<T>* newElement = new Element<T>(value);
            LinkedListParent<T>::tail->setNext(newElement);
            newElement->setPrevious(LinkedListParent<T>::tail);
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

    Element<T>* pop() override
    {
        Element<T>* ptr = LinkedListParent<T>::tail->getPrevious();
        delete LinkedListParent<T>::tail;
        LinkedListParent<T>::tail = ptr;

        return LinkedListParent<T>::tail;
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
    Element<int>* e1 = S.pop();
    cout << "\nElement = " << e1->getValue();
    cout << S;
    cout<<"\nIndex in the Stack class: " << S[1]->getValue();

    cout << S;
    cout << "\nIterators:\n";
    S.iterator = S.begin();
    while (S.iterator != S.end())
    {
        cout << *S.iterator << " ";
        S.iterator++;
    }
    cout << *S.iterator << " ";

    return 0;
}
