#include "WriteFile.h"
#include <string>
void WriteReaderToFile(ReaderList* list) {
	ofstream ofs;
	ofs.open("Readers.txt", ios::out || ios::app);
	if (!ofs) {
		cout << "khong the mo file Readers.txt!";
		return;
	}
	ReaderNode* reader = list->head;
	int n = 0;
	while (reader != NULL) {
		ofs << reader->reader.code << ",";
		ofs << reader->reader.name << ",";
		ofs << reader->reader.ID << ",";
		ofs << reader->reader.gender << ",";
		ofs << reader->reader.email << ",";
		ofs << reader->reader.address << ",";
		ofs << reader->reader.startDay.day << "," << reader->reader.startDay.month << "," << reader->reader.startDay.year << ",";
		ofs << reader->reader.endDay.day << "," << reader->reader.endDay.month << "," << reader->reader.endDay.year << ",";
		reader = reader->next;
		n++; // dem so doc gia them vao file
	}
	ofs << n; // ghi vao cuoi file
	ofs.close();
}

void InputReaderFromFile(ReaderList* list) {
	ifstream ifs;
	ifs.open("Readers.txt", ios::in);
	if (!ifs) {
		cout << "khong the mo file Readers.txt!";
		return;
	}
	int num;
	ifs.seekg(-1, ios::end);
	ifs >> num; // doc so luong doc gia
	ifs.seekg(0, ios::beg);
	for (int i = 0; i < num; i++) {
		Reader reader;
		string temp;
		getline(ifs, reader.code, ',');
		getline(ifs, reader.name, ',');
		getline(ifs, reader.ID, ','); 
		getline(ifs, temp, ',');
		reader.gender = stoi(temp);
		
		getline(ifs, reader.email, ',');

		getline(ifs, reader.address, ',');

		getline(ifs, temp, ',');
		reader.startDay.day = stoi(temp);

		getline(ifs, temp, ',');
		reader.startDay.month = stoi(temp);

		getline(ifs, temp, ',');
		reader.startDay.year = stoi(temp);

		getline(ifs, temp, ',');
		reader.endDay.day = stoi(temp);

		getline(ifs, temp, ',');
		reader.endDay.month = stoi(temp);

		getline(ifs, temp, ',');

		reader.endDay.year = stoi(temp);
		ThemDocGia(list, reader);
	}
	ifs.close();
}

void WriteBooksToFile(BookList* list) {
	ofstream ofs;
	ofs.open("Books.txt");
	if (!ofs) {
		cout << "khong the mo file Books.txt!";
		return;
	}
	BookNode* curBook = list->head;
	while (curBook != NULL) {
		ofs << curBook->book.ISBN << ",";
		ofs << curBook->book.name << ",";
		ofs << curBook->book.author << ",";
		ofs << curBook->book.publisher << ",";
		ofs << curBook->book.yearPublish << ",";
		ofs << curBook->book.type << ",";
		ofs << curBook->book.price << ",";
		ofs << curBook->book.number << endl;
		curBook = curBook->next;
	}
	ofs.close();
}