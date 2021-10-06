/* Аркадсков А.Е. КТСО-02-20 */

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

class Series
{
private:
    std::string title, producer, country;
    size_t seasons, popularity, rate, date;
public:
    Series()
    {
        title = producer = country = "";
        seasons = popularity = rate = date = NULL;
    };
    Series(std::string title_, std::string producer_, std::string country_, size_t seasons_, size_t popularity_, size_t rate_, size_t date_)
    {
        title = title_; producer = producer_; country = country_;
        seasons = seasons_; popularity = popularity_; rate = rate_; date = date_;
    };

};

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
T pop(std::list<T>& lst)
{
    typename std::list<T>::iterator it = lst.begin();

    T returnValue;

    while(it != lst.end()) it++;
    it--;
    returnValue = *it;
    lst.erase(it);
    return returnValue;
}

template<class T>
bool isPositive(T x)
{
    return x > 0;
}

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

int main()
{
    srand(time(nullptr));
    std::list<double> lst;

    /* Fill list with random numbers */
    for(size_t i = 0; i < 30; i++)
    {
        lst.push_back(rand() % 100 - 90);
    }

    lst.sort();

    std::cout << "\nBefore insertion : \n";
    printList(lst);

    push(lst, 100.12);
    push(lst, 0.3);
    push(lst, -50.0);
    push(lst, -302.213);
    push(lst, -15.52);

    std::cout << "\nAfter insertion : \n";
    printList(lst);

    /* Pop test */
    double retVal = pop(lst);

    std::cout << "\nAfter deletion:\n";
    printList(lst);
    std::cout << "\nPop function returned " << retVal << "\n";

    /* Filter test */
    std::list<double> lst2;
    filter(lst, lst2, isPositive);
    std::cout << "\nSecond list:\n";
    printList(lst2);

    return 0;
}
