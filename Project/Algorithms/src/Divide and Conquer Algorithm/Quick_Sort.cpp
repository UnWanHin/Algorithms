#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
void Quick_sort(vector<int>& nums_arrays, int left, int right);
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
    //sort(v.begin(), v.end());


    cout << endl;

    Quick_sort(v, 0, v.size() - 1);

    cout << "Sorted array: ";
    for (auto i: v) {
        cout << i << " ";
    }
    return 0;
}

void Quick_sort(vector<int>& nums_arrays, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    int i = left;
    int j = right;
    int temp=nums_arrays[mid];
    while (i <= j) { //一輪做到mid點，然後再i++, j--開始分治
        while (nums_arrays[i] < temp) {
            i++;
        }
        while (nums_arrays[j] > temp) {
            j--;
        }
        if (i <= j) {
            swap(nums_arrays[i], nums_arrays[j]);
            i++;
            j--;
        }
    }
    if (left<j) { //確保有多於一個元素，才有分治遞歸的需求
        Quick_sort(nums_arrays, left, j);
    }
    if (right>i) {
        Quick_sort(nums_arrays, i, right);
    }
}

//
// Created by unwan on 25-10-26.
//
