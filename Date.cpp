#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

bool isLeapYear(const int &year) {
    return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

int DaysInMonth(int month, int year) {
    int dayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear(year)) dayInMonth[2]++;
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

ostream &operator<<(ostream &out, const Date &date) {
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

bool Date::operator>(const Date &date) {
    if(this->year > date.year) {
        return true;
    }
    if(this->year == date.year && this->month > date.month) {
        return true;
    }
    if(this->year == date.year && this->month == date.month && this->day > date.day) {
        return true;
    }
    return false;
}

int DaysFromThisYear(int day, int month, int year) {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += DaysInMonth(m, year);
    }
    return days + day;
}


int DaysCalculate(Date firstDate, Date lastDate) { // lastDate luon nam sau firstDate nhe <(")
    int days = 0;
    if(firstDate > lastDate) {
        SwapDate(firstDate, lastDate);
    }

    // Tính khoảng cách từ năm nhỏ hơn đến năm hiện tại
    for (firstDate.year; firstDate.year < lastDate.year; firstDate.year++) {
        days += isLeapYear(firstDate.year) ? 366 : 365;
    }

    // Tính khoảng cách từ đầu năm đến ngày hiện tại
    days += DaysFromThisYear(lastDate.day, lastDate.month, lastDate.year) - DaysFromThisYear(firstDate.day, firstDate.month, firstDate.year);
    return days;
}

Date RealDate() {
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm *localTime = std::localtime(&currentTime);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1; // (0 - 11)
    int year = localTime->tm_year + 1900; // tm_year -> 1900 (bat dau tu 1900s)
    return Date(day, month, year);
}

Date::Date(const Date &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date Date::operator=(const Date &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    return *this;
}

void SwapDate(Date &a, Date &b) {
    Date temp = a;
    a = b;
    b = temp;
}

bool Date::operator==(const Date &date) {
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

bool Date::operator<(const Date &date) {
    return !(*this > date || *this == date);
}

Date &Date::operator++(int) {
    if(day == DaysInMonth(month, year)) {
        day = 1;
        if(month == 12) {
            month = 1;
            year++;
        }
        else month++;
    }
    else day++;
    return *this;
}