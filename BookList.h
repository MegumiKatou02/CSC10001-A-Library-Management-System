#pragma once
#include "BookNode.h"

struct BookList {
    BookNode *head;
    BookNode *tail;
    BookList();
    ~BookList();
};

int SizeBook(BookList* list);
void FindAllBooksByName(BookList* list);
void DanhSachCacSachTrongThuVien(BookList *bookList);
void ThemSach(BookList *bookList, Book book);
void NhapThemSach(BookList *bookList);
void ChinhSuaThongTinSach(BookList *bookList);
int MenuChinhSuaThongTinSach();
BookNode *BookDuaTrenISBN(BookList *bookList, string ISBN);
BookNode *BookDuaTrenTenSach(BookList *bookList, string name);
void XoaThongTinSach(BookList *&bookList); // xoa cmn node luon (oke hay day anh ching <("))
void TimKiemSachTheoISBN(BookList *bookList);