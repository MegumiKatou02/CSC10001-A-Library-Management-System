#include "ReaderNode.h"

ReaderNode::ReaderNode(Reader reader) {
    this->reader = reader;
    this->next = NULL;
}

void InputAddLendCard(ReaderNode *readerNode, Book book) {
    LendCard lendCard;
    cout << "Nhap ngay muon: "; cin >> lendCard.borrowDate.day;
    cout << "Nhap thang muon: "; cin >> lendCard.borrowDate.month;
    cout << "Nhap nam muon: "; cin >> lendCard.borrowDate.year;
    lendCard.borrowBook = book;
    readerNode->reader.lendCards.push_back(lendCard);
}