#include <iostream>
#include <cmath>

using namespace std;

template<class T>
class Node
{
protected:
    T data;

    Node* left;
    Node* right;
    Node* parent;

    int height;
public:
    virtual void setData(T d) { data = d; }
    virtual T getData() { return data; }
    int getHeight() { return height; }

    virtual Node* getLeft() { return left; }
    virtual Node* getRight() { return right; }
    virtual Node* getParent() { return parent; }

    virtual void setLeft(Node* N) { left = N; }
    virtual void setRight(Node* N) { right = N; }
    virtual void setParent(Node* N) { parent = N; }

    Node<T>(T n)
    {
        data = n;
        left = right = parent = NULL;
        height = 1;
    }

    Node<T>()
    {
        left = NULL;
        right = NULL;
        parent = NULL;
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
    Node<T>* root;
public:
    virtual Node<T>* getRoot() { return root; }

    Tree<T>() { root = NULL; }

    virtual Node<T>* Add_R(Node<T>* N)
    {
        return Add_R(N, root);
    }

    virtual Node<T>* Add_R(Node<T>* N, Node<T>* Current)
    {
        if (N == NULL) return NULL;
        if (root == NULL)
        {
            root = N;
            return N;
        }

        if (Current->getData() > N->getData())
        {
            if (Current->getLeft() != NULL)
                Current->setLeft(Tree<T>::Add_R(N, Current->getLeft()));
            else
                Current->setLeft(N);
            Current->getLeft()->setParent(Current);
        }
        if (Current->getData() < N->getData())
        {
            if (Current->getRight() != NULL)
                Current->setRight(Tree<T>::Add_R(N, Current->getRight()));
            else
                Current->setRight(N);
            Current->getRight()->setParent(Current);
        }
        if (Current->getData() == N->getData())
            ;
        return Current;
    }

    virtual void Add(int n)
    {
        Node<T>* N = new Node<T>;
        N->setData(n);
        Add_R(N);
    }

    virtual void Remove(Node<T>* N)
    { }

    virtual Node<T>* Min(Node<T>* Current=NULL)
    {
        if (root == NULL) return NULL;

        if(Current==NULL)
            Current = root;
        while (Current->getLeft() != NULL)
            Current = Current->getLeft();

        return Current;
    }

    virtual Node<T>* Max(Node<T>* Current = NULL)
    {
        if (root == NULL) return NULL;

        if (Current == NULL)
            Current = root;
        while (Current->getRight() != NULL)
            Current = Current->getRight();

        return Current;
    }

    virtual Node<T>* Find(int data, Node<T>* Current)
    {
        if (Current == NULL) return NULL;

        if (Current->getData() == data) return Current;

        if (Current->getData() > data) return Find(data, Current->getLeft());

        if (Current->getData() < data) return Find(data, Current->getRight());

        /*
        * main.cpp:159:5: warning: control reaches end of non-void function [-Wreturn-type]
        */
    }

    virtual void PreOrder(Node<T>* N, void (*f)(Node<T>*))
    {
        if (N != NULL)
            f(N);
        if (N != NULL && N->getLeft() != NULL)
            PreOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PreOrder(N->getRight(), f);
    }

    virtual void InOrder(Node<T>* N, void (*f)(Node<T>*))
    {
        if (N != NULL && N->getLeft() != NULL)
            InOrder(N->getLeft(), f);
        if (N != NULL)
            f(N);
        if (N != NULL && N->getRight() != NULL)
            InOrder(N->getRight(), f);
    }

    virtual void PostOrder(Node<T>* N, void (*f)(Node<T>*))
    {
        if (N != NULL && N->getLeft() != NULL)
            PostOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PostOrder(N->getRight(), f);
        if (N != NULL)
            f(N);
    }
};

template<typename ValueType>
class TreeIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:

public:
    TreeIterator() { ptr = NULL; T = NULL; }
    TreeIterator(Tree<ValueType>* t, Node<ValueType>* p) { T = t; ptr = p; }
    TreeIterator(const TreeIterator& it) { T = it.T; ptr = it.ptr; }

    TreeIterator& operator=(const TreeIterator& it) { T = it.T; ptr = it.ptr; return *this; }
    TreeIterator& operator=(Node<ValueType>* p)
    {
        if(T != nullptr && p!= nullptr && T->Find(p->getData(), T->getRoot())) ptr = p;
        return *this;
    }

    bool operator!=(TreeIterator const& other) const { return ptr != other.ptr; }
    bool operator==(TreeIterator const& other) const { return ptr == other.ptr; }
    Node<ValueType>& operator*()
    {
        return *ptr;
    }
    TreeIterator& operator++()
    {
        if(ptr == nullptr || T == nullptr){ return *this; }
        if(ptr->getRight() != nullptr)
        {
            ptr = T->Min(ptr->getRight());
            return *this;
        }

        Node<ValueType>* Current = ptr;
        while(Current->getParent() != nullptr && Current->getParent()->getLeft() != Current)
        {
            Current = Current->getParent();
        }
        if(Current->getParent() != nullptr)
            ptr = Current->getParent();

        return *this;
    }
    TreeIterator& operator++(int v)
    {

    }
private:
    Node<ValueType>* ptr;
    Tree<ValueType>* T;
};

template<class T>
class IteratedTree : public Tree<T>
{
public:
    IteratedTree<T>() : Tree<T>() {}

    TreeIterator<T> iterator;

    TreeIterator<T> begin() {  }
    TreeIterator<T> end() {  }
};

template<class T>
class AVL_Tree : public IteratedTree<T>
{
protected:
    int bfactor(Node<T>* p)
    {
        int hl = 0;
        int hr = 0;
        if (p->getLeft() != NULL)
            hl = p->getLeft()->getHeight();
        if (p->getRight() != NULL)
            hr = p->getRight()->getHeight();
        return (hr - hl);
    }

    void fixHeight(Node<T>* p)
    {
        int hl = 0;
        int hr = 0;
        if (p->getLeft() != NULL)
            hl = p->getLeft()->getHeight();
        if (p->getRight() != NULL)
            hr = p->getRight()->getHeight();
        p->setHeight((hl > hr ? hl : hr) + 1);
    }

    Node<T>* RotateRight(Node<T>* p)
    {
        Node<T>* q = p->getLeft();
        if(p->getParent() != nullptr)
        {
            if (p->getParent()->getLeft() == p) p->getParent()->setLeft(q);
            else p->getParent()->setRight(q);
        }

        q->setParent(p->getParent());
        p->setParent(q);
        if(q->getRight() != nullptr) p->getRight()->setParent(p);

        if(p == Tree<T>::root) Tree<T>::root = q;

        p->setLeft(q->getRight());
        q->setRight(q);

        fixHeight(p);
        fixHeight(q);
        return q;
    }

    Node<T>* RotateLeft(Node<T>* q)
    {
        Node<T>* p = q->getRight();

        if(p->getParent() != nullptr)
        {
            if(q->getParent()->getLeft() == q) q->getParent()->setLeft(p);
            else q->getParent()->setRight(p);
        }
        p->setParent(q->getParent());
        q->setParent(p);
        if(q->getRight() != nullptr) q->getRight()->setParent(p);

        if(p == Tree<T>::root) Tree<T>::root = p;

        fixHeight(q);
        fixHeight(p);
        return p;
    }

    Node<T>* Balance(Node<T>* p)
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

        return p;
    }

public:
    AVL_Tree<T>() : IteratedTree<T>() {}

    virtual Node<T>* Add_R(Node<T>* N)
    {
        return Add_R(N, Tree<T>::root);
    }

    virtual Node<T>* Add_R(Node<T>* N, Node<T>* Current)
    {
        Node<T>* AddedNode = Tree<T>::Add_R(N, Current);
        return Balance(AddedNode);
    }

    virtual void Add(T n)
    {
        Node<T>* N = new Node<T>;
        N->setData(n);
        Add_R(N);
    }

    virtual void Remove(Node<T>* N)
    { }
};



int main()
{
    AVL_Tree<double> T;
    int arr[15];
    int i = 0;
    for (i = 0; i < 15; i++) arr[i] = (int)(100 * cos(15 * double(i)));
    for (i = 0; i < 15; i++) T.Add(arr[i]);

    Node<double>* M = T.Min();
    cout << "\nMin = " << M->getData() << "\tFind " << arr[3] << ": " << T.Find(arr[3], T.getRoot());

    void (*f_ptr)(Node<double>*); f_ptr = print;
    /*cout << "\n-----\nPreorder:";
    T.PreOrder(T.getRoot(), f_ptr);*/
    cout << "\n-----\nInorder:";
    T.InOrder(T.getRoot(), f_ptr);
    /*cout << "\n-----\nPostorder:";
    T.PostOrder(T.getRoot(), f_ptr);*/
    /*cout << "\nIterators:\n";
    T.iterator = T.begin();
    while (T.iterator != T.end())
    {
        cout << *T.iterator << " ";
        T.iterator++;
    }
    cout << *T.iterator << " ";*/

    return 0;
}