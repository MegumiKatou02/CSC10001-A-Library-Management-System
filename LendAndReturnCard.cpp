#include "LendAndReturnCard.h"

void LapPhieuTraSach(ReaderList *readerList) {
    cout << "Nhap ten hoac id: ";
    string undefine;
    getline(cin >> ws, undefine);
    ReaderNode *readerNode = FindByNameOrID(readerList, undefine);
    if(readerNode == nullptr) {
        cout << "sai\n";
        return;
    }
    Reader reader = readerNode->reader;
    cout << reader.ID << "\n";
    cout << reader.name << "\n";
    cout << reader.code << "\n\n";
    LendCardNode *current = reader.lendCardList->head;
    while(current != nullptr) {
        LendCard lendCard = current->lendCard;
        cout << lendCard.borrowDate.day << " - " << lendCard.borrowDate.month << " - " << lendCard.borrowDate.year << "\n"; 
        cout << "\n";
        BookNode *bookNode = lendCard.borrowBookList->head;
        while(bookNode != nullptr) {
            ThongTinQuyenSach(bookNode->book);
            cout << "\n";
        }
        current = current->next;
    }

}

void LapPhieuMuonSach(ReaderList *readerList, BookList *bookList) {
    cout << "Nhap ma doc gia hoac ten doc gia muon lap phieu:\n";
    string undefinedTypeDate;
    getline(cin >> ws, undefinedTypeDate);
    ReaderNode *readerNode = FindByNameOrID(readerList, undefinedTypeDate);
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
        InputAddLendCard(readerNode->reader.lendCardList);
        cout << "Nhap so luong sach muon muon cua sach \"" << bookNode->book.name << "\"\n";
        unsigned int bookNumber; cin >> bookNumber;
        if(bookNumber > bookNode->book.number) {
            unsigned int leftBook = bookNumber - bookNode->book.number;
            cout << "So luong sach vuot qua gioi han nen chi muon duoc muon " << leftBook << " quyen \n"; 
            bookNode->book.number = 0;
        }
        bookNode->book.number = bookNumber - bookNode->book.number;
        cout << "\n";
    }
}
