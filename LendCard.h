#pragma once
#include "Reader.h"
#include "BookList.h"

struct LendCard {
	Reader borrower; // hoac la char code[] roi so sanh voi code cua nguoi doc
	Date borrowDate;
	Date returnDate; // ngay tra du kien
	BookList *borrowBookList;
	LendCard();
	~LendCard();
};
