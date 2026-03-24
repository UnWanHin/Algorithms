#include <iostream>
#include <algorithm>
#include <vector>
// #include <cctype>
// #include <cstdio>
using namespace std;
bool isNumber(const string& s)
{
    if (s.empty()) return false;
    size_t start = (s[0] == '-') ? 1 : 0;
    return all_of(s.begin() + start, s.end(), ::isdigit);
}

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
    return 0;
}



//
// Created by unwan on 25-10-26.
//
