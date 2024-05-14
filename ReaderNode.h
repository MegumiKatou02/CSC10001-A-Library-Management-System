#pragma once
#include "Reader.h"

struct ReaderNode {
	Reader reader;
	ReaderNode* next;
	ReaderNode(Reader reader);
};