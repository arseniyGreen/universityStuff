#include <iostream>
#include <list>
#include <algorithm>

template <class T>
void push(std::list<T> &L, T element)
{
    typename std::list<T>::iterator it = L.begin();

    while(it != L.end() && *it < element){
        *it++;
    }

    if(it != L.end())
        L.insert(it, element);

    else
        L.push_back(element);
}

template <class T>
bool condition(T x)
{
    bool ans = (x > 0) ? true : false;
    return ans;
}

template <class T>
void filter(std::list<T> &Source, std::list<T> &Dist, bool (*p)(T))
{
    typename std::list<T>::iterator it = Source.begin();

    while(it != Source.end()){

        if(p(*it))
            Dist.push_back(*it);

        *it++;
    }
}

int main()
{
    std::list<int> lst;

    for(size_t i = 0; i < 15; ++i)
    {
        lst.push_back(i);
    }

    push(lst, -100);

    std::list<int>::iterator p = lst.begin();

    while(p != lst.end())
    {
        std::cout << *p << " ";
        *p++;
    }

    std::cout << std::endl;

    std::list<int> lst1;

    filter(lst, lst1, condition);
    std::list<int>::iterator it = lst1.begin();
    while(it != lst1.end()){
        std::cout << *it << " ";
        *it++;
    }

    return 0;
}
