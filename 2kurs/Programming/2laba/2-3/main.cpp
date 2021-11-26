#include <iostream>
#include <cmath>
#include <exception>
#include <stack>
#include "Series.h"

using namespace std;
//узел
template<class T>
class Node
{
protected:
    //закрытые переменные Node N; N.data = 10 вызовет ошибку
    T data;

    //не можем хранить Node, но имеем право хранить указатель
    Node* left;
    Node* right;
    Node* parent;

    //переменная, необходимая для поддержания баланса дерева
    int height;
public:
    //доступные извне переменные и функции
    virtual void setData(T d) { data = d; }
    virtual T getData() { return data; }
    int getHeight() { return height; }

    virtual Node* getLeft() { return left; }
    virtual Node* getRight() { return right; }
    virtual Node* getParent() { return parent; }

    virtual void setLeft(Node* N) { left = N; }
    virtual void setRight(Node* N) { right = N; }
    virtual void setParent(Node* N) { parent = N; }

    //Конструктор. Устанавливаем стартовые значения для указателей
    Node<T>(T n)
    {
        data = n;
        left = right = parent = nullptr;
        height = 1;
    }

    Node<T>()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        data = 0;
        height = 1;
    }


    virtual void print()
    {
        cout << "\n" << data;
    }

    virtual void setHeight(int h)
    {
        height = h;
    }

    template<class T1> friend ostream& operator<< (ostream& stream, Node<T1>& N);
};

template<class T>
ostream& operator<< (ostream& stream, Node<T>& N)
{
    stream << "\nNode data: " << N.data << ", height: " << N.height;
    return stream;
}
template<class T>
void print(Node<T>* N) { cout << "\n" << N->getData(); }

template<class T>
class Tree
{
protected:
    //корень - его достаточно для хранения всего дерева
    Node<T>* root;
public:
    //доступ к корневому элементу
    virtual Node<T>* getRoot() { return root; }

    //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
    Tree<T>() { root = nullptr; }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual Node<T>* Add_R(Node<T>* N)
    {
        return Add_R(N, root);
    }

    virtual Node<T>* Add_R(Node<T>* New, Node<T>* Current)
    {
        if (New == nullptr) return nullptr;
        if (root == nullptr)
        {
            root = New;
            return New;
        }

        if (Current->getData() > New->getData())
        {
            //идем влево
            if (Current->getLeft() != nullptr)
                Current->setLeft(Add_R(New, Current->getLeft()));
            else
                Current->setLeft(New);
            Current->getLeft()->setParent(Current);
        }
        if (Current->getData() < New->getData())
        {
            //идем вправо
            if (Current->getRight() != nullptr)
                Current->setRight(Add_R(New, Current->getRight()));
            else
                Current->setRight(New);
            Current->getRight()->setParent(Current);
        }
        if (Current->getData() == New->getData())
            //нашли совпадение
            ;
        //для несбалансированного дерева поиска
        return Current;
    }

    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
    virtual Node<T>* Add(T n)
    {
        Node<T>* N = new Node<T>(n);
        return Add_R(N);
    }

    //удаление узла
    virtual void Remove(Node<T>* N)
    { }

    virtual Node<T>* Min(Node<T>* Current=nullptr)
    {
        //минимум - это самый "левый" узел. Идём по дереву всегда влево
        if (root == nullptr) return nullptr;

        if(Current==nullptr)
            Current = root;
        while (Current->getLeft() != nullptr)
            Current = Current->getLeft();

        return Current;
    }

    virtual Node<T>* Max(Node<T>* Current = nullptr)
    {
        //максимум - это самый "правый" узел. Идём по дереву всегда вправо
        if (root == nullptr) return nullptr;

        if (Current == nullptr)
            Current = root;
        while (Current->getRight() != nullptr)
            Current = Current->getRight();

        return Current;
    }


    //поиск узла в дереве
    virtual Node<T>* Find(T data)
    {
        if (root == nullptr) return nullptr;
        return Find_R(data, root);
    }

    virtual Node<T>* Find_Left()
    {
        Node<T>* ptr = root;
        while(ptr->getLeft() != nullptr){ ptr = ptr->getLeft(); }
        return ptr;
    }

    //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
    virtual Node<T>* Find_R(T data, Node<T>* Current)
    {
        //база рекурсии
        if (Current == nullptr) return nullptr;

        if (Current->getData() == data) return Current;

        //рекурсивный вызов
        if (Current->getData() > data) return Find_R(data, Current->getLeft());

        if (Current->getData() < data) return Find_R(data, Current->getRight());


    }

    //три обхода дерева
    virtual void PreOrder(Node<T>* N, void (*f)(Node<T>*))
    {
        if (N != nullptr)
            f(N);
        if (N != nullptr && N->getLeft() != nullptr)
            PreOrder(N->getLeft(), f);
        if (N != nullptr && N->getRight() != nullptr)
            PreOrder(N->getRight(), f);
    }

    //InOrder-обход даст отсортированную последовательность
    virtual void InOrder(Node<T>* N, void (*f)(Node<T>*))
    {
        if (N != nullptr && N->getLeft() != nullptr)
            InOrder(N->getLeft(), f);
        if (N != nullptr)
            f(N);
        if (N != nullptr && N->getRight() != nullptr)
            InOrder(N->getRight(), f);
    }

    virtual void PostOrder(Node<T>* N, void (*f)(Node<T>*))
    {
        if (N != nullptr && N->getLeft() != nullptr)
            PostOrder(N->getLeft(), f);
        if (N != nullptr && N->getRight() != nullptr)
            PostOrder(N->getRight(), f);
        if (N != nullptr)
            f(N);
    }
};

template<typename ValueType>
class TreeIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:
    Node<ValueType>* ptr;
    Tree<ValueType>* T;

public:
    TreeIterator() { ptr = nullptr; T = nullptr; }
//    ListIterator(ValueType* p) { ptr = p; }
    TreeIterator(Node<ValueType>* p) { ptr = p; }
    TreeIterator(const TreeIterator& it) { ptr = it.ptr; }

    bool operator!=(TreeIterator const& other) const { return ptr != other.ptr; }
    bool operator==(TreeIterator const& other) const { return ptr == other.ptr; }
    Node<ValueType>& operator*()
    {
//        if(ptr == nullptr){ std::cerr << "\nNo iterator found."; }
//        else{ return *ptr; }
        return *ptr;
    }

    // Pre
    TreeIterator& operator++()
    {
//        if(ptr->getRight())
//        {
//            ptr = ptr->getRight();
//            while(ptr->getLeft() != nullptr)
//            {
//                ptr = ptr->getLeft();
//            }
//        }
//        else
//        {
//            Node<ValueType>* before;
//            do{
//                before = ptr;
//                ptr = ptr->getParent();
//            }while(ptr != nullptr && before == ptr->getRight());
//        }
//        return *this;

        Node<ValueType>* p;
        if(ptr == nullptr)
        {//ptr = ptr.getleft
            if(ptr == nullptr) while(ptr->getLeft() != nullptr) ptr = ptr->getLeft();
        }
        else if(ptr->getRight() != nullptr){ ptr = ptr->getRight(); while(ptr->getLeft() != nullptr) ptr = ptr->getLeft(); }
        else
        {
            p = ptr->getParent();
            while(p != nullptr && ptr == p->getRight()){ ptr = p; p = p->getParent(); }
            ptr = p;
        }
        return *this;
    }

    // Post
    TreeIterator& operator++(int v)
    {
//        TreeIterator<ValueType> old(*this);
//        ++(*this);
//        return old;
        if(!ptr) return *this;
        else {
            Node<ValueType> *p;
            auto *temp = new TreeIterator<ValueType>(ptr);
            if (ptr == nullptr) { while (ptr->getLeft() != nullptr) ptr = ptr->getLeft(); }
            else if (ptr->getRight() != nullptr) {
                ptr = ptr->getRight();
                while (ptr->getLeft() != nullptr) ptr = ptr->getLeft();
            }
            else {
                p = ptr->getParent();
                while (p != nullptr && ptr == p->getRight()) {
                    ptr = p;
                    p = p->getParent();
                }
                ptr = p;
            }
            return *temp;
        }
    }

    TreeIterator& operator=(const TreeIterator& it) { ptr = it.ptr; return *this; }
    TreeIterator& operator=(Node<ValueType>* p) { ptr = p; return *this; }
};

template<class T>
class IteratedTree : public Tree<T>
{
public:
    IteratedTree<T>() : Tree<T>() {}

    TreeIterator<T> iterator;

    TreeIterator<T> begin() { TreeIterator<T> it = TreeIterator<T>(Tree<T>::Min()); return it; }
    TreeIterator<T> end() { TreeIterator<T> it = TreeIterator<T>(Tree<T>::Max()); return it; }
};

//AVL_Tree - потомок класса Tree
template<class T>
class AVL_Tree : public IteratedTree<T>
{
protected:
    //определение разности высот двух поддеревьев
    int bfactor(Node<T>* p)
    {
        int hl = 0;
        int hr = 0;
        if (p->getLeft() != nullptr)
            hl = p->getLeft()->getHeight();
        if (p->getRight() != nullptr)
            hr = p->getRight()->getHeight();
        return (hr - hl);
    }

    //при добавлении узлов в них нет информации о балансе, т.к. не ясно, куда в дереве они попадут
    //после добавления узла рассчитываем его высоту (расстояние до корня) и редактируем высоты в узлах, где это
    //значение могло поменяться
    void fixHeight(Node<T>* p)
    {
        int hl = 0;
        int hr = 0;
        if (p->getLeft() != nullptr)
            hl = p->getLeft()->getHeight();
        if (p->getRight() != nullptr)
            hr = p->getRight()->getHeight();
        p->setHeight((hl > hr ? hl : hr) + 1);
    }

    //краеугольные камни АВЛ-деревьев - процедуры поворотов
    Node<T>* RotateRight(Node<T>* p) // правый поворот вокруг p
    {
        Node<T>* q = p->getLeft();
        p->setLeft(q->getRight());
        q->setRight(p);
        if (p == Tree<T>::root)
            Tree<T>::root = q;

        q->setParent(p->getParent());
        p->setParent(q);
        if (p->getLeft()!=nullptr) p->getLeft()->setParent(p);

        fixHeight(p);
        fixHeight(q);
        return q;
    }

    Node<T>* RotateLeft(Node<T>* q) // левый поворот вокруг q
    {
        Node<T>* p = q->getRight();
        q->setRight(p->getLeft());
        p->setLeft(q);
        if (q == Tree<T>::root)
            Tree<T>::root = p;

        p->setParent(q->getParent());
        q->setParent(p);
        if(q->getRight()!=nullptr) q->getRight()->setParent(q);

        fixHeight(q);
        fixHeight(p);
        return p;
    }

    //балансировка поддерева узла p - вызов нужных поворотов в зависимости от показателя баланса
    Node<T>* Balance(Node<T>* p) // балансировка узла p
    {
        fixHeight(p);
        if (bfactor(p) == 2)
        {
            if (bfactor(p->getRight()) < 0)
            {
                p->setRight(RotateRight(p->getRight()));
                p->getRight()->setParent(p);
            }
            return RotateLeft(p);
        }
        if (bfactor(p) == -2)
        {
            if (bfactor(p->getLeft()) > 0)
            {
                p->setLeft(RotateLeft(p->getLeft()));
                p->getLeft()->setParent(p);
            }
            return RotateRight(p);
        }

        return p; // балансировка не нужна
    }

public:
    //конструктор AVL_Tree вызывает конструктор базового класса Tree
    AVL_Tree<T>() : IteratedTree<T>() {}

    virtual Node<T>* Add_R(Node<T>* N)
    {
        return Add_R(N, Tree<T>::root);
    }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual Node<T>* Add_R(Node<T>* N, Node<T>* Current)
    {
        //вызываем функцию Add_R из базового класса
        Node<T>* AddedNode = Tree<T>::Add_R(N, Current);
        //применяем к добавленному узлу балансировку
        return Balance(AddedNode);
    }

    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
    virtual Node<T>* Add(T n)
    {
        Node<T>* N = new Node<T>(n);
        return Add_R(N);
    }

    //удаление узла
    virtual void Remove(Node<T>* N)
    { }
};



int main()
{
    AVL_Tree<int> T;
    int arr[15];
    int i = 0;
    for (i = 0; i < 15; i++) arr[i] = (int)(100 * cos(15 * double(i+1)));
    for (i = 0; i < 15; i++)
        T.Add(arr[i]);

    Node<int>* M = T.Min();
    cout << "\nMin = " << M->getData() << "\tFind " << arr[3] << ": " << T.Find_R(arr[3], T.getRoot());

//    void (*f_ptr)(Node<double>*); f_ptr = print;
    /*cout << "\n-----\nPreorder:";
    T.PreOrder(T.getRoot(), f_ptr);*/
//    cout << "\n-----\nInorder:";
//    T.InOrder(T.getRoot(), f_ptr);
    /*cout << "\n-----\nPostorder:";
    T.PostOrder(T.getRoot(), f_ptr);*/

    cout << "\nIterators:\n";
    T.iterator = T.getRoot();
    while (T.iterator != T.end())
    {
        cout << *T.iterator << " ";
        T.iterator++;
    }
//    cout << *T.iterator << " ";

    return 0;
}
