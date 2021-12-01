#include <iostream>
#include <exception>
#include "Series.h"

//узел
template<class K, class V>
class Node
{
protected:
    V data;
    K key;

    //не можем хранить Node, но имеем право хранить указатель
    Node* left;
    Node* right;
    Node* parent;

    //переменная, необходимая для поддержания баланса дерева
    int height;
public:
    //доступные извне переменные и функции
    virtual void setData(V d) { data = d; }
    virtual void setKey(K k){ key = k; }
    virtual V getData() { return data; }
    virtual K getKey() { return key; }
    int getHeight() { return height; }

    virtual Node* getLeft() { return left; }
    virtual Node* getRight() { return right; }
    virtual Node* getParent() { return parent; }

    virtual void setLeft(Node* N) { left = N; }
    virtual void setRight(Node* N) { right = N; }
    virtual void setParent(Node* N) { parent = N; }

    //Конструктор. Устанавливаем стартовые значения для указателей
    Node<K, V>(K k, V n)
    {
        data = n;
        key = k;
        left = right = parent = nullptr;
        height = 1;
    }

    Node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        data = 0;
        height = 1;
    }


    virtual void print()
    {
        std::cout << "\n" << data;
    }

    virtual void setHeight(int h)
    {
        height = h;
    }

    template<class T1, class T2> friend std::ostream& operator<< (std::ostream& stream, Node<T1, T2>& N);
};

template<class T1, class T2>
std::ostream& operator<< (std::ostream& stream, Node<T1, T2>& N)
{
    stream << "\nNode key: " << N.key <<  "\nNode data: " << N.data << ", height: " << N.height;
    return stream;
}
template<class T1, class T2>
void print(Node<T1, T2>* N)
{
    Series tmp = N->getData();
    std::cout << "\n"<< "Key: " << N->getKey() << "\tData :" << tmp;
}

template<class K, class V>
class Tree
{
protected:
    //корень - его достаточно для хранения всего дерева
    Node<K, V>* root;
public:
    //доступ к корневому элементу
    virtual Node<K, V>* getRoot() { return root; }

    //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
    Tree<K, V>() { root = nullptr; }
    /* Destructor */
    ~Tree<K, V>()
    {
        std::cout << "\nTree destructor invoked.";
        if(root == nullptr) return;
        clearNode(root);
        delete root;
        std::cout << "\nTree destructor done.";
    }
    virtual void clearNode(Node<K,V>* node)
    {
        if(node->getLeft())
        {
            clearNode(node->getLeft());
            delete(node->getLeft());
        }
        if(node->getRight())
        {
            clearNode(node->getRight());
            delete(node->getLeft());
        }
    }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual Node<K, V>* Add_R(Node<K, V>* N)
    {
        return Add_R(N, root);
    }

    virtual Node<K, V>* Add_R(Node<K, V>* New, Node<K, V>* Current)
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
    virtual Node<K, V>* Add(K k, V n)
    {
        Node<K, V>* N = new Node<K, V>(k, n);
        return Add_R(N);
    }

    //удаление узла
//    virtual void Remove(Node<T>* N)
//    {
//        //TODO
//    }

    virtual Node<K, V>* Min(Node<K, V>* Current=nullptr)
    {
        //минимум - это самый "левый" узел. Идём по дереву всегда влево
        if (root == nullptr) return nullptr;

        if(Current==nullptr)
            Current = root;
        while (Current->getLeft() != nullptr)
            Current = Current->getLeft();

        return Current;
    }

    virtual Node<K, V>* Max(Node<K, V>* Current = nullptr)
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
    virtual Node<K, V>* Find(V data)
    {
        if (root == nullptr) return nullptr;
        return Find_R(data, root);
    }

    virtual Node<K, V>* Find_Left()
    {
        Node<K, V>* ptr = root;
        while(ptr->getLeft() != nullptr){ ptr = ptr->getLeft(); }
        return ptr;
    }

    //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
    virtual Node<K, V>* Find_R(V data, Node<K, V>* Current)
    {
        //база рекурсии
        if (Current == nullptr) return nullptr;

        if (Current->getData() == data) return Current;

        //рекурсивный вызов
        if (Current->getData() > data) return Find_R(data, Current->getLeft());

        if (Current->getData() < data) return Find_R(data, Current->getRight());

    }

    //три обхода дерева
    virtual void PreOrder(Node<K, V>* N, void (*f)(Node<K, V>*))
    {
        if (N != nullptr)
            f(N);
        if (N != nullptr && N->getLeft() != nullptr)
            PreOrder(N->getLeft(), f);
        if (N != nullptr && N->getRight() != nullptr)
            PreOrder(N->getRight(), f);
    }

    //InOrder-обход даст отсортированную последовательность
    virtual void InOrder(Node<K, V>* N, void (*f)(Node<K, V>*))
    {
        if (N != nullptr && N->getLeft() != nullptr)
            InOrder(N->getLeft(), f);
        if (N != nullptr)
            f(N);
        if (N != nullptr && N->getRight() != nullptr)
            InOrder(N->getRight(), f);
    }

    virtual void PostOrder(Node<K, V>* N, void (*f)(Node<K, V>*))
    {
        if (N != nullptr && N->getLeft() != nullptr)
            PostOrder(N->getLeft(), f);
        if (N != nullptr && N->getRight() != nullptr)
            PostOrder(N->getRight(), f);
        if (N != nullptr)
            f(N);
    }
};

template<class K, typename ValueType>
class TreeIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:
    Node<K, ValueType>* ptr;
    Tree<K, ValueType>* T;

public:
    TreeIterator() { ptr = nullptr; T = nullptr; }
    TreeIterator(Node<K, ValueType>* p) { ptr = p; }
    TreeIterator(const TreeIterator& it) { ptr = it.ptr; }

    bool operator!=(TreeIterator const& other) const { return ptr != other.ptr; }
    bool operator==(TreeIterator const& other) const { return ptr == other.ptr; }
    Node<K, ValueType>& operator*()
    {
        if(ptr == nullptr){ std::cerr << "\nNo iterator found."; }
        else{ return *ptr; }
    }

    // Pre
    TreeIterator& operator++()
    {
        if(ptr->getRight())
        {
            ptr = ptr->getRight();
            while(ptr->getLeft() != nullptr)
            {
                ptr = ptr->getLeft();
            }
        }
        else
        {
            Node<K, ValueType>* before;
            do{
                before = ptr;
                ptr = ptr->getParent();
            }while(ptr != nullptr && before == ptr->getRight());
        }
        return *this;
    }

    // Post
    TreeIterator& operator++(int v)
    {
        TreeIterator<K, ValueType> old(*this);
        ++(*this);
        return old;
    }

    ValueType getData(){ return ptr->getData(); }
    K getKey(){ return ptr->getKey(); }

    TreeIterator& operator=(const TreeIterator& it) { ptr = it.ptr; return *this; }
    TreeIterator& operator=(Node<K, ValueType>* p) { ptr = p; return *this; }
};

template<class K, class V>
class IteratedTree : public Tree<K, V>
{
public:
    IteratedTree<K, V>() : Tree<K, V>() {}

    TreeIterator<K, V> iterator;

    TreeIterator<K, V> begin() { TreeIterator<K, V> it = TreeIterator<K, V>(Tree<K, V>::Min()); return it; }
    TreeIterator<K, V> end() { TreeIterator<K, V> it = TreeIterator<K, V>(Tree<K, V>::Max()); return it; }
};

//AVL_Tree - потомок класса Tree
template<class K, class V>
class AVL_Tree : public IteratedTree<K, V>
{
protected:
    //определение разности высот двух поддеревьев
    int bfactor(Node<K, V>* p)
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
    void fixHeight(Node<K, V>* p)
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
    Node<K, V>* RotateRight(Node<K, V>* p) // правый поворот вокруг p
    {
        Node<K, V>* q = p->getLeft();
        p->setLeft(q->getRight());
        q->setRight(p);
        if (p == Tree<K, V>::root)
            Tree<K, V>::root = q;

        q->setParent(p->getParent());
        p->setParent(q);
        if (p->getLeft()!=nullptr) p->getLeft()->setParent(p);

        fixHeight(p);
        fixHeight(q);
        return q;
    }

    Node<K, V>* RotateLeft(Node<K, V>* q) // левый поворот вокруг q
    {
        Node<K, V>* p = q->getRight();
        q->setRight(p->getLeft());
        p->setLeft(q);
        if (q == Tree<K, V>::root)
            Tree<K, V>::root = p;

        p->setParent(q->getParent());
        q->setParent(p);
        if(q->getRight()!=nullptr) q->getRight()->setParent(q);

        fixHeight(q);
        fixHeight(p);
        return p;
    }

    //балансировка поддерева узла p - вызов нужных поворотов в зависимости от показателя баланса
    Node<K, V>* Balance(Node<K, V>* p) // балансировка узла p
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
    AVL_Tree<K, V>() : IteratedTree<K, V>() {}

    virtual Node<K, V>* Add_R(Node<K, V>* N)
    {
        return Add_R(N, Tree<K, V>::root);
    }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual Node<K, V>* Add_R(Node<K, V>* N, Node<K, V>* Current)
    {
        //вызываем функцию Add_R из базового класса
        Node<K, V>* AddedNode = Tree<K, V>::Add_R(N, Current);
        //применяем к добавленному узлу балансировку
        return Balance(AddedNode);
    }

    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
    virtual Node<K, V>* Add(K k, V n)
    {
        Node<K, V>* N = new Node<K, V>(k, n);
        return Add_R(N);
    }

    //удаление узла
    virtual void Remove(Node<K, V>* N)
    { }
};

//Search by key function
template<class K, class V>
V searchByKey(AVL_Tree<K, V> tree, K k)
{
    for(TreeIterator it = tree.Find_Left(); it != tree.end(); it++)
    {
        if(it.getKey() == k)
        {
            V data = it.getData();
            std::cout << "\nKey " << k << " found.\tValue by key: " << data << "\n";
            return it.getData();
        }
    }
    throw std::runtime_error("\nError! No key found!");
}


//Search by value function
template<class K, class V>
K searchByValue(AVL_Tree<K,V> tree, V value)
{
    for(TreeIterator it = tree.Find_Left(); it != tree.end(); it++)
    {
        if(it.getData() == value)
        {
            std::cout << "\nValue " << value << " found.\tKey by value: " << it.getKey() << "\n";
            return it.getKey();
        }
    }
    throw std::runtime_error("\nError! No value found!");
}

int main()
{
    Series MrR("Mister Robot", "Sam Esmail", "USA", 4, 88, 92, 24062015);
    Series GoT("Game Of Thrones", "David Benioff", "USA", 8, 100, 92, 17042011);
    Series TwD("The Walking Dead", "Jolly Dale", "USA", 10, 84, 94, 31102010);
    Series Fb("Family Business", "Carl Weber", "France", 2, 73, 89, 28062019);

    AVL_Tree<std::string, Series> T;
    T.Add("MrR", MrR); T.Add("GoT", GoT); T.Add("TwD", TwD); T.Add("FB", Fb);

    Node<std::string, Series>* M = T.Min();
    std::cout << "\nMin = " << M->getData().getTitle();
    std::cout << "\tFind " << TwD.getTitle() << ": " << T.Find_R(TwD, T.getRoot());

    void (*f_ptr)(Node<std::string, Series>*); f_ptr = print;
    std::cout << "\n-----\nPreorder:";
    T.PreOrder(T.getRoot(), f_ptr);
    std::cout << "\n-----\nInorder:";
    T.InOrder(T.getRoot(), f_ptr);
    std::cout << "\n-----\nPostorder:";
    T.PostOrder(T.getRoot(), f_ptr);

    try
    {
        std::cout << "\n-----\nSearch by key: ";
        searchByKey(T, std::string("MrR"));
        searchByKey(T, std::string("Random string"));
    } catch(const std::runtime_error& e){ std::cout << e.what(); };

    try
    {
        std::cout << "\n-----\nSearch by value: ";
        searchByValue(T, Fb);
        searchByValue(T, Series());
    } catch(const std::runtime_error& e){ std::cout << e.what(); };

    std::cout << "\n-----\nIterators:";
    T.iterator = T.Find_Left();
    while (T.iterator != T.end())
    {
        std::cout << *T.iterator << " ";
        T.iterator++;
    }

    return 0;
}
