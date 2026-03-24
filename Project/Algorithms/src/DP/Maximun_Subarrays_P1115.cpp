#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;
void Max_Subarrays(vector<int>& nums_array);
bool isNumber(const string& s) {
    if (s.empty()) return false;
    size_t start = (s[0] == '-') ? 1 : 0;
    return all_of(s.begin() + start, s.end(), ::isdigit);
}
int main() {
    vector<int> v;
    string s;
    cout<<"Please enter element in the arrays: "<<endl;
    while (cin>>s && isNumber(s)) {
        v.push_back(stoi(s));
    }

    for (int i:v) {
        cout<<i<<" ";
    }

    cout<<endl;
    Max_Subarrays(v);
    return 0;
}
void Max_Subarrays(vector<int>& nums_array) {
    if (nums_array.empty()) {
        cout << "Array is empty!" << endl;
        return;
    }
    vector<int> v_dp;
    v_dp.push_back(nums_array[0]);
    int max_loop=v_dp[0];
    for (int i=1;i<nums_array.size();i++) {
        v_dp.push_back(max(nums_array[i], v_dp[i-1]+nums_array[i]));
        max_loop = max(max_loop, v_dp[i]);
    }
    cout<<max_loop<<endl;
}

// keep studying
//
// Created by unwan on 25-10-28.
//
