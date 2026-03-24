//計算幂指數，高精度方法
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string num_base;

    int num_power;
    cout<<"Please input base number"<<endl;
    cin>>num_base;
    cout<<"Please input power of base"<<endl;
    cin>>num_power;
    //反轉底數
    reverse(num_base.begin(), num_base.end());

    vector<int> num(1,1);
    vector<int> base_num;
    for (int i = 0; i < num_base.size(); i++) {
        base_num.push_back(num_base[i] - '0');
    }
    //Reverse 測試
    // for (int i = 0; i < num_base.size(); i++) {
    //     cout<<base_num[i];
    // }



    for (int i = 0; i < num_power; i++) {

        vector<int> temp(num.size() + base_num.size(), 0);

        for (int j = 0; j < num.size(); j++) {
            for (int k = 0; k < base_num.size(); k++) {
                temp[j + k] += num[j] * base_num[k];
            }
        }
        int carry = 0;
        for (int m = 0; m < temp.size(); m++) {
            temp[m] += carry;
            carry = temp[m] / 10;
            temp[m] %= 10;
        }

        // 移除前导零
        while (temp.size() > 1 && temp.back() == 0) {
            temp.pop_back();
        }

        // 更新结果
        num = temp;

    }
    reverse(num.begin(), num.end());

    // 输出结果
    cout << "Result: ";
    for (int i = 0; i < num.size(); i++) {
        cout << num[i];
    }
    cout << endl;

    return 0;

}


//
// Created by unwan on 25-10-19.
//
