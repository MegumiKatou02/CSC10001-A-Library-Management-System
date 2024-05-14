#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
#include "Date.h"
#include <iostream>
#include <cstring>
using namespace std;
struct Reader {
	string code;
	string name;
	string ID;
	int gender;
	// 1: male, 2: female, 3: other, 0: undefined
	string email;
	string address;
	Date startDay;
	Date endDay;
	Reader();
};

void ThongTinDocGia(Reader reader);