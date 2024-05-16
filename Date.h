#pragma once
#define jan, mar, may, jul, aug, oct, dec 31;
#define apr, jun, sep, nov 30;

struct Date {
    int day, month, year;
};

// cac ham ho tro dem so ngay trong thang, nam
bool isLeapYear(int year);
int daysInMonth(int month, int year);

// cac ham tinh toan so ngay
int daysCalculate(Date firstDate, Date lastDate);
int daysFromThisYear(int day, int month, int year);