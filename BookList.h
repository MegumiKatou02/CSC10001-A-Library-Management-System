#pragma once
#include "BookNode.h"

// using namespace std;

struct BookList {
    BookNode *head;
    BookNode *tail;
    BookList();
};

void DanhSachCacSachTrongThuVien(BookList *bookList);
void ThemSach(BookList *bookList, Book book);
void NhapThemSach(BookList *bookList);
void ChinhSuaThongTinSach(BookList *bookList);
int MenuChinhSuaThongTinSach();
BookNode *BookDuaTrenISBN(BookList *bookList, string ISBN);
BookNode *BookDuaTrenTenSach(BookList *bookList, string name);
void ThayTheSach(BookList *&bookList, BookNode *bookNode);
void XoaThongTinSach(BookList *&bookList); // xoa cmn node luon
void TimKiemSachTheoISBN(BookList *bookList);
void TimKiemSachTheoTenSach(BookList *bookList);