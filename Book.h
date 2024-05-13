#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Book {
    string ISBN;
	string name;
	string author;
	string publisher;
	int yearPublish;
	string type;
	double price;
	int number;
};

void ThongTinQuyenSach(Book book);
int HashCodeBook(Book book);