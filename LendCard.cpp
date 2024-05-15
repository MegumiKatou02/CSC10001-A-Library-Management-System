#include "LendCard.h"

LendCard::LendCard() {
    this->codeBorrower = "";
    borrowBookList = new BookList();
}

LendCard::~LendCard() {
    while(borrowBookList->head != nullptr) {
        BookNode *current = borrowBookList->head;
        borrowBookList->head = borrowBookList->head->next;
        delete current;
    }
    if(borrowBookList != nullptr)
        delete borrowBookList;
}
