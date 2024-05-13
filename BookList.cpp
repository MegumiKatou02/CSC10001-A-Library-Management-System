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

void ThemSach(BookList *bookList, Book book) {
    BookNode *bookNode = new BookNode(book);
    if(bookList->head == nullptr) {
        bookList->head = bookNode;
    }
    else {
        bookList->tail->next = bookNode;
    }
    bookList->tail = bookNode;
}

void NhapThemSach(BookList *bookList) {
    cout << "Nhap so luong sach can them: ";
    unsigned int size; cin >> size;
    for(int i = 1; i <= size; i++) {
        cout << "Nhap sach thu " << i << ": \n";
        Book book;
        cout << "Name: "; getline(cin >> ws, book.name);
        cout << "Author: "; getline(cin >> ws, book.author);
        cout << "Publisher: "; getline(cin >> ws, book.publisher);
        cout << "Year Publisher: "; cin >> book.yearPublish;
        cout << "Type: "; getline(cin >> ws, book.type);
        cout << "Price: "; cin >> book.price;
        cout << "Number: "; cin >> book.number;
        book.ISBN = EncodeBookCode(book);
        ThemSach(bookList, book); cout << "\n";
    }
}

void ChinhSuaThongTinSach(BookList *bookList) {
    
}