#include "Statistic.h"

void BookStatisticize(BookList* list) {
	BookNode* curBook = list->head;
	int num = 0, numDiffer = 0;
	while (curBook != NULL) {
		num += curBook->book.number;
		numDiffer++;
		curBook = curBook->next;
	}
	cout << "Thong ke sach trong thu vien: " << endl;
	cout << "Tong so luong sach hien tai: " << num << " quyen sach." << endl;
	cout << "Tong so luong sach khac nhau: " << numDiffer << " quyen sach." << endl;
}

void BookTypeStatisticize(BookList* list) {
	int num = SizeBook(list);
	map <string, int> mymap;
	BookNode* curBook = list->head;
	while (curBook != NULL) {
		mymap[curBook->book.type]++;
	}
	cout << "Cac the loai sach tuong ung: ";
	for (const pair<string, int> m : mymap) {
		cout << m.first << " " << m.second << " ";
	}
}

void ReaderStatisticize(ReaderList* list) {
	ReaderNode* curReader = list->head;
	int num = 0;
	while (curReader != NULL) {
		num++;
		curReader = curReader->next;
	}
	cout << "Tong so luong doc gia la: " << num << " doc gia." << endl;
}

void ReaderStatisticizeByGender(ReaderList* list) {
	ReaderNode* curReader = list->head;
	int nam = 0, nu = 0, khongxacdinh = 0, khac = 0;
	while (curReader != NULL) {
		switch (curReader->reader.gender) {
		case 1: nam++; break;
		case 2: nu++; break;
		case 3: khac++; break;
		case 4: khongxacdinh++; break;
		}
		curReader = curReader->next;
	}
	cout << "Thong ke doc gia theo gioi tinh: " << endl;
	cout << nam << " doc gia co gioi tinh nam." << endl;
	cout << nu << " doc gia co gioi tinh nu." << endl;
	cout << khongxacdinh << " doc gia khong xac dinh duoc gioi tinh." << endl;
	cout << khac << " doc gia khac." << endl;
}