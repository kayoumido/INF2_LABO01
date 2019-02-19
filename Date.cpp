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

bool Date::isCorrect() {
    return true;
}