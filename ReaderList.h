#pragma once
#include "ReaderNode.h"

struct ReaderList {
	ReaderNode* head;
	ReaderNode* tail;
	ReaderList();
};

void DanhSachDocGia(ReaderList* readerList);
ReaderNode* FindByName(ReaderList* list, char name[]);
Date UpdateEndDay(Date start);
void NhapThemDocGia(ReaderList* list);
void ThemDocGia(ReaderList* readerList, Reader reader);
int ReaderInfoChangeOption();
void ReaderInfoChanging(ReaderList* list);
void UserFindReaderByName(ReaderList *list);
void UserFindReaderByID(ReaderList *list);