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

    /**
     * @brief Default constructor
     */
    Date();

    /**
     * @brief Constructor with unsigned values
     *
     * @param d day of the date
     * @param m month of the date
     * @param y year of the date
     */
    Date(unsigned d, unsigned m, unsigned y);

    /**
     * @brief Constructor with unsigned values and enum for the month
     *
     * @param d day of the date
     * @param m month of the date as a Month enum
     * @param y year of the date
     */
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


    /**
     * @brief (pre)increment the day of a date by one
     *
     * @return date incremented by one day
     */
    Date &operator++();

    /**
     * @brief (post)increment the day of a date by one
     *
     * @return date before incrementation
     */
    Date operator++(int);

    /**
     * @brief add x days to a date (Date + nb_days)
     *
     * @param DAYS to add to date
     * @return date increased by given number of days
     */
    Date operator+(const unsigned DAYS) const;

    /**
     * @brief (pre)decrease the day of a date by one
     *
     * @return date decreased by one day
     */
    Date &operator--();

    /**
     * @brief (post)decrease the day of a date by one
     *
     * @return date decreased by one day
     */
    Date operator--(int);

    /**
     * @brief remove x days to a date (Date - nb_days)
     *
     * @param DAYS to remove to date
     * @return date decreased by given number of days
     */
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
     * @brief Compare if the left Date is lower than the right Date. The comparison is made
     * by the whole date (day, month, year). e.g : 01.01.2000 is lower than 02.03.2000
     *
     * @param L_Date The left Date object
     * @param R_DATE The Right Date object
     * @return True if the left Date is lower than the right Date, false otherwise
     */
    friend bool operator<(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date is greater than the right Date
     * @details To do that, we use the "<" override operator
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if the left Date is greater than the right Date, false otherwise
     */
    friend bool operator>(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date is lower or equal than the right Date
     * @details To do that, we use the ">" override operator
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if the left Date is lower or equal than the right Date, false otherwise
     */
    friend bool operator<=(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date is greater or equal than the right Date
     * @details To do that, we use the "<" override operator
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if the left Date is greater or equal than the right Date, false otherwise
     */
    friend bool operator>=(const Date &L_Date, const Date &R_DATE);

    /**
     * @brief Compare if the left Date equals the right Date
     * @details To do that, we use the "<=" and ">=" override operators
     *
     * @param L_Date The left Date object
     * @param R_DATE The right Date object
     * @return True if both dates are equal, false otherwise
     */
    friend bool operator==(const Date &L_DATE, const Date &R_DATE);

    /**
     * @brief add x days to a date (nb_days + Date)
     *
     * @param DAYS to add to date
     * @param DATE to increase
     * @return date increased by given number of days
     */
    friend Date operator+(const unsigned DAYS, const Date &DATE);

    /**
     * @brief remove x days to a date (nb_days - Date)
     *
     * @param DAYS to remove to date
     * @param DATE to decrease
     * @return date decreased by given number of days
     */
    friend Date operator-(const unsigned DAYS, const Date &DATE);

private:
    // 1852 was chosen as the min year because it is the year the Gregorian calendar was created
    //  https://en.wikipedia.org/wiki/Gregorian_calendar
    static const unsigned MIN_YEAR = 1852;
    static const unsigned FIRST_MONTH = 1;
    static const unsigned LAST_MONTH = 12;


    unsigned day;
    unsigned month;
    unsigned year;
    bool correct;

    /**
     * @brief CHeck if the current Date object is correct
     *          i.e the day is between 1 and getMonthLength
     *              the month is between 1 and 12
     *              and the year is greater than 1852.
     *              
     * @return true if the date is correct otherwise false
     */
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
