#pragma once
#include <iostream>
#include <cstring>
#include "Date.h"
#include "ReaderNode.h"
using namespace std;
struct Reader {
	char code[12];
	char name[20];
	char ID[12];
	int gender;
	// 1: male, 2: female, 3: other, 0: undefined
	char email[20];
	char address[36];
	Date startDay;
	Date endDay;
};

void ThongTinDocGia(Reader reader);
void DanhSachDocGia(ReaderList* readerList);
ReaderNode* FindByName(ReaderList* list, char name[]);
Date UpdateEndDay(Date start);
void NhapThemDocGia(ReaderList* list);
void ThemDocGia(ReaderList* readerList, Reader reader);
int ReaderInfoChangeOption();
void ReaderInfoChanging(ReaderList* list);