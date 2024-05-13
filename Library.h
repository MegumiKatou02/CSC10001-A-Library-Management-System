#pragma once
#include <iostream>		
#include <algorithm>
#include <string>	// ho, ten doc gia
#include <fstream> // luu tru thong tin len file
using namespace std;
#define MAX 5

struct date {
	int day, month, year;
};

struct reader {
	char code[12];
	char name[20];
	char ID[12];
	int gender; 
		// 1: male, 2: female, 3: other, 0: undefined
	char email[20];
	char address[36];
	date startDay;
	date endDay;
};

struct book {
	char ISBN[16];
	char name[24];
	char author[20];
	char publisher[20];
	int yearPublish;
	char type[16];
	double price;
	int number;
};

struct lendCard {
	reader borrower; // hoac la char code[] roi so sanh voi code cua nguoi doc
	date borrowDate;
	date returnDate;
	book bookBorrow[MAX]; // gia su 1 phieu muon gom nhieu nhat 5 quyen sach

	int penalty; // tien phat 
};


// cai nay tinh sau nhe
struct bookNode {
	book sach;
	bookNode* next;
};

struct bookList {
	bookNode* head;
	bookNode* tail;
};

// cac ham xu ly cac lua chon cua nguoi dung:
// int main_menu();
// void lap_phieu_mua_sach();
// void lap_phieu_tra_sach();
// void thong_ke();
