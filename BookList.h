#pragma once
#include "BookNode.h"

struct BookList {
    BookNode *head;
    BookNode *tail;
    BookList();
};

void DanhSachCacSachTrongThuVien(BookList *bookList);