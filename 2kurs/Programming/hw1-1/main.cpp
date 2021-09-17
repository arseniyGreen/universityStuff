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
void pop(std::list<T>& lst, T elementToRemove)
{
    typename std::list<T>::iterator it = lst.begin();

    while(it != lst.end())
    {
        if(*it == elementToRemove)
        {
            std::cout << "\nElement found.";
            it = lst.erase(it);
            break;
        }
        *it++;
    }
    if(it == lst.end()) std::cerr << "\nNo such element.";
}

template<class T>
bool isEven(T x)
{
    return (x % 2 == 0);
}

/* This function filters list, removing all uneven numbers */
template<class T>
void filter(std::list<T>& first, std::list<T>& second, bool (*predicate)(T))
{
    std::list<T>::iterator it = first.begin();
    while(it != first.end())
    {
        if(predicate(*it)) push(second, *it);
        *it++;
    }
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
        //system("sleep 0.1"); //remove it later
    }

    lst.sort();

    std::cout << "\nBefore insertion : \n";
    printList(lst);

    push(lst, 100);
    push(lst, 0);

    std::cout << "\nAfter insertion : \n";
    printList(lst);

    /* Pop test */

    int toRemove = NULL;
    std::cout << "\nChoose element to delete: ";
    std::cin >> toRemove; std::cout << std::endl;

    pop(lst, toRemove);
    printList(lst);

    /* Filter test */
    std::list<int> lst2;
    filter(lst, lst2, isEven);
    std::cout << "\nSecond list:\n";
    printList(lst2);

    return 0;
}
