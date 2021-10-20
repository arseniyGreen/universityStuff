#include <iostream>

template <class T>
class Node
{
private:
    T value;
public:
    //установить данные в узле
    T getValue() { return value; }
    void setValue(T v) { value = v; }

    //сравнение узлов
    int operator<(Node N)
    {
        return (value < N.getValue());
    }

    int operator>(Node N)
    {
        return (value > N.getValue());
    }

    //вывод содержимого одного узла
    void print()
    {
        std::cout << value;
    }
};

template <class T>
void print(Node<T>* N)
{
    std::cout << N->getValue() << "\n";
}

//куча (heap)
template <class T>
class Heap
{
private:
    //массив
    Node<T>* arr;
    //сколько элементов добавлено
    int len;
    //сколько памяти выделено
    int size;
public:

    //доступ к вспомогательным полям кучи и оператор индекса
    int getCapacity() { return size; }
    int getCount() { return len; }

    Node<T>& operator[](int index)
    {
        if (index < 0 || index >= len)
            ;//?

        return arr[index];
    }

    //конструктор
    Heap<T> (int MemorySize = 100)
    {
        arr = new Node<T>[MemorySize];
        len = 0;
        size = MemorySize;
    }

    //поменять местами элементы arr[index1], arr[index2]
    void Swap(int index1, int index2)
    {
        if (index1 <= 0 || index1 >= len)
            ;
        if (index2 <= 0 || index2 >= len)
            ;
        //здесь нужна защита от дурака

        Node<T> temp;
        temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    //скопировать данные между двумя узлами
    void Copy(Node<T>* dest, Node<T>* source)
    {
        dest->setValue(source->getValue());
    }

    //функции получения левого, правого дочернего элемента, родителя или их индексов в массиве
    Node<T>* GetLeftChild(int index)
    {
        if (index < 0 || index * 2 >= len)
            ;
        //здесь нужна защита от дурака
        return &arr[index * 2 + 1];
    }

    Node<T>* GetRightChild(int index)
    {
        if (index < 0 || index * 2 >= len)
            ;
        //здесь нужна защита от дурака

        return &arr[index * 2 + 2];
    }

    Node<T>* GetParent(int index)
    {
        if (index <= 0 || index >= len)
            ;
        //здесь нужна защита от дурака

        if (index % 2 == 0)
            return &arr[index / 2 - 1];
        return &arr[index / 2];
    }

    int GetLeftChildIndex(int index)
    {
        if (index < 0 || index * 2 >= len)
            ;
        //здесь нужна защита от дурака
        return index * 2 + 1;
    }

    int GetRightChildIndex(int index)
    {
        if (index < 0 || index * 2 >= len)
            ;
        //здесь нужна защита от дурака

        return index * 2 + 2;
    }

    int GetParentIndex(int index)
    {
        if (index <= 0 || index >= len)
            ;
        //здесь нужна защита от дурака

        if (index % 2 == 0)
            return index / 2 - 1;
        return index / 2;
    }

    //восстановление свойств кучи после удаления или добавления элемента
    void Heapify(int index = -1)
    {
        //то же, что и SiftDown
        int leftChild;
        int rightChild;
        int largestChild;
        if (index == -1) index = len - 1;

        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;

        //нужно сравнить элементы и при необходимости произвести просеивание вниз


    }

    //просеить элемент вверх
    void SiftUp(int index = -1)
    {
        if(index == -1) index = len - 1;
        if(index <= 0) return;
//        int parent = GetParentIndex(index);
//        int index2 = GetLeftChildIndex(parent);
//        if (index2 == index) index2 = GetRightChildIndex(parent);

        //нужно сравнить элементы и при необходимости произвести просеивание вверх
        int parent_index = GetParentIndex(index);
        if(arr[index] > arr[parent_index])
        {
            Swap(index, parent_index);
            SiftUp(parent_index);
        }
    }

    //удобный интерфейс для пользователя
    template <class T1>
    void push(T1 v)
    {
        Node<T1>* N = new Node<T1>;
        N->setValue(v);
        push(N);
    }

    //добавление элемента - вставляем его в конец массива и просеиваем вверх
    template <class T1>
    void push(Node<T1>* N)
    {
        if (len < size)
        {
            Copy(&arr[len], N);
            len++;
            SiftUp();
        }
        else return;
    }

    Node<T>* ExtractMax()
    {
        //исключить максимум и запустить просеивание кучи

    }

    //перечислить элементы кучи и применить к ним функцию
    void Straight(void(*f)(Node<T>*))
    {
        int i;
        for (i = 0; i < len; i++)
        {
            f(&arr[i]);
        }
    }

    //перебор элементов, аналогичный проходам бинарного дерева
    void PreOrder(void(*f)(Node<T>*), int index = 0)
    {
        if (index >= 0 && index < len)
            f(&arr[index]);
        if (GetLeftChildIndex(index) < len)
            PreOrder(f, GetLeftChildIndex(index));
        if (GetRightChildIndex(index) < len)
            PreOrder(f, GetRightChildIndex(index));
    }

    void InOrder(void(*f)(Node<T>*), int index = 0)
    {
        if (GetLeftChildIndex(index) < len)
            PreOrder(f, GetLeftChildIndex(index));
        if (index >= 0 && index < len)
            f(&arr[index]);
        if (GetRightChildIndex(index) < len)
            PreOrder(f, GetRightChildIndex(index));
    }

    void PostOrder(void(*f)(Node<T>*), int index = 0)
    {
        if (GetLeftChildIndex(index) < len)
            PreOrder(f, GetLeftChildIndex(index));
        if (GetRightChildIndex(index) < len)
            PreOrder(f, GetRightChildIndex(index));
        if (index >= 0 && index < len)
            f(&arr[index]);
    }

    void RemoveMax()
    {

    }
};

int main()
{
    Heap<int> Tree;

    Tree.Add(1);
    Tree.Add(-1);
    Tree.Add(-2);
    Tree.Add(2);
    Tree.Add(5);
    Tree.Add(6);
    Tree.Add(-3);
    Tree.Add(-4);
    Tree.Add(4);
    Tree.Add(3);

    std::cout << "\n-----\nStraight:";
    void(*f_ptr)(Node<int>*); f_ptr = print;
    Tree.Straight(f_ptr);
    std::cout << "\n-----\nExtractMax:";
    int i = 0;
    while (i < Tree.getCount())
    {
        Node<int>* N = Tree.ExtractMax();
        N->print();
        delete N;
        std::cout << "\n";
    }

    return 0;
}
