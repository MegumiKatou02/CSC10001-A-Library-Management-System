#pragma once
#include <fstream>
#include <string>
#include "BookList.h"
#include "ReaderList.h"
#include "ultilty.h"

void WriteReaderToFile(ReaderList* list);
void WriteBooksToFile(BookList* list);

void InputReaderFromFile(ReaderList* list);