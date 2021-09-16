#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

template<class T>
void push(std::list<T>& lst, T element)
{
    typename std::list<T>::iterator it = lst.begin();

        while(it != lst.end() && *it < element)
        {
            if(*it > element) break;

            *it++;
        }
        lst.insert(it, element);
}

template<class T>
void pop()
{

}

template<class T>
void printList(std::list<T>& lst)
{
    typename std::list<T>::iterator p = lst.begin();

    while(p != lst.end())
    {
        std::cout << *p << " ";
        *p++;
    }
}

int main()
{
    srand(time(NULL));
    std::list<int> lst;

    /* Fill list with random numbers */
    for(size_t i = 0; i < 10; i++)
    {
        lst.push_back(rand() % 50 + 1);
        system("sleep 0.1"); //remove it later
    }

    lst.sort();

    std::cout << "\nBefore insertion : \n";
    printList(lst);

    push(lst, 100);
    push(lst, 0);

    std::cout << "\nAfter insertion : \n";
    printList(lst);

    return 0;
}
