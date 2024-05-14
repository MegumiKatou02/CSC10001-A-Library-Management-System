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

int HashReaderCode(const string &s) {
    int hashValue = 0;
    for(const auto &ch : s) {
        hashValue = hashValue * 31 + static_cast<int>(ch);
    }
    return hashValue;
}
string EncodeReaderCode(Reader reader) {
    string input =  reader.name + reader.ID + to_string(reader.gender) + reader.email + 
        reader.address + to_string(reader.startDay.day + reader.startDay.month + reader.startDay.year);
    int hashValue = HashReaderCode(input);

    string code = HashSixDigitCodeR(hashValue);
    if(code[0] == '-') {
        srand(time(nullptr));
        code = to_string(rand() % 9 + 0) + code.substr(1);
    }
    return (code.length() > 6) ? code.substr(0, 6) : code;
}
string HashSixDigitCodeR(int num) {
    num = num % 1000000;
    string code = to_string(num);
    while (code.length() < 6) {
        code = "0" + code;
    }
    return code;
}