#include "LendCardList.h"

LendCardList::LendCardList() {
    head = tail = nullptr;
}

LendCardList::~LendCardList() {
   while(head != nullptr) {
       LendCardNode *current = head;
       head = head->next;
       delete current;
   }
}

void AddLendCard(LendCardList *list, LendCard lendCard) {
    LendCardNode *node = new LendCardNode(lendCard);
    if(list->head == nullptr) {
        list->head = node;
    }
    else {
        list->tail->next = node;
    }
    list->tail = node;
}

void InputAddLendCard(LendCardList *list) {
    LendCard lendCard;
    cout << "Nhap ngay muon sach: ";
    cin >> lendCard.borrowDate.day;
    cout << "Nhap thang muon sach: ";
    cin >> lendCard.borrowDate.month;
    cout << "Nhap nam muon sach: ";
    cin >> lendCard.borrowDate.year;
    AddLendCard(list, lendCard);
}