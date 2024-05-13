#include "Reader.h"


//struct Reader {
//    char code[12];
//    char name[20];
//    char ID[12];
//    int gender;
//    // 1: male, 2: female, 3: other, 0: undefined
//    char email[20];
//    char address[36];
//    Date startDay;
//    Date endDay;
//};

void ThongTinDocGia(Reader reader) {
    cout << "     Member's code: " << reader.code << endl;
    cout << "     Name: " << reader.name << endl;
    cout << "     ID: " << reader.ID << endl;
    cout << "     gender: ";
    switch (reader.gender) {
    case 1: cout << "male"; break;
    case 2: cout << "female"; break;
    case 3: cout << "other"; break;
    case 4: cout << "undefined"; break;
    }
    cout << endl;

    cout << "     Email: " << reader.email << endl;
    cout << "     Address " << reader.address << endl;
    cout << "     Start Date: " << reader.startDay.day << "/" << reader.startDay.month << "/" << reader.startDay.year << endl;
    cout << "     End Date: " << reader.endDay.day << "/" << reader.endDay.month << "/" << reader.endDay.year << endl;
}

void DanhSachDocGia(ReaderList* readerList) {
    if (readerList->head == NULL) {
        cout << "Thu vien chua co doc gia dang ky.";
        return;
    }
    int number = 1;
    ReaderNode* curReader = readerList->head;
    while (curReader != NULL) {
        cout << "Doc gia thu " << number << ": \n";
        ThongTinDocGia(curReader->reader);
        curReader = curReader->next;
        number++;
    }
}

void NhapThemDocGia(ReaderList* list) {
    while (1) {
        Reader reader;
        cout << "nhap thong tin nguoi doc moi: " << endl;
        // randomcode hoc cua anh ching sau nhe
        cout << "nhap ten: "; cin.getline(reader.name, 19);
        cout << "Nhap ID: "; cin.getline(reader.ID, 19);
        cout << "Nhap gioi tinh:"; // tinh sau;
        cout << "nhap email: "; 

    }
}

void ThemDocGia(ReaderList* readerList, Reader reader) {
    ReaderNode* newReader = new ReaderNode;
    newReader->reader = reader;
    if (readerList->head == NULL) {
        readerList->head = newReader;
    }
    else {
        readerList->tail->next = newReader;
    }
    readerList->tail = newReader;
    readerList->tail->next = NULL;
}
