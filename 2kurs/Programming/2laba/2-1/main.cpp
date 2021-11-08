/* Аркадсков А.Е. КТСО-02-20 */

#include <iostream>
#include <string>
#include <map>

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
        seasons = popularity = rate = date = NULL;
    };
    Series(std::string title_, std::string producer_, std::string country_, short seasons_, short popularity_, short rate_, int date_)
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

void printTree(std::map<std::string, Series> tree)
{
    std::map<std::string, Series>::iterator it = tree.begin();
    while(it != tree.end())
    {
        std::cout << "Key : " << it->first << " , Value : " << it->second << "\n";
        *it++;
    }
}

int main() {
    //<key, value>
    //tree[key] = value;
    Series MrR("Mister Robot", "Sam Esmail", "USA", 4, 88, 92, 24062015);
    Series GoT("Game Of Thrones", "David Benioff", "USA", 8, 100, 92, 17042011);
    Series TwD("The Walking Dead", "Jolly Dale", "USA", 10, 84, 94, 31102010);
    Series FB("Family Business", "Carl Weber", "France", 2, 73, 89, 28062019);

    std::map<std::string, Series> tree;

    tree["Mr Robot"] = MrR;
    tree["GoT"] = GoT;
    tree["TwD"] = TwD;
    tree["FB"] = FB;

    printTree(tree);
    return 0;
}
