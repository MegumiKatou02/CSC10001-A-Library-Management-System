#pragma once
#include "Reader.h"
#include "Book.h"
#define MAX 5

struct lendCard {
	Reader borrower; // hoac la char code[] roi so sanh voi code cua nguoi doc
	Date borrowDate;
	Date returnDate;
	Book bookBorrow[MAX]; // gia su 1 phieu muon gom nhieu nhat 5 quyen sach

	int penalty; // tien phat 
};
