#pragma once
#include "ReaderList.h"
#include "BookList.h"
#include "Date.h"
#include "Statistic.h"

using namespace std;

void LapPhieuTraSach(ReaderList *readerList, BookList *bookList);

void LapPhieuMuonSach(ReaderList *readerList, BookList *bookList);

void TraSachVeThuVien(Reader &reader, BookList *bookList);