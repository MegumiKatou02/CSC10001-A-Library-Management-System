#include "BookNode.h"

BookNode::BookNode(Book book) {
    this->book = book;
    this->next = nullptr;
}