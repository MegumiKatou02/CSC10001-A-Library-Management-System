#pragma once
#include "Reader.h"

struct ReaderNode {
	Reader reader;
	ReaderNode* next;

};
struct ReaderList {
	ReaderNode* head;
	ReaderNode* tail;
};



