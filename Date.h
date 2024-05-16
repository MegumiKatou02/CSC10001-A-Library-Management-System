#pragma once

struct Date {
    int day, month, year;
    Date();
};

bool LeapYear(const int &year);

int DaysInMonth(int month, int year);

Date addDays(Date date, int daysToAdd);