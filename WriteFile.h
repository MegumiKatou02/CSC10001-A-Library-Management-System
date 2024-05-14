#pragma once
#include <fstream>
#include "BookList.h"
#include "ReaderList.h"

void WriteReaderToFile(ReaderList* list);
void WriteBooksToFile(BookList* list);

