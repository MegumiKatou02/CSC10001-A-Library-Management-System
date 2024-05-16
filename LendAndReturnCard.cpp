#include "LendAndReturnCard.h"

void LapPhieuTraSach(ReaderList *readerList) {
    cout << "Nhap ma doc gia hoac ten doc gia muon tra phieu:\n";
    string undefined; getline(cin >> ws, undefined);
    ReaderNode *readerNode = FindByNameOrID(readerList, undefined);
    if(readerNode == nullptr) {
        cout << "Ma doc gia hoac ten doc gia khong hop le !\n";
        return;
    }
    Reader reader = readerNode->reader;
    cout << reader.name << "\n";
    cout << reader.ID << "\n";
    for(const LendCard &lendCard : reader.lendCards) {
        ThongTinQuyenSach(lendCard.borrowBook);
        cout << "Ngay tra du kien: " << lendCard.borrowDate.day << "/" << lendCard.borrowDate.month << "/" << lendCard.borrowDate.year << "\n";
        cout << "\n";
    }
}

void LapPhieuMuonSach(ReaderList *readerList, BookList *bookList) {
    cout << "Nhap ma doc gia hoac ten doc gia muon lap phieu:\n";
    string undefined;
    getline(cin >> ws, undefined);
    ReaderNode *readerNode = FindByNameOrID(readerList, undefined);
    if(readerNode == nullptr) {
        cout << "Ma doc gia hoac ten doc gia khong hop le !\n";
        return;
    }
    cout << "Nhap so loai sach muon muon: ";
    unsigned int number; cin >> number;
    for(int i = 1; i <= number; i++) {
        cout << "Quyen sach thu " << i << ":\n";
        cout << "Nhap ISBN hoac ten sach muon muon: ";
        string bookUndefine;
        getline(cin >> ws, bookUndefine);
        BookNode *bookNode = FindByISBNOrName(bookList, bookUndefine);
        if(bookNode == nullptr) {
            cout << "ISBN hoac ten sach khong hop le !\n";
            continue;
        }
        InputAddLendCard(readerNode, bookNode->book);
        cout << "Nhap so luong sach muon muon cua sach \"" << bookNode->book.name << "\":\n";
        unsigned int bookNumber; cin >> bookNumber;
        if(bookNode->book.number == 0) {
            cout << "Sach nay trong thu vien da het\n";
            continue;
        }
        if(bookNumber > bookNode->book.number) {
            cout << "So luong sach vuot qua gioi han nen chi muon duoc muon " << bookNode->book.number << " quyen \n"; 
            bookNumber = bookNode->book.number;
            bookNode->book.number = 0;
        }
        else bookNode->book.number = bookNode->book.number - bookNumber;
        cout << "Muon thanh cong "<< bookNumber << " quyen " << "!\n";
        cout << "\n";
    }
}
