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
		curBook = curBook->next;
	}
	cout << "Cac the loai sach tuong ung: \n";
	for (const pair<string, int> m : mymap) {
		cout << m.first << " " << m.second << "\n";
	}
}

void ReaderStatisticize(ReaderList* list) {
	ReaderNode* curReader = list->head;
	int num = 0;
	while (curReader != NULL) {
		num++;
		curReader = curReader->next;
	}
	cout << "Tong so luong doc gia la: " << num << endl;
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

void BorrowedBookStatisticize(ReaderList* readerList) {
	ReaderNode *readerNode = readerList->head;
	int number = 0;
	while(readerNode != nullptr) {
		Reader reader = readerNode->reader;
		for(const LendCard &lendCard : reader.lendCards) {
			number += lendCard.number;
		}
		readerNode = readerNode->next;
	}
	cout << "So sach dang duoc muon: " << number << "\n";
}

void LateReturnerStatisticize(ReaderList *readerList) {
	cout << "Danh sach doc gia bi tre han:\n";
	if(lateReturnerStatisticizeNumber.size() == 0) {
		cout << "Khong ai ca !\n";
		return;
	}
	for(const string &lateRetuner : lateReturnerStatisticizeNumber) {
		cout << lateRetuner << "\n";
	}
}

void InserLateReturner(string nameReturner) {
	lateReturnerStatisticizeNumber.insert(nameReturner);
};