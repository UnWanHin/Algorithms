#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int main() {
    string str1 = "";
    string str2 = "";
    cout << "Please enter the first string" << endl;
    cin >> str1;
    cout << "Please enter the second string" << endl;
    cin >> str2;
    if (str1.size()<str2.size()||str1.size()==str2.size()&&str1<str2) {
        swap(str1, str2);
    }
    // cout << str1 << endl;
    // cout << str2 << endl;

    vector<int> v1(str1.size(), 0);
    vector<int> v2(str2.size(), 0);
    vector<int> v3(str1.size()+str2.size(),0);
    for (int i = 0; i < str1.size(); i++) {
        v1[i] = str1[i] - '0';
    }
    for (int i = 0; i < str2.size(); i++) {
        v2[i] = str2[i] - '0';
    }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    // 执行乘法
    for (int i = 0; i < str2.size(); i++) {
        for (int j = 0; j < str1.size(); j++) {
            v3[j+i] += v1[j] * v2[i];
        }
    }

    // 统一处理进位
    for (int i = 0; i < v3.size() - 1; i++) {
        if (v3[i] >= 10) {
            v3[i+1] += v3[i] / 10;
            v3[i] %= 10;
        }
    }

    // 反转回正常顺序
    reverse(v3.begin(), v3.end());

    // 跳过前导零
    int start = 0;
    while (start < v3.size() - 1 && v3[start] == 0) {
        start++;
    }

    // 输出完整结果
    for (int i = start; i < v3.size(); i++) {
        cout << v3[i];
    }
    cout << endl;

    return 0;
}

//
// Created by unwan on 25-10-18.
//


