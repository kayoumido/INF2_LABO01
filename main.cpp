/**
 * todo header
 */

#include "Date.h"
#include <iostream>


using namespace std;

int main() {

    Date date(4, 7, 1993);

    cout << "Vore date est : " << date.getDay() << " " << date.getMonthString() << " " << date.getYear() << endl;

    return 0;
}