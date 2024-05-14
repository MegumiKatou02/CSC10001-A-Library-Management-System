#include "Reader.h"



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

Date UpdateEndDay(Date start) {
    
    Date end;
    
    // truong hop lam the vao ngay 29/2: cong them 1 ngay (het han vao 1/3) (ranh that)
    if (start.day == 29 && start.month == 2 && ((start.year % 4 == 0 && start.year % 100 != 0) || (start.year % 400 == 0))) {
        end.day = 1; end.month = start.month + 1; end.year = start.year + 2;
    }
    else {
        end.day = start.day;
        end.month = start.month;
        end.year = start.year + 2; // het han vao 2 nam sau
    }
    return end;
}


void NhapThemDocGia(ReaderList* list) {
    while (1) {
        Reader reader;
        cout << "nhap thong tin nguoi doc moi: " << endl;
        // randomcode hoc cua anh ching sau nhe
        cout << "nhap ten: "; cin.getline(reader.name, 19);
        cout << "Nhap ID: "; cin.getline(reader.ID, 19);
        cout << "Nhap gioi tinh: \n1. Nam \n2. Nu \n 3. Khac"; cin >> reader.gender;
        cout << "nhap email: "; cin.getline(reader.email, 19);
        cout << "nhap thong tin the thu vien: " << endl;
        cout << "nhap ngay dang ky: "; cin >> reader.startDay.day;
        cout << "nhap thang dang ky: "; cin >> reader.startDay.month;
        cout << "nhap nam dang ky: "; cin >> reader.startDay.year;
        UpdateEndDay(reader.startDay);

        ThemDocGia(list, reader);

        char ch;
        cout << "ban muon nhap them doc gia khac khong? (y/n)";
        cin.get(ch);
        while (toupper(ch) != 'Y' || toupper(ch) != 'N') {
            cout << "vui long nhap y hoac n.";
            cin.get(ch);
            cin.ignore();
        }
        if (toupper(ch) == 'N')
            return;
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

ReaderNode* FindByName(ReaderList* list, char name[]) {
    ReaderNode* curReader = list->head;
    while (curReader != NULL && strcmp(curReader->reader.name, name) == 0) {
        curReader = curReader->next;
    }
    return curReader;
}

ReaderNode* FindByID(ReaderList* list, char ID[]) {
    ReaderNode* curReader = list->head;
    while (curReader != NULL && strcmp(curReader->reader.ID, ID) == 0) {
        curReader = curReader->next;
    }
    return curReader;
}


int ReaderInfoChangeOption() {
    cout << "     1. Thay doi ho ten doc gia" << endl;
    cout << "     2. Thay doi dia chi email" << endl;
    cout << "     3. Chinh sua ma so sinh vien: " << endl;
    cout << "     4. Thay doi gioi tinh: " << endl;
    cout << "     5. Thay doi dia chi thuong tru: " << endl;
    cout << "Nhap vao lua chon muon thay doi: ";
    int option; cin >> option;
    while (option < 1 || option > 6) {
        cout << "Lenh nhap vao khong hop le, vui long nhap lai: ";
        cin >> option;
    }
    return option;
}

void ReaderInfoChanging(ReaderList* list) {
    cout << "Nhap ten doc gia can chinh sua thong tin: ";
    char name[20]; cin.getline(name, 19);
    ReaderNode* fReader = FindByName(list, name);
    if (fReader == NULL || strcmp(fReader->reader.name, name) != 0) {
        cout << "Ten doc gia nhap vao khong ton tai hoac chua duoc dang ky!";
        return;
    }
    while (1) {
        int option = ReaderInfoChangeOption();
        switch (option) {
        case 1: {
            char newName[20];
            cout << "Nhap vao ho ten moi cua doc gia: ";
            cin.getline(newName, 19);
            strcpy(fReader->reader.name, newName);
            break;
        }
        case 2: {
            cout << "Nhap vao dia chi email moi: ";
            char newEmail[20]; cin.getline(newEmail, 19);
            strcpy(fReader->reader.email, newEmail);
            break;
        }
        case 3: {
            cout << "Nhap ma so sinh vien moi cua doc gia: ";
            char newID[12]; cin.getline(newID, 11);
            strcpy(fReader->reader.ID, newID);
            break;
        }
        case 4: {
            cout << "Chon gioi tinh cua ban <(\"): " << endl;
            cout << " 1. Nam" << endl << " 2. Nu" << endl << " 3. Linh hoat " << endl << " 4. Khong xac dinh" << endl;
            int newGender; cin >> newGender;
            while (newGender < 1 || newGender > 4) {
                cout << "Lenh khong hop le. Vui long nhap lai.";
                cin >> newGender;
            }
            fReader->reader.gender = newGender;
        }
        case 5: {
            cout << "Nhap dia chi moi cua doc gia: ";
            char newAddress[36]; cin.getline(newAddress, 35);
            strcpy(fReader->reader.address, newAddress);
            break;
        }
    }
        
        char ch;
        cout << "ban muon tiep tuc chinh sua thong tin khong? (y/n)";
        cin.get(ch);
        while (toupper(ch) != 'Y' || toupper(ch) != 'N') {
            cout << "vui long nhap y hoac n.";
            cin.get(ch);
            cin.ignore();
        }
        if (toupper(ch) == 'N')
            return;
    }
}