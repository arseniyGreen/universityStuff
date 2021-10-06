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
    typename std::list<T>::iterator it = first.begin();
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

class Series
{
private:
   std::string name, producer, country;
   int seasons, popularity, rate, year;

public:
    Series(){ name = ""; producer = ""; country = ""; seasons = NULL; popularity = NULL; rate = NULL; year = NULL; };
    Series(std::string name_, std::string producer_, std::string country_, int seasons_, int popularity_, int rate_, int year_)
    {
        name = name_; producer = producer_; country = country_; seasons = seasons_; popularity = popularity_; rate = rate_; year = year_;
    }
};

int main()
{

    return 0;
}
