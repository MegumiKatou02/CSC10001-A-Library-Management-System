#include "WriteFile.h"

void WriteReaderToFile(ReaderList* list) {
	ofstream ofs;
	ofs.open("Readers.txt", ios::out || ios::app);
	if (!ofs) {
		cout << "khong the mo file Readers.txt!";
		return;
	}
	ReaderNode* reader = list->head;
	while (reader != NULL) {
		ofs << reader->reader.code << ",";
		ofs << reader->reader.name << ",";
		ofs << reader->reader.ID << ",";
		ofs << reader->reader.gender << ",";
		ofs << reader->reader.email << ",";
		ofs << reader->reader.address << ",";
		ofs << reader->reader.startDay.day << "/" << reader->reader.startDay.month << "/" << reader->reader.startDay.year << ",";
		ofs << reader->reader.endDay.day << "/" << reader->reader.endDay.month << "/" << reader->reader.endDay.year << "\n";
		reader = reader->next;
	}
	ofs.close();
}


void WriteBooksToFile(BookList* list) {
	ofstream ofs;
	ofs.open("BookShelf.txt", ios::out || ios::app);
	if (!ofs) {
		cout << "khong the mo file books.txt!";
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