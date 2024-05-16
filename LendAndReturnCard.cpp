#include "LendAndReturnCard.h"

void LapPhieuTraSach(ReaderList *readerList, BookList *bookList) {
    cout << "Nhap ma doc gia muon trar phieu:\n";
    string ID; cin >> ID;
    ReaderNode *readerNode = FindByID(readerList, ID);
    if(readerNode == nullptr) {
        cout << "Ma doc gia khong hop le !\n";
        return;
    }
    Reader reader = readerNode->reader;
    if(reader.lendCards.empty()) {
        cout << "Doc gia chua muon sach nao trong thu vien\n";
        return;
    }
    ThongTinDocGia(reader);
    cout << "\nNhung sach da muon:\n";
    srand(time(nullptr));
    for(LendCard &lendCard : reader.lendCards) {
        cout << "ISBN: " << lendCard.borrowBook.ISBN << "\n";
        cout << "Ten sach: " << lendCard.borrowBook.name << "\n";
        cout << "So quyen sach da muon: " << lendCard.borrowBook.number << " quyen\n";
        cout << "Ngay muon sach: " << RealDate() << "\n";
        lendCard.borrowDate = RealDate();
        cout << "Ngay tra du kien: " << lendCard.returnDate << "\n";
        int seed = rand() % 20 + 1;
        Date realReturnDate = addDays(lendCard.borrowDate, seed);
        Date standardDate = addDays(lendCard.borrowDate, 7); // ngay gioi han tra sach
        cout << "Ngay tra thuc te: " << realReturnDate << "\n";
        int penalty = 0;
        if(realReturnDate > standardDate) {
            penalty = DaysCalculate(standardDate, realReturnDate) * 5000;
        }
        //
        bool existed = realReturnDate > addDays(lendCard.borrowDate, 18);
        //
        Book book = lendCard.borrowBook;
        double moneyHaveToPay = book.price * book.number + penalty;
        if(existed) {
            penalty = 0;
            moneyHaveToPay = 2 * book.price * book.number;
        }
        cout << "So tien phai tra: " << moneyHaveToPay << "vnd ";
        if(existed) {
            cout << "(mat sach)\n";
        }
        else if(penalty != 0) {
            cout << "(tien phat: " << penalty << ")\n";
        }
        else cout << "\n";
        cout << "\n";
    }
    TraSachVeThuVien(readerNode->reader, bookList);
}

void LapPhieuMuonSach(ReaderList *readerList, BookList *bookList) {
    cout << "Nhap ma doc gia muon lap phieu:\n";
    string ID; cin >> ID;
    ReaderNode *readerNode = FindByID(readerList, ID);
    if(readerNode == nullptr) {
        cout << "Ma doc gia hoac ten doc gia khong hop le !\n";
        return;
    }
    if(readerNode->reader.endDay < RealDate()) {
        cout << "The cua doc gia da het han, khong the muon duoc sach\n";
        return;
    }
    cout << "Nhap so loai sach muon muon: ";
    unsigned int number; cin >> number;
    for(int i = 1; i <= number; i++) {
        cout << "Quyen sach thu " << i << ":\n";
        cout << "Nhap ISBN muon muon: ";
        string ISBN; cin >> ISBN;
        BookNode *bookNode = BookDuaTrenISBN(bookList, ISBN);
        if(bookNode == nullptr) {
            cout << "ISBN khong hop le !\n";
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
        else { 
           bookNode->book.number = bookNode->book.number - bookNumber;
        }
        int sizeLendCard = readerNode->reader.lendCards.size();
        readerNode->reader.lendCards[sizeLendCard - 1].number = bookNumber;
        cout << "Muon thanh cong "<< bookNumber << " quyen " << "!\n";
        cout << "\n";
    }
}
void TraSachVeThuVien(Reader &reader, BookList *bookList) {
    for(LendCard &lendCard : reader.lendCards) {
        int number = lendCard.borrowBook.number;
        string ISBN = lendCard.borrowBook.ISBN;
        BookNode *bookNode = BookDuaTrenISBN(bookList, ISBN);
        bookNode->book.number += number;
    }
    reader.lendCards.clear();
    reader.lendCards.shrink_to_fit();
    reader.lendCards.resize(0);
}