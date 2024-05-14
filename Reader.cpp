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
    case 4: default: cout << "underfined"; break;
    }
    cout << endl;

    cout << "     Email: " << reader.email << endl;
    cout << "     Address " << reader.address << endl;
    cout << "     Start Date: " << reader.startDay.day << "/" << reader.startDay.month << "/" << reader.startDay.year << endl;
    cout << "     End Date: " << reader.endDay.day << "/" << reader.endDay.month << "/" << reader.endDay.year << endl;
}

Reader::Reader()
{
    this->code = "";
}