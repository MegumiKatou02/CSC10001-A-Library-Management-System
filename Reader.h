#pragma once
#include <iostream>
#include "Date.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include "LendCardList.h"

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
	LendCardList *lendCardList; // tap hop cac phieu muon ma doc gia da muon
	Reader();
	~Reader();
};

void ThongTinDocGia(Reader reader);
int HashReaderCode(const string &s);
string EncodeReaderCode(Reader reader);
string HashSixDigitCodeR(int num);
