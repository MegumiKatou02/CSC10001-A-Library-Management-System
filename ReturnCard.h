#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
#define MAX 5

struct ReturnCard {
	string readerCode;
	string ISBN[MAX];
	Date borrowDate;
	Date expectReDate;
	Date realReDate;
	bool exist; // doc gia co tra sach ve hay khong
	int penalty; // phat tien nhe

};