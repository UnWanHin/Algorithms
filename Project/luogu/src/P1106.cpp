#include <bits/stdc++.h>
using namespace std;

string n;
int k;

int main() {
    cin >> n >> k;

    string stk;  // 單調棧

    for (char c : n) {
        while (!stk.empty() && k > 0 && c < stk.back()) {
            stk.pop_back();
            k--;
        }
        stk.push_back(c);
    }

    // 還沒刪夠，從低位刪除
    while (k > 0 && !stk.empty()) {
        stk.pop_back();
        k--;
    }

    // 去除前導零
    size_t start = stk.find_first_not_of('0');  // 找到第一個非0的位置

    if (start == string::npos) {  // 全是0
        cout << "0" << endl;
    } else {
        cout << stk.substr(start) << endl;  // 從第一個非0開始輸出
    }

    return 0;
}