#include "Date.h"

Date::Date() {
    this->day = 2;
    this->month = 12;
    this->year = 1996;
}

bool LeapYear(const int &year) {
    return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

int DaysInMonth(int month, int year) {
    int dayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(LeapYear(year)) dayInMonth[2]++;
    return dayInMonth[month];
}

Date addDays(Date date, int daysToAdd) {
    while (daysToAdd > 0) {
        int daysInCurrentMonth = DaysInMonth(date.month, date.year);
        if (date.day + daysToAdd <= daysInCurrentMonth) {
            date.day += daysToAdd;
            daysToAdd = 0;
        }
        else {
            daysToAdd -= (daysInCurrentMonth - date.day + 1);
            date.day = 1;
            if (date.month == 12) {
                date.month = 1;
                date.year++;
            }
            else {
                date.month++;
            }
        }
    }
    return date;
}