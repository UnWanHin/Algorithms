#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

bool isNumber(const std::string& s) {
    // 处理空字符串和负数
    if (s.empty()) return false;
    size_t start = (s[0] == '-') ? 1 : 0;
    // 检查剩余字符是否全为数字
    return std::all_of(s.begin() + start, s.end(), ::isdigit);
}

void menu();

int main() {

    vector<int> v;
    string s;
    cout<<"Enter the number of elements in the array"<<endl;
    while(cin >> s && isNumber(s)) {
        v.push_back(stoi(s));
    }

    for (auto i: v) {
        cout<<i<<" ";
    }

    menu();

    return 0;
}

void menu() {

    system("clear");
}


//
// Created by unwan on 2026/1/22.
//