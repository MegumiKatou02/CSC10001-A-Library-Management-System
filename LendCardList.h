#pragma once
#include "LendCardNode.h"

struct LendCardList {
    LendCardNode *head;
    LendCardNode *tail;
    LendCardList();
    ~LendCardList();
};