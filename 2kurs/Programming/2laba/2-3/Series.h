#ifndef INC_2_2_SERIES_H
#define INC_2_2_SERIES_H
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

#endif //INC_2_2_SERIES_H
