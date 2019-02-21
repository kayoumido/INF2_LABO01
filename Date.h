/**
 * TODO header
 */

#ifndef DATE_H
#define DATE_H

#include <string>

enum class Month {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAI = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};

class Date {
public:
    Date() : day(1), month(1), year(1970) {};
    Date(unsigned, unsigned, unsigned);
    Date(unsigned, Month, unsigned);

    void setDay(const unsigned& DAY);
    void setMonth(const unsigned& MONTH);
    void setMonth(const Month& m);
    void setMonth(const std::string& MONTH);
    void setYear(const unsigned& YEAR);

    unsigned getDay() const;
    unsigned getMonth() const;
    Month getMonthEnum() const;
    std::string getMonthString() const;
    unsigned getYear() const;

private:
    unsigned day;
    unsigned month;
    unsigned year;
    bool correct;

    bool isCorrect();
};


#endif DATE_H
