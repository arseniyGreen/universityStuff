#include <iostream>
#include <queue>
#include <string>
#include <vector>
//#include "Series.h"

#define _GLIBCXX_USE_CXX11_ABI 0

class Series
{
private:
    std::string title, producer, country;
    short seasons, popularity, rate;
    int date;
public:
    Series()
    {
        title = producer = country = "";
        seasons = popularity = rate = 0;
        date = 0;
    };
    Series(std::string title_, std::string producer_, std::string country_, short seasons_, short popularity_, short rate_, int date_)
    {
        title = std::move(title_); producer = std::move(producer_); country = std::move(country_);
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
    return (s1.rate == s2.rate) ? s1.title < s2.title : s1.rate < s2.rate;
}

bool operator >(const Series &s1, const Series &s2)
{
    return (s1.rate == s2.rate) ? s1.title > s2.title : s1.rate > s2.rate;
}

bool operator ==(const Series &s1, const Series &s2)
{
    return (s1.rate == s2.rate && s1.title == s2.title && s1.producer == s2.producer && s1.seasons == s2.seasons && s1.date == s2.date && s1.popularity == s2.popularity);
}

template<class K, class V>
void printQueue(std::priority_queue<std::pair<K, V>>& q)
{
    while(!q.empty())
    {
        Series tmp = q.top().second;
        std::cout << "\nKey : " << q.top().first << "\tValue:" << tmp;
        q.pop();
    }
}

int main() {
    std::priority_queue<std::pair<std::string, Series>> q;

    Series MrR("Mister Robot", "Sam Esmail", "USA", 4, 88, 92, 24062015);
    Series GoT("Game Of Thrones", "David Benioff", "USA", 8, 100, 92, 17042011);
    Series TwD("The Walking Dead", "Jolly Dale", "USA", 10, 84, 94, 31102010);
    Series Fb("Family Business", "Carl Weber", "France", 2, 73, 89, 28062019);

    std::pair <std::string, Series> MR; MR.first = std::string("MrR"); MR.second = MrR;
    std::pair <std::string, Series> GOT; GOT.first = std::string("GoT"); GOT.second = GoT;
    std::pair <std::string, Series> TWD; TWD.first = std::string("TwD"); TWD.second = TwD;
    std::pair <std::string, Series> FB; FB.first = std::string("FB"); FB.second = Fb;

    q.push(MR); q.push(GOT); q.push(TWD); q.push(FB);

    printQueue(q);

    return 0;
}
