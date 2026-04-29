#include "String.hpp"

std::string InputString() {
    std::string s{};
    std::cout<<"Please enter a string: ";
    std::cin>>s;
    return s;
}
//Lambda
//學習下這種代碼思路
std::string LongestPalindromicSubstring(std::string s) {
    if (s.empty()||s.size()==1) return s;

    int start = 0;
    int maxLength = 1;

    auto MoveCenter = [&](int left, int right) {
        while (left >= 0 && right < s.size() && s.at(left) == s.at(right)) {
            left --;
            right ++;
        }
        return right-left-1;
    };

    for (int i=0 ; i<s.size(); i++) {
        int len1 = MoveCenter(i,i);
        int len2 = MoveCenter(i, i+1);
        int len = std::max(len1,len2);

        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1)/2;
        }
    }

    return s.substr(start, maxLength);
}

std::string MinimumWindowSubstring(std::string s, std::string t) {

    if (s.size() < t.size() || s.empty() || t.empty()) return "";

    std::unordered_map<char, int> need, window;
    for (char c: t) {
        need[c]++;
    }
    int left = 0, right = 0;
    int valid = 0;
    int start = 0;
    int MinimumLength = s.size() + 1; //給一個最大值

    while (right < s.length()) {
        char c = s[right];
        right++;

        if (need.count(c)) {
            window[c]++; //做累積
            if (window[c] == need[c]) { //先對齊一種字符
                valid++;
            }
        }
        //全對齊了
        while (valid == need.size()) {
            if (right - left < MinimumLength) {
                start = left;
                MinimumLength = right - left;
            }

            char d = s[left];
            left++;

            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }
    return MinimumLength == s.size() + 1 ? "" : s.substr(start, MinimumLength);
}
//
// Created by unwan on 17/4/2026.
//