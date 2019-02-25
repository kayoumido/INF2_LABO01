/**
 * todo header
 */

#include "Date.h"
#include <iostream>


using namespace std;

int main() {

    Date date1(04, 07, 1993);
    Date date2(28, 02, 2019);
    Date date3;

    cout << (date2 == date1) << endl;

    cout << date2 << endl;

    date3 = date2;

    date1 = {1, 2, 1995};

    cout << date1 << endl;
    cout << date3 << endl;

    return 0;
}