#pragma once
#include "Book.h"

using namespace std;

struct BookNode {
    Book book;
    BookNode *next;
    BookNode(Book book);
};