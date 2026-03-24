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

    bool isNegative = false;
    if (str1.size() < str2.size() ||
        (str1.size() == str2.size() && vector<char>(str1) < vector<char>(str2))) {
        swap(str1, str2);
        isNegative = true;
        }

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    vector<char> result;
    int borrow = 0;
    for (int i = 0; i < str1.size(); i++) {
        int digit1 = str1[i] - '0';
        int digit2 = (i < str2.size()) ? (str2[i] - '0') : 0;

        // 减去借位
        digit1 -= borrow;
        borrow = 0;

        // 如果当前位不够减，需要借位
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        }

        int diff = digit1 - digit2;
        result.push_back(diff + '0');
    }

    // 移除结果中的前导零
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());

    cout << "结果是: ";
    if (isNegative) {
        cout << "-";
    }
    for (char c : result) {
        cout << c;
    }
    cout << endl;
    return 0;
}

//
// Created by unwan on 25-10-18.
//

// 用vector<char> 明顯空間更小更快 1 byte
// 用vector<int> 則更方便處理但用空間更多 4byte