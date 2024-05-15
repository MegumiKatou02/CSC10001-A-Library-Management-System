#pragma once
#include "LendCardNode.h"

struct LendCardList {
    LendCardNode *head;
    LendCardNode *tail;
    LendCardList();
    ~LendCardList();
};

void AddLendCard(LendCardList *list, LendCard lendCard);

void InputAddLendCard(LendCardList *list);