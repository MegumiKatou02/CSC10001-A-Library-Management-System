#pragma once
#include "ReaderList.h"
#include "BookList.h"
#include <vector>
#include <map>
using namespace std;

// cac ham thong ke sach
void BookStatisticize(BookList* list);
void BookTypeStatisticize(BookList* list);

// cac ham thong ke doc gia
void ReaderStatisticize(ReaderList* list);
void ReaderStactisticizeByGender(ReaderList* list);

// thong ke sach muon, tra, tre han
void BorrowedBookStatisticize(ReaderList* readerList);