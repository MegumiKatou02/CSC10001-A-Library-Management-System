#include "ReaderNode.h"

ReaderNode::ReaderNode(Reader reader) {
    this->reader = reader;
    this->next = NULL;
}
