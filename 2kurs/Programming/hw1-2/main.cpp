/* Аркадсков А.Е. КТСО-02-20 */

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

class Series
{
private:
    std::string title, producer, country;
    short seasons, popularity, rate, date;
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
    std::string getTitle() const { return title; }
    std::string getProducer() const { return producer; }
    std::string getCountry() const { return country; }
    short getRate() const { return rate; }

    friend std::ostream& operator<< (std::ostream& stream, Series& series);
};

std::ostream& operator<< (std::ostream& stream, Series& series)
{
    stream << "\nTitle : " << series.getTitle() << "\nProducer : " << series.getProducer() << "\nCountry : " << series.getCountry() << "\nRate : " << series.getRate() << std::endl;
    return stream;
}

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
    std::list<Series> lst;
    Series got;
    push(lst, got);

    return 0;
}
