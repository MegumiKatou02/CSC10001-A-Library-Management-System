#include "ReaderNode.h"

ReaderNode::ReaderNode(Reader reader) {
    this->reader = reader;
    this->next = NULL;
}

void InputAddLendCard(ReaderNode *readerNode, Book book) {
    LendCard lendCard;
    while(true) {
        cout << "Nhap ngay tra du kien: "; cin >> lendCard.returnDate.day;
        if(lendCard.returnDate.day == -1) {
            Date date = RealDate(); date++;
            lendCard.returnDate = date;
            break;
        }
        cout << "Nhap thang tra du kien: "; cin >> lendCard.returnDate.month;
        cout << "Nhap nam tra du kien: "; cin >> lendCard.returnDate.year;
        if(lendCard.returnDate < RealDate()) {
            cout << "Khong the nhap ngay tra du kien truoc ngay muon sach !\n";
            continue;
        }
        break;
    }
    lendCard.borrowBook = book;
    readerNode->reader.lendCards.push_back(lendCard);
}