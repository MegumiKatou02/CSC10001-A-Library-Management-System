#include "Date.h"

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 31;
    }
}

Date addDays(Date date, int daysToAdd) {
    while (daysToAdd > 0) {
        int daysInCurrentMonth = daysInMonth(date.month, date.year);
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

int daysFromThisYear(int day, int month, int year) {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += daysInMonth(m, year);
    }
    return days + day;
}


int daysCalculate(Date firstDate, Date lastDate) { // lastDate luon nam sau firstDate nhe <(")
    int days = 0;

    // Tính khoảng cách từ năm nhỏ hơn đến năm hiện tại
    for (firstDate.year; firstDate.year < lastDate.year; firstDate.year++) {
        days += isLeapYear(firstDate.year) ? 366 : 365;
    }

    // Tính khoảng cách từ đầu năm đến ngày hiện tại
    days += daysFromThisYear(lastDate.day, lastDate.month, lastDate.year) - daysFromThisYear(firstDate.day, firstDate.month, firstDate.year);
    return days;
}
