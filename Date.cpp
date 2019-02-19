/**
 * TODO header
 */

#include "Date.h"

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

void Date::setMonth(Month m) {
    month = (unsigned)m;
}

Month Date::getMonthEnum() {
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

bool Date::isCorrect() {
    return true;
}