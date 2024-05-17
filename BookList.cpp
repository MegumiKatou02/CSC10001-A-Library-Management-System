#include "BookList.h"

BookList::BookList() {
    head = tail = nullptr;
}

BookList::~BookList() {
    while(this->head != nullptr) {
        BookNode *current = head;
        head = head->next;
        delete current;
    }
}

int SizeBook(BookList* list) {
    int count = 0;
    BookNode* current = list->head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void DanhSachCacSachTrongThuVien(BookList *bookList) {
    if(bookList->head == nullptr) {
        cout << "Thu vien chua co sach !\n";
        return;
    }
    BookNode *current = bookList->head;
    while(current != nullptr) {
        ThongTinQuyenSach(current->book);
        cout << "\n";
        current = current->next;
    }
}

void ThemSach(BookList *bookList, Book book) {
    BookNode *bookNode = new BookNode(book);
    if(bookList->head == nullptr) {
        bookList->head = bookNode;
    }
    else {
        bookList->tail->next = bookNode;
    }
    bookList->tail = bookNode;
}

void NhapThemSach(BookList *bookList) {
    cout << "Nhap so luong sach can them: ";
    unsigned int size; cin >> size;
    for(int i = 1; i <= size; i++) {
        cout << "Nhap sach thu " << i << ": \n";
        Book book;
        cout << "Name: "; getline(cin >> ws, book.name);
        cout << "Author: "; getline(cin >> ws, book.author);
        cout << "Publisher: "; getline(cin >> ws, book.publisher);
        cout << "Year Publisher: "; cin >> book.yearPublish;
        cout << "Type: "; getline(cin >> ws, book.type);
        cout << "Price: "; cin >> book.price;
        cout << "Number: "; cin >> book.number;
        book.ISBN = EncodeBookCode(book);
        ThemSach(bookList, book); cout << "\n";
    }
}

int MenuChinhSuaThongTinSach() {
    cout << "1. Chinh sua ten sach\n";
    cout << "2. Chinh sua tac gia\n";
    cout << "3. Chinh sua nha xuat ban\n";
    cout << "4. Chinh sua nam xuat ban\n";
    cout << "5. Chinh sua the loai\n";
    cout << "6. Chinh sua gia sach\n";
    cout << "7. Chinh sua chinh sua so quyen sach\n";
    cout << "8. Thoat\n";
    // xu ly lenh cua nguoi dung 
	int option;
	cin >> option;
	while (option < 1 || option > 8) {
		cout << "Lenh khong hop le, vui long nhap lai: ";
		cin >> option;
	}
    return option;
}

void ChinhSuaThongTinSach(BookList *bookList) {
    cout << "Nhap ISBN de chinh sua: ";
    string ISBN; cin >> ISBN;
    BookNode *bookNode = BookDuaTrenISBN(bookList, ISBN);
    if(bookNode == nullptr || bookNode->book.ISBN != ISBN) {
        cout << "ISBN khong ton tai hoac khong dung dinh dang !\n";
        return;
    }
    int option; bool loop = true;
    while(loop) {
        option = MenuChinhSuaThongTinSach();
        switch(option) {
        case 1: {
            cout << "Ten sach: " << bookNode->book.name << "\n";
            cout << "Nhap ten sach muon thay doi: ";
            string name; getline(cin >> ws, name);
            bookNode->book.name = name;
            break;
        }
        case 2: {
            cout << "Ten tac gia: " << bookNode->book.author << "\n";
            cout << "Nhap ten tac gia muon thay doi: ";
            string author; getline(cin >> ws, author);
            bookNode->book.author = author;
            break;
        }
        case 3: {
            cout << "Ten nha xuat ban: " << bookNode->book.publisher << "\n";
            cout << "Nhap ten nha xuat ban muon thay doi: ";
            string publisher; getline(cin >> ws, publisher);
            bookNode->book.publisher = publisher;
            break;
        }
        case 4: {
            cout << "Nam xuat ban: " << bookNode->book.yearPublish << "\n";
            cout << "Nhap nam xuat ban muon thay doi: ";
            int yearPublish; cin >> yearPublish;
            bookNode->book.yearPublish = yearPublish;
            break;
        }
        case 5: {
            cout << "Ten the loai: " << bookNode->book.type << "\n";
            cout << "Nhap ten the loai muon thay doi: ";
            string type; getline(cin >> ws, type);
            bookNode->book.type = type;
            break;
        }
        case 6: {
            cout << "Gia sach: " << bookNode->book.price << "\n";
            cout << "Nhap gia sach muon thay doi: ";
            double price; cin >> price;
            bookNode->book.price = price;
            break;
        }
        case 7: {
            cout << "So quyen sach: " << bookNode->book.number << "\n";
            cout << "Nhap so quyen sach muon thay doi: ";
            int number; cin >> number;
            bookNode->book.number = number;
            break;
        }
        case 8: loop = false; break;
        }
    }
}

BookNode *BookDuaTrenISBN(BookList *bookList, string ISBN) {
    BookNode *current = bookList->head;
    while(current != nullptr && current->book.ISBN != ISBN) {
        current = current->next;
    }
    return current;
}

BookNode *BookDuaTrenTenSach(BookList *bookList, string name) {
    BookNode *current = bookList->head;
    while(current != nullptr && current->book.name != name) {
        current = current->next;
    }
    return current;
}

void XoaThongTinSach(BookList *&bookList) {
    cout << "Nhap ISBN de xoa thong tin: ";
    string ISBN; cin >> ISBN;
    BookNode *bookNode = BookDuaTrenISBN(bookList, ISBN);
    if(bookNode == nullptr) {
        cout << "ISBN khong ton tai hoac khong dung dinh dang !\n";
        return;
    }
    BookNode *current = bookList->head;
    BookNode *previous = nullptr;
    while(current != nullptr && current->book.ISBN != ISBN) {
        previous = current;
        current = current->next;
    }
    if(current == nullptr) {
        cout << "ISBN khong ton tai\n";
        return;
    }
    if(previous == nullptr) {
        bookList->head = current->next;
    }
    else {
        previous->next = current->next;
    }
    delete current;
    cout << "Xoa thanh cong thong tin sach <(\")\n";
}

void TimKiemSachTheoISBN(BookList *bookList) {
    cout << "Nhap ISBN de tim kiem: ";
    string ISBN; cin >> ISBN;
    BookNode *bookNode = BookDuaTrenISBN(bookList, ISBN);
    if(bookNode == nullptr) {
        cout << "ISBN khong ton tai hoac khong dung dinh dang !\n";
        return;
    }
    ThongTinQuyenSach(bookNode->book);
}

void FindAllBooksByName(BookList* list) {
    cout << "Nhap ten sach cua cuon sach can tim: ";
    string bookName; getline(cin >> ws, bookName);
    BookNode* curBook = list->head;
    bool found = false;
    for (curBook; curBook != NULL; curBook = curBook->next) {
        if (curBook->book.name == bookName) {
            if (!found) {
                cout << "Cac quyen sach co ten tuong ung la: \n";
            }
            ThongTinQuyenSach(curBook->book); cout << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co cuon sach nao trong thu vien co ten tuong ung!\n";
    }
}