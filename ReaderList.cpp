#include "ReaderList.h"
#include <string>

ReaderList::ReaderList() {
    head = tail = nullptr;
}

ReaderList::~ReaderList() {
    while(this->head != nullptr) {
        ReaderNode *current = head;
        head = head->next;
        delete current;
    }
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
    cout << "Nhap so luong doc gia can them: ";
    unsigned int num; cin >> num;
    for (int i = 0; i < num; i++) {
        Reader reader;
        cout << "nhap thong tin nguoi doc moi: " << endl;
        // randomcode hoc cua anh ching sau nhe - anh Ching lam roi nhe
        cout << "nhap ten: "; getline(cin >> ws, reader.name); reader.name = ChuanHoaTen(reader.name);
        cout << "Nhap ID: "; cin >> reader.ID;
        cout << "Nhap gioi tinh: \n1. Nam \n2. Nu \n3. Khac\n4. Khong xac dinh\n"; cin >> reader.gender;
        cout << "nhap email: "; cin >> reader.email;
        cout << "nhap dia chi: "; getline(cin >> ws, reader.address);
        cout << "nhap thong tin the thu vien: " << endl;
        cout << "nhap ngay dang ky: "; cin >> reader.startDay.day; 
        cout << "nhap thang dang ky: "; cin >> reader.startDay.month;
        cout << "nhap nam dang ky: "; cin >> reader.startDay.year; 
        reader.endDay = UpdateEndDay(reader.startDay); 
        reader.code = EncodeReaderCode(reader);

        ThemDocGia(list, reader);
        // cout << SizeReader(list) << " - size\n";  
        char ch;
        cout << "ban muon nhap them doc gia khac khong? (y/n): ";
        cin >> ch;      
        while (toupper(ch) != 'Y' && toupper(ch) != 'N') {
            cout << "vui long nhap y hoac n: ";
            cin >> ch;
        }
        if (toupper(ch) == 'N') {
            return;
        }
    }
}

void ThemDocGia(ReaderList *readerList, Reader reader) {
    ReaderNode* newReader = new ReaderNode(reader);
    if (readerList->head == NULL) {
        readerList->head = newReader;
    }
    else {
        readerList->tail->next = newReader;
    }
    readerList->tail = newReader;
}

ReaderNode* FindByName(ReaderList* list, string name) {
    ReaderNode* curReader = list->head;
    while (curReader != NULL && curReader->reader.name != name) {
        curReader = curReader->next;
    }
    return curReader;
}

ReaderNode* FindByID(ReaderList* list, string ID) {
    ReaderNode* curReader = list->head;
    while (curReader != NULL && curReader->reader.ID != ID) {
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
    string name; getline(cin >> ws, name);
    ReaderNode* fReader = FindByName(list, name);
    if (fReader == NULL || fReader->reader.name != name) {
        cout << "Ten doc gia nhap vao khong ton tai hoac chua duoc dang ky!";
        return;
    }
    while (1) {
        int option = ReaderInfoChangeOption();
        switch (option) {
        case 1: {
            string newName;
            cout << "Nhap vao ho ten moi cua doc gia: ";
            getline(cin >> ws, newName);
            fReader->reader.name = newName;
            break;
        }
        case 2: {
            cout << "Nhap vao dia chi email moi: ";
            string newEmail; cin >> newEmail;
            fReader->reader.email = newEmail;
            break;
        }
        case 3: {
            cout << "Nhap ma so sinh vien moi cua doc gia: ";
            string newID; cin >> newID;
            fReader->reader.ID = newID;
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
            break;
        }
        case 5: {
            cout << "Nhap dia chi moi cua doc gia: ";
            string newAddress; getline(cin >> ws, newAddress);
            fReader->reader.address = newAddress;
            break;
        }
        }

        char ch;
        cout << "ban muon tiep tuc chinh sua thong tin khong? (y/n)";
        cin >> ch;
        while (toupper(ch) != 'Y' && toupper(ch) != 'N') {
            cout << "vui long nhap y hoac n.";
            cin >> ch;
        }
        if (toupper(ch) == 'N')
            return;
    }
}

void UserFindReaderByName(ReaderList* list) {
    cout << "Nhap ten doc gia ban muon tim kiem: ";
    string fName; getline(cin >> ws, fName);
    ReaderNode* fNode = FindByName(list, fName);
    if (fNode == NULL) {
        cout << "Khong ton tai doc gia co ten trung khop voi ten da nhap!" << endl;
        return;
    }
    else {
        ThongTinDocGia(fNode->reader);
    }
}

void UserFindReaderByID(ReaderList* list) {
    cout << "Nhap ID cua doc gia ban can tim: ";
    string fID; cin >> fID;
    ReaderNode* fNode = FindByID(list, fID);
    if (fNode == NULL) {
        cout << "Khong ton tai doc gia co CMND trung khop voi CMND da nhap!" << endl;
        return;
    }
    else {
        ThongTinDocGia(fNode->reader);
    }
}

int SizeReader(ReaderList *list) 
{
    int count = 0;
    ReaderNode *current = list->head;
    while(current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void DeleteInformationReader(ReaderList *&list) {
    cout << "Nhap ID de xoa thong tin: ";
    string ID; cin >> ID;
    ReaderNode *readerNode = FindByID(list, ID);
    if(readerNode == nullptr) {
        cout << "ID khong ton tai hoac khong dung dinh dang !\n";
        return;
    }
    ReaderNode *current = list->head;
    ReaderNode *previous = nullptr;
    while(current != nullptr && current->reader.ID != ID) {
        previous = current;
        current = current->next;
    }
    if(current == nullptr) {
        cout << "ID khong ton tai\n";
        return;
    }
    if(previous == nullptr) {
        list->head = current->next;
    }
    else {
        previous->next = current->next;
    }
    delete current;
    cout << "Xoa thanh cong thong tin doc gia <(\")\n";
}

ReaderNode* FindByNameOrID(ReaderList *list, string undefineTypeData) {
    ReaderNode* curReader = list->head;
    while (curReader != nullptr && (curReader->reader.ID != undefineTypeData || 
                                curReader->reader.name != undefineTypeData)) {
        curReader = curReader->next;
    }
    return curReader;
}
