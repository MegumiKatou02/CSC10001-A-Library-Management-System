#include "Book.h"

Book::Book() {
    ISBN = "";
}

void ThongTinQuyenSach(Book book) {
    cout << "     ISBN: " << book.ISBN << "\n";
    cout << "     Name: " << book.name << "\n";
    cout << "     Author: " << book.author << "\n";
    cout << "     Publisher: " << book.publisher << "\n";
    cout << "     Year Publisher: " << book.yearPublish << "\n";
    cout << "     Type: " << book.type << "\n";
    cout << "     Price: " << book.price << "\n";
    cout << "     Number: " << book.number << "\n";
}

int HashBookCode(const string &s) {   
    int hashValue = 0;
    for(const auto &ch : s) {
        hashValue = hashValue * 31 + static_cast<int>(ch);
    }
    return hashValue;
}

string EncodeBookCode(Book book) {
    string input =  book.name + book.author + book.publisher + to_string(book.yearPublish) + 
        book.type + to_string(book.number);
    int hashValue = HashBookCode(input);

    string code = HashSixDigitCode(hashValue);
    if(code[0] == '-') {
        srand(time(nullptr));
        code = to_string(rand() % 9 + 0) + code.substr(1);
    }
    return code;
}

string HashSixDigitCode(int num) {
    num = num % 1000000;
    string code = to_string(num);
    while (code.length() < 6) {
        code = "0" + code;
    }
    return code;
}