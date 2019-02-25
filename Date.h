/**
 * TODO header
 */

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

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
    Date();

    Date(unsigned d, unsigned m, unsigned y);

    Date(unsigned d, Month m, unsigned y);


    void setDay(const unsigned DAY);

    void setMonth(const unsigned MONTH);

    void setMonth(const Month &m);

    void setMonth(const std::string &MONTH);

    void setYear(const unsigned YEAR);


    unsigned getDay() const;

    unsigned getMonth() const;

    Month getMonthEnum() const;

    std::string getMonthString() const;

    unsigned getYear() const;


    Date &operator++();

    Date operator++(int);

    Date operator+(const unsigned DAYS) const;

    Date &operator--();

    Date operator--(int);

    Date operator-(const unsigned DAYS) const;

    /**
     * @brief Display the date with this format : dd.mm.yyyy
     *
     * @param os The ostream (e.g : cout)
     * @param DATE The date we want to display
     * @return The current ostream to be able to chain multiples of them
     */
    friend std::ostream &operator<<(std::ostream &os, const Date &DATE);

    /**
     * @brief Type a date (format : dd.mm.yyyy) and store into a Date object
     *
     * @param is The instream (e.g cin)
     * @param date The Date object we want to put into the data typed
     * @return The current istream to be able to chain multiples of them
     */
    friend std::istream &operator>>(std::istream &is, Date &date);

    /**
     * @brief Compare if the left Date is lower than the right Date
     *
     * @param L_Date The left Date object
     * @param R_DATE The Right Date object
     * @return True if the left Date is lower than the right Date, false otherwise
     */
    friend bool operator<(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date is greater than the right Date
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if the left Date is greater than the right Date, false otherwise
     */
    friend bool operator>(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date is lower or equal than the right Date
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if the left Date is lower or equal than the right Date, false otherwise
     */
    friend bool operator<=(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date is greater or equal than the right Date
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if the left Date is greater or equal than the right Date, false otherwise
     */
    friend bool operator>=(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date equals the right Date
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if both dates are equal, false otherwise
     */
    friend bool operator==(const Date &L_DATE, const Date &R_DATE);
    
    friend Date operator+(const unsigned DAYS, const Date &DATE);

    friend Date operator-(const unsigned DAYS, const Date &DATE);

private:
    static const unsigned MIN_YEAR = 1852;
    static const unsigned FIRST_MONTH = 1;
    static const unsigned LAST_MONTH = 12;


    unsigned day;
    unsigned month;
    unsigned year;
    bool correct;

    bool isCorrect() const;

    /**
     * @brief Determines if a given year is a leap year or a common year
     *
     * If the year is divisible by 4 and not divisible by 100 or
     * if the year is divisible by 400, then it's a leap year
     * (all divisions are integer divisions)
     * All the other cases, it's a common year
     *
     * @param year unsigned The year which will be checked
     * @return bool Is or isn't a leap year
     */
    bool isLeapYear() const;

    /**
     * @brief Return the total number of days contain in the month of a specific year
     *
     * @param monthIndex
     * @return The total number of days contains in the month
     */
    unsigned getMonthLength() const;
};


#endif
