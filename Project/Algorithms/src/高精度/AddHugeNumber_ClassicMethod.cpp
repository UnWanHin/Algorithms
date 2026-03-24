#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    cout<<"Please input first number:"<<endl;
    cin>>s1;
    cout<<"Please input second number:"<<endl;
    cin>>s2;

    cout << "You entered: " << s1 << " and " << s2 << endl;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    vector<int> v1;
    int maxsize = max(s1.size(), s2.size());
    int carry =0;
    // 注意數組越界的問題
    for(int i = 0; i < maxsize || carry; i++) {
        int sum = carry;
        if (i<s1.size()) {
            sum += s1.at(i)-'0';
        }
        if (i<s2.size()) {
            sum += s2.at(i)-'0';
        }
        carry = sum/10;
        sum = sum%10;
        v1.push_back(sum);

    }
    reverse(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i];
    }

    return 0;
}

//
// Created by unwan on 25-10-18.
//
// 這個是用vector<int>實現的，但思路和vector<char>一樣只是少了轉換但多了內存