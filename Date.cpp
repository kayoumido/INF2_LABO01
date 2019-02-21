/**
 * TODO header
 */

#include "Date.h"
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> STR_MONTHS {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};


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


void Date::setDay(const unsigned& DAY) {
    day = DAY;
}
void Date::setMonth(const unsigned& MONTH) {
    month = MONTH;
}
void Date::setMonth(const Month& m) {
    month = (unsigned)m;
}
void Date::setMonth(const string& MONTH) {
    vector<string>::const_iterator it =  find(STR_MONTHS.cbegin(), STR_MONTHS.cend(), MONTH);
    month = (unsigned)distance(STR_MONTHS.begin(), it) + 1;
}
void Date::setYear(const unsigned& YEAR) {
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


bool Date::isCorrect() {
    return true;
}