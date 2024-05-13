#include "Book.h"

void ThongTinQuyenSach(Book book) {
    cout << "     ISBN: " << book.ISBN << "\n";
    cout << "     Name: " << book.name << "\n";
    cout << "     Author: " << book.author << "\n";
    cout << "     Publisher: " << book.publisher << "\n";
    cout << "     Year Publisher: " << book.yearPublish << "\n";
    cout << "     Type: " << book.type << "\n";
    cout << "     Price: " << book.price << "\n";
    cout << "     Number: " << book.number << "\n";
}

int HashCodeBook(Book book) {
    srand(time(nullptr));
    int yearCode = book.yearPublish % 100;
    int price = ((yearCode) / 10 != 0) ? yearCode : (rand() % 9 + 0) * 10 + book.yearPublish % 10;
}
