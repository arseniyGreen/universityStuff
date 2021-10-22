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

    Element operator*(){ return field; }

    bool operator < (const Element<T>& other) const { return field < other.field; }
    bool operator > (const Element<T>& other) const { return field > other.field; }

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
        for (Element<T>* current = obj.getBegin(); current != nullptr; current = current->getNext())
            ustream << current->getValue() << " ";
        return ustream;
    }

    ustream << "\nLength: " << obj.num << "\n";
    int i = 0;
    Element<T>* current = obj.getBegin();
    for (Element<T>* current = obj.getBegin(); current != nullptr; current = current->getNext(), i++)
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
public:
    //конструкторы
    ListIterator() { ptr = nullptr; }
    ListIterator(Element<ValueType>* p) { ptr = p; }
    ListIterator(const ListIterator& it) { ptr = it.ptr; }

    ValueType getValue() const
    {
        return ptr->getValue();
    }

    //методы работы с итераторами
    //присваивание
    ListIterator& operator=(const ListIterator& it) { ptr = it.ptr; return *this; }
    ListIterator& operator=(Element<ValueType>* p) { ptr = p; return *this; }

    //проверка итераторов на равенство
    bool operator!=(ListIterator const& other) const { return ptr->getValue() != other.ptr->getValue(); }
    bool operator==(ListIterator const& other) const { return ptr->getValue() == other.ptr->getValue(); }

    //получить значение
    Element<ValueType>& operator*()
    {
        return *ptr;
    }

    Element<ValueType>& getNext() const
    {
        return *ptr->getNext();
    };
    Element<ValueType>& getPrevious() const
    {
        return *ptr->getPrevious();
    }

    //перемещение с помощью итераторов
    ListIterator& operator++()
    {
        if(ptr->getNext() != nullptr || ptr != nullptr){ ptr = ptr->getNext(); }
        else return *this;
    }
    ListIterator& operator++(int v)
    {
        if(ptr->getNext() != nullptr || ptr != nullptr){ ptr = ptr->getNext(); }
        else return *this;
    }

    ListIterator& operator--()
    {
        if(ptr->getPrevious() != nullptr || ptr != nullptr) { ptr = ptr->getPrevious(); }
        else return *this;
    }
    ListIterator& operator--(int v)
    {
        if(ptr->getPrevious() != nullptr || ptr != nullptr) { ptr = ptr->getPrevious(); }
        else return *this;
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

    ListIterator<T> begin() { ListIterator<T> it = LinkedListParent<T>::head; return it; }
    ListIterator<T> end() { ListIterator<T> it = LinkedListParent<T>::tail; return it; }

    template<class T1> friend ostream& operator << (ostream& stream, IteratedLinkedList<T1>& lst);
};

template<class T1>
ostream &operator<<(ostream &stream, IteratedLinkedList<T1> &lst) {
    lst.iterator = lst.begin();
    while(lst.iterator != lst.end())
    {
        stream << *lst.iterator << " ";
        lst.iterator++;
    }
    return stream;
}

/* Начало ДЗ */
template<class T>
class Stack : public IteratedLinkedList<T>
{
public:
    Stack() : IteratedLinkedList<T>(){ std::cout << "\nStack constructor"; }
    ~Stack(){ std::cout << "\nStack destructor"; }

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
        Element<T>* ptr = LinkedListParent<T>::tail;
        LinkedListParent<T>::tail = LinkedListParent<T>::tail->getPrevious();
        LinkedListParent<T>::tail->setNext(nullptr);
        LinkedListParent<T>::num--;

        return ptr;
    }

    template<class T1> friend std::ostream& operator << (std::ostream& stream, Stack<T1>& S);
};

template<class T1>
std::ostream& operator << (std::ostream& stream, Stack<T1>& S){

    ListIterator<T1> it = S.begin();

    while(it != S.end())
    {
        stream << *it << " ";
        *it++;
    }
    stream << *it;
    return stream;
}

/* Keeps ordered */
template<class T>
class DInheritence : public Stack<T>
{
public:
    Element<T>* push(T value) override
    {
        Element<T>* toPush = new Element(value);

        if(LinkedListParent<T>::num == 0)
        {
            LinkedListParent<T>::head = LinkedListParent<T>::tail = toPush;
            LinkedListParent<T>::num++;
        }
        else if(LinkedListParent<T>::num == 1)
        {
            if(toPush > IteratedLinkedList<T>::head)
            {
                IteratedLinkedList<T>::head->setNext(toPush);
            }
            else
            {
                toPush->setNext(IteratedLinkedList<T>::head);
                IteratedLinkedList<T>::head = toPush; //???
            }
            LinkedListParent<T>::num++;
        }
        else
        {
            if(toPush < IteratedLinkedList<T>::getBegin()){ toPush->setNext(IteratedLinkedList<T>::head); return IteratedLinkedList<T>::tail; }
            ListIterator<T> it = IteratedLinkedList<T>::head->getNext();
            while(it != IteratedLinkedList<T>::tail)
            {
                if(it.getPrevious() < *it && it.getNext() > *it)
                {
                    it.getPrevious().setNext(toPush);
                    it.getNext().setPrevious(toPush);
                }
                *it++;
            }
            LinkedListParent<T>::num++;
        }

        return IteratedLinkedList<T>::tail;
    }
};

template<class T>
void filter(Stack<T>& stack, Stack<T>& newStack, bool (*predicate)(T))
{
    ListIterator it = stack.begin();
    while(it != stack.end())
    {
        if(predicate(it.getVal())){ newStack.push(*it); }
        *it++;
    }
    std::cout << "Filtering done!\n";
}

int main()
{
    Stack<int> S;
    S.push(11);
    S.push(-35);
    S.push(332);
    S.push(-10);
    S.push(62);
    S.push(-41);
    cout << "\n" << S;
    cout << "\n";
    Element<int>* e1 = S.pop();
    cout << "\nElement = " << e1->getValue() << "\n";
    cout << S;
    cout<<"\nIndex in the Stack class: " << S[1]->getValue() << "\n";
    cout << S;

    cout << "\nIterators:\n";
    /* "<<" overload for stack based on iterators */
    std::cout << S << "\n";

    std::cout << "D inh test :\n";
    DInheritence<int> S2;
    S2.push(11);
    S2.push(-35);
    S2.push(332);
    S2.push(-10);
    S2.push(62);
    S2.push(-41);
    std::cout << S2 << "\n";

//    Stack<int> filteredStack;

    //filter(S, filteredStack, isPositive);
    //std::cout << filteredStack;

    return 0;
}
