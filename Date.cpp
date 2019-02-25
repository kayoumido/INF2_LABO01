/**
 * TODO header
 */

#include "Date.h"
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const vector<string> STR_MONTHS{"january", "february", "march", "april", "may", "june", "july", "august", "september",
                                "october", "november", "december"};
const string INVALID_MSG = "invalide";
const char DELIMITER = '.';


Date::Date() : day(1), month(1), year(1970), correct(true) {}

Date::Date(unsigned d, unsigned m, unsigned y) {
    day = d;
    month = m;
    year = y;

    correct = isCorrect();
}

Date::Date(unsigned d, Month m, unsigned y) {
    day = d;
    setMonth(m);
    year = y;

    correct = isCorrect();
}


void Date::setDay(const unsigned DAY) {
    day = DAY;
}

void Date::setMonth(const unsigned MONTH) {
    month = MONTH;
}

void Date::setMonth(const Month &m) {
    month = (unsigned) m;
}

void Date::setMonth(const string &MONTH) {
    vector<string>::const_iterator it = find(STR_MONTHS.cbegin(), STR_MONTHS.cend(), MONTH);
    month = (unsigned) distance(STR_MONTHS.begin(), it) + 1;
}

void Date::setYear(const unsigned YEAR) {
    year = YEAR;
}


unsigned Date::getDay() const {
    return day;
}

unsigned Date::getMonth() const {
    return month;
}

Month Date::getMonthEnum() const {
    switch (month) {
        case 1:
            return Month::JANUARY;
        case 2:
            return Month::FEBRUARY;
        case 3:
            return Month::MARCH;
        case 4:
            return Month::APRIL;
        case 5:
            return Month::MAI;
        case 6:
            return Month::JUNE;
        case 7:
            return Month::JULY;
        case 8:
            return Month::AUGUST;
        case 9:
            return Month::SEPTEMBER;
        case 10:
            return Month::OCTOBER;
        case 11:
            return Month::NOVEMBER;
        case 12:
            return Month::DECEMBER;
    }
}

string Date::getMonthString() const {
    return STR_MONTHS.at(month - 1);
}

unsigned Date::getYear() const {
    return year;
}


Date &Date::operator++() {

    if (isCorrect()) {
        day++;

        if (day > getMonthLength()) {
            day = day - getMonthLength();
            month++;

            if (month > Date::LAST_MONTH) {
                month = Date::FIRST_MONTH;
                year++;
            }
        }
    }
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;

    ++*this;

    return temp;
}

Date Date::operator+(const unsigned DAY) const {

    Date temp = *this;

    if (isCorrect()) {
        for (unsigned i = 0; i < DAY; ++i)
            ++temp;
    }

    return temp;
}

Date operator+(const unsigned days, const Date &DATE) {
    return DATE + days;
}

Date &Date::operator--() {

    if (isCorrect()) {
        day--;

        if (day == 0) {
            month--;
            day = getMonthLength();

            if (month == 0) {
                year--;
                month = Date::LAST_MONTH;

                if (year < Date::MIN_YEAR) {
                    correct = false;
                }
            }
        }
    }
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;

    --*this;

    return temp;
}

Date Date::operator-(const unsigned DAY) const {
    Date temp = *this;
    if (isCorrect()) {
        for (unsigned i = 0; i < DAY; ++i)
            --temp;
    }

    return temp;
}

Date operator-(const unsigned days, const Date &DATE) {
    return DATE - days;
}

ostream &operator<<(ostream &os, const Date &DATE) {
    if (DATE.correct) {
        string strDay = (DATE.day < 10) ? "0" + to_string(DATE.day) : to_string(DATE.day);
        string strMonth = (DATE.month < 10) ? "0" + to_string(DATE.month) : to_string(DATE.month);

        cout << strDay << "." << strMonth << "." << DATE.year;
    } else {
        cout << INVALID_MSG;
    }

    return os;
}

istream &operator>>(istream &is, Date &date) {
    string userInput;
    is >> userInput;

    // Put the correct flag to false, and if all params are correct, put to true
    date.correct = false;

    // correct date must be 10 length (dd.mm.yyyy)
    if (userInput.length() == 10) {
        // Check the dot position
        if (userInput.at(2) == DELIMITER and userInput.at(5) == DELIMITER) {

            int inputDay;
            int inputMonth;
            int inputYear;
            stringstream ssDay(userInput.substr(0, 2));
            stringstream ssMonth(userInput.substr(3, 2));
            stringstream ssYear(userInput.substr(6, 4));

            // Check if day, month, year are integer, and fetch them
            if (ssDay >> inputDay and ssMonth >> inputMonth and ssYear >> inputYear) {

                // Set all data and check if the date is correct
                date.setDay(inputDay);
                date.setMonth(inputMonth);
                date.setYear(inputYear);

                if (date.isCorrect()) {
                    date.correct = true;
                }

            }

        }

    }
    return is;
}

bool operator<(const Date &L_DATE, const Date &R_DATE) {
    bool result = false;

    if (L_DATE.isCorrect() and R_DATE.isCorrect()) {
        if (L_DATE.year < R_DATE.year) {
            result = true;
        } else if (L_DATE.year == R_DATE.year) {
            if (L_DATE.month < R_DATE.month) {
                result = true;
            } else if (L_DATE.month == R_DATE.month) {
                if (L_DATE.day < R_DATE.day) {
                    result = true;
                }
            }
        }
    }

    return result;
}

bool operator>(const Date &L_DATE, const Date &R_DATE) {
    return R_DATE < L_DATE;
}

bool operator<=(const Date &L_DATE, const Date &R_DATE) {
    return !(L_DATE > R_DATE);
}

bool operator>=(const Date &L_DATE, const Date &R_DATE) {
    return !(L_DATE < R_DATE);
}

bool operator==(const Date &L_DATE, const Date &R_DATE) {
    return (L_DATE <= R_DATE) and (L_DATE >= R_DATE);
}


bool Date::isCorrect() const {
    return day >= 1 and day <= getMonthLength() and
           month >= Date::FIRST_MONTH and
           month <= Date::LAST_MONTH and
           year >= Date::MIN_YEAR;
}

bool Date::isLeapYear() const {
    return ((year % 4 == 0) && year % 100 != 0) || year % 400 == 0;
}

unsigned Date::getMonthLength() const {
    unsigned totalDaysInMonth;

    if (getMonthEnum() == Month::FEBRUARY) {
        if (isLeapYear()) {
            totalDaysInMonth = 29;
        } else {
            totalDaysInMonth = 28;
        }
    } else if ((month % 2 == 0 && getMonthEnum() < Month::JULY) ||
               (month % 2 == 1 && getMonthEnum() > Month::JULY)
            ) {
        totalDaysInMonth = 30;
    } else {
        totalDaysInMonth = 31;
    }

    return totalDaysInMonth;
}
