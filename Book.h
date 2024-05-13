#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "ultilty.h"

using namespace std;

struct Book {
    string ISBN;
	string name;
	string author;
	string publisher;
	int yearPublish;
	string type;
	double price;
	int number;
};

void ThongTinQuyenSach(Book book);
int HashBookCode(const string &s);
string EncodeBookCode(Book book);
string HashSixDigitCode(int num);