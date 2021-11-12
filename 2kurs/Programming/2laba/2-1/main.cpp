/* Аркадсков А.Е. КТСО-02-20 */

#include <iostream>
#include <string>
#include <map>
#include <utility>

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

bool isHigher(Series S)
{
    int treshold = 90;
    return S.getRate() > treshold;
}

template<class A, class B>
std::map<A, B> filter(std::map<A, B>& tree, bool (*predicate)(B))
{
    std::map<A, B> newTree;
    typename std::map<A, B>::iterator it = tree.begin();
    while(it != tree.end())
    {
        if(predicate(it->second))
        {
            newTree[it->first] = it->second;
        }
        *it++;
    }
    return newTree;
}

template<class A, class B>
void printTree(std::map<A, B> tree)
{
    typename std::map<A, B>::iterator it = tree.begin();
    while(it != tree.end())
    {
        std::cout << "Key : " << it->first << " , Value : " << it->second << "\n";
        it++;
    }
}

template<class A, class B>
void findByKey(std::map<A, B> tree, A key)
{
    if(tree.count(key) == 1)
    {
        std::cout << "\nKey found!. Value by key : " << tree.at(key) << "\n";
    }
    else
    {
        std::cout << "\nNo matches found!\n";
    }
}

template<class A, class B>
void findByValue(std::map<A, B> tree, B value)
{
    typename std::map<A, B>::iterator it = tree.begin();
    while(it != tree.end())
    {
        if(it->second == value){ std::cout << "\nVALUE FOUND : " << value << " KEY FOR THIS VALUE : " << it->first; return; }
        *it++;
    }
    std::cout << "\nNO MATCHES FOUND.\n";
}

int main() {
    Series MrR("Mister Robot", "Sam Esmail", "USA", 4, 88, 92, 24062015);
    Series GoT("Game Of Thrones", "David Benioff", "USA", 8, 100, 92, 17042011);
    Series TwD("The Walking Dead", "Jolly Dale", "USA", 10, 84, 94, 31102010);
    Series FB("Family Business", "Carl Weber", "France", 2, 73, 89, 28062019);

    std::map<std::string, Series> tree;

    tree["MrR"] = MrR;
    tree["GoT"] = GoT;
    tree["TwD"] = TwD;
    tree["FB"] = FB;

    printTree(tree);

    std::cout << "\nFilter test\n";
    std::map<std::string, Series> filteredTree = filter(tree, isHigher);
    printTree(filteredTree);

    std::cout << "\nKey search test:\n";
    findByKey(tree, std::string("FB")); //success
    findByKey(tree, std::string("RANDOM STRING")); //fail

    std::cout << "\nValue search test:\n";
    Series MrR_duplicate("Mister Robot", "Sam Esmail", "USA", 4, 88, 92, 24062015);
    Series MrR_wrong("Mister Robott", "Sam Esmail", "Russia", 4, 88, 101, 24062015);
    findByValue(tree, MrR_duplicate); //success
    findByValue(tree, MrR_wrong); //fail

    return 0;
}
