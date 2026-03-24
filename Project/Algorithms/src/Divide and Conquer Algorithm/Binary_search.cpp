#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 改名為 Binary_search 更合適
int Binary_search(const vector<int>& nums_arrays, int value_search, int Flag_left, int Flag_right) {
    // 基準情況：搜索範圍無效
    if (Flag_left > Flag_right) {
        return -1;  // 未找到
    }

    int mid = Flag_left + (Flag_right - Flag_left) / 2;  // 防止溢出

    if (nums_arrays[mid] == value_search) {
        return mid;  // 找到，返回索引
    }
    else if (value_search > nums_arrays[mid]) {
        // 搜索右半部分
        return Binary_search(nums_arrays, value_search, mid + 1, Flag_right);
    }
    else {
        // 搜索左半部分
        return Binary_search(nums_arrays, value_search, Flag_left, mid - 1);
    }
}

bool isNumber(const string& s) {
    if (s.empty()) return false;
    size_t start = (s[0] == '-') ? 1 : 0;
    return all_of(s.begin() + start, s.end(), ::isdigit);
}

int main() {
    vector<int> v;
    string s;

    cout << "Enter the number of elements in the array" << endl;
    while(cin >> s && isNumber(s)) {
        v.push_back(stoi(s));
    }

    // 先排序（二分查找要求有序）
    sort(v.begin(), v.end());

    cout << "Sorted array: ";
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;

    int value_search;
    cout << "Please input the data for searching" << endl;
    cin >> value_search;

    int result = Binary_search(v, value_search, 0, v.size() - 1);

    if (result != -1) {
        cout << "Found at index: " << result << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}

//因為返回的是下標所以不用怕元素內的內容是-1和return 重合了
