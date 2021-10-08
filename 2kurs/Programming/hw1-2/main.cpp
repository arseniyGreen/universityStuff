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
    Series(std::string title_, std::string producer_, std::string country_, short seasons_, short popularity_, short rate_, short date_)
    {
        title = title_; producer = producer_; country = country_;
        seasons = seasons_; popularity = popularity_; rate = rate_; date = date_;
    };
    std::string getTitle() const { return title; }
    std::string getProducer() const { return producer; }
    std::string getCountry() const { return country; }
    short getRate() const { return rate; }
    short getSeasons() const { return seasons; }
    short getPopularity() const { return popularity; }

    friend std::ostream& operator<< (std::ostream& stream, Series& series);
    friend bool operator <(const Series &s1, const Series &s2);
    friend bool operator >(const Series &s1, const Series &s2);
    friend bool operator ==(const Series &s1, const Series &s2);
};

std::ostream& operator<< (std::ostream& stream, Series& series)
{
    stream << "\nTitle : " << series.getTitle() << "\nProducer : " << series.getProducer() << "\nCountry : " << series.getCountry() << "\nRate : " \
    << series.getRate() << "\nSeasons : " << series.getSeasons() << "\nPopularity : " << series.getPopularity() << std::endl;
    return stream;
}

bool operator <(const Series &s1, const Series &s2)
{
    return s1.rate < s2.rate;
}

bool operator >(const Series &s1, const Series &s2)
{
    return s1.rate > s2.rate;
}

bool operator ==(const Series &s1, const Series &s2)
{
    return s1.rate == s2.rate;
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
    std::list<Series> def;

    Series MrR("Mister Robot", "Sam Esmail", "USA", 4, 88, 92, 24062015);
    Series GoT("Game Of Thrones", "David Benioff", "USA", 8, 100, 92, 17042011);
    Series TwD("The Walking Dead", "Jolly Dale", "USA", 10, 84, 94, 31102010);
    Series FB("Family Business", "Carl Weber", "France", 2, 73, 89, 28062019);

    push(lst, MrR);
    push(lst, GoT);
    push(lst, TwD);
    push(lst, FB);

    def.push_back(MrR);
    def.push_back(GoT);
    def.push_back(TwD);
    def.push_back(FB);

    std::cout << "\nUnsorted :\n";
    printList(def);

    std::cout << "\nSorted :\n";
    printList(lst);


    return 0;
}
