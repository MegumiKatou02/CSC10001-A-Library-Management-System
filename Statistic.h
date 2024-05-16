#pragma once
#include "ReaderList.h"
#include "BookList.h"
#include <vector>
#include <map>
#include <set>
using namespace std;

// cac ham thong ke sach
void BookStatisticize(BookList* list);                      // a
void BookTypeStatisticize(BookList* list);                  // b

// cac ham thong ke doc gia
void ReaderStatisticize(ReaderList* list);                  //c
void ReaderStatisticizeByGender(ReaderList* list);          //d

// thong ke sach muon, tre han
void BorrowedBookStatisticize(ReaderList* readerList);      // e
void LateReturnerStatisticize(ReaderList *readerList);      // f

void InserLateReturner(string nameReturner);

static set<string> lateReturnerStatisticizeNumber;