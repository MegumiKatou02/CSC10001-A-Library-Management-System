#pragma once
#include "LendCard.h"

struct LendCardNode {
    LendCard lendCard;
    LendCardNode *next;
    LendCardNode(LendCard lendCard);
};