#pragma once
#include "ReaderNode.h"

struct ReaderList {
	ReaderNode* head;
	ReaderNode* tail;
	ReaderList();
	~ReaderList();
};

void FindAllReadersWithName(ReaderList* list);
void DanhSachDocGia(ReaderList* readerList);
ReaderNode* FindByName(ReaderList* list, string name);
ReaderNode* FindByID(ReaderList* list, string ID);
Date UpdateEndDay(Date start);
void NhapThemDocGia(ReaderList* list);
void ThemDocGia(ReaderList *readerList, Reader reader);
int ReaderInfoChangeOption();
void ReaderInfoChanging(ReaderList* list);
void UserFindReaderByName(ReaderList *list);
void UserFindReaderByID(ReaderList* list);
int SizeReader(ReaderList *list);
void DeleteInformationReader(ReaderList *&list); 