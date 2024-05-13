#include "BookList.h"

BookList::BookList() {
    head = tail = nullptr;
}

void DanhSachCacSachTrongThuVien(BookList *bookList) {
    if(bookList->head == nullptr) {
        cout << "Thu vien chua co sach !\n";
        return;
    }
    BookNode *current = bookList->head;
    while(current != nullptr) {
        ThongTinQuyenSach(current->book);
        cout << "\n";
        current = current->next;
    }
}