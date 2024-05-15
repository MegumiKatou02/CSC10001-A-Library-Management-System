#pragma once
#include <fstream>
#include <string>
#include "BookList.h"
#include "ReaderList.h"

void WriteReaderToFile(ReaderList* list);
void WriteBooksToFile(BookList* list);

void InputBooksFromFile(BookList* list);
void InputReaderFromFile(ReaderList* list);