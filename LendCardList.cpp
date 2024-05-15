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