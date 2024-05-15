#pragma once
#include "BookList.h"
#include "Date.h"

struct LendCard {
	string codeBorrower; // hoac la char code[] roi so sanh voi code cua nguoi doc
	Date borrowDate;
	Date returnDate; // ngay tra du kien
	BookList *borrowBookList;
	LendCard();
	~LendCard();
};