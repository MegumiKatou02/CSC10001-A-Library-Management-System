#pragma once
#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>

using namespace std;

struct Date {
    int day, month, year;
    friend ostream &operator<<(ostream &out, const Date &date);
    bool operator>(const Date &date);
    bool operator<(const Date &date);
    bool operator==(const Date &date);
    Date(const Date &date);
    Date(int day = 2, int month = 2, int year = 1996);
    Date operator=(const Date &date);
    Date &operator++(int);
};

bool isLeapYear(const int &year);

int DaysInMonth(int month, int year);

Date addDays(Date date, int daysToAdd);

int DaysFromThisYear(int day, int month, int year);

int DaysCalculate(Date firstDate, Date lastDate);

Date RealDate();

void SwapDate(Date &a, Date &b);
