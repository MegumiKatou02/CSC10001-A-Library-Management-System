#pragma once
#include "Book.h"
#include "Date.h"

struct LendCard {
	string codeBorrower; // hoac la char code[] roi so sanh voi code cua nguoi doc
	Date borrowDate;
	Date returnDate; // ngay tra du kien
	Book borrowBook;
	int number;
	LendCard();
	~LendCard();
};