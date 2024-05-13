#include "ultilty.h"

bool chuThuong(const char &ch) {
    return ch >= 'a' && ch <= 'z';
}

bool chuHoa(const char &ch) {
    return ch >= 'A' && ch <= 'Z';
}

vector<string> TachChuoi(const string &s) {
    string empty;
    stringstream ss(s);
    vector<string> containString;
    while(ss >> empty)
    {
        containString.push_back(empty);
    }
    return containString;
}

string InHoaDauCau(const string &s) {
    vector<string> containString = TachChuoi(s);
    string sum = "";
    for(auto &x : containString) {
        char ch = x[0];
        if(chuThuong(ch)) {
            x[0] -= 32;    
        }
        sum = sum + x + " ";
    }
    return sum.substr(0, sum.length() - 1);
}