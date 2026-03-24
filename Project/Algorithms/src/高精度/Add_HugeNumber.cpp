#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    vector<char> str1, str2;
    char c;
    cout<<"Enter the first strings: "<<endl;
    while (cin.get(c)&& c!='\n'&& c!=EOF) {
        if (isdigit(c)) {
            str1.push_back(c);
        }
    }
    cout<<"Enter the second strings: "<<endl;
    while (cin.get(c)&& c!='\n'&& c!=EOF) {
        if (isdigit(c)) {
            str2.push_back(c);
        }
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    vector<char> result;
    int carry = 0;
    int maxLength = max(str1.size(), str2.size());
    for (int i = 0; i < maxLength || carry; i++) {
        int sum = carry;
        if (i < str1.size()) sum += str1[i] - '0';
        if (i < str2.size()) sum += str2[i] - '0';

        carry = sum / 10;
        result.push_back((sum % 10) + '0');

    }

    reverse(result.begin(), result.end());

    cout << "结果是: ";
    for (char c : result) {
        cout << c;
    }
    cout << endl;

    return 0;
}

//
// Created by unwan on 25-10-18.
//
