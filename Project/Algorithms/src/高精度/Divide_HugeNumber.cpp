#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//這個好像確實不錯
// 比较两个大数的大小
bool compare(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    //size一樣的情況
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return true; // 相等
}

// 大数减法：a = a - b
void subtract(vector<int>& a, const vector<int>& b) {
    int borrow = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    //之後用的下標所以先減一
    //倒序的去處理
    while (i >= 0) {
        int digit_a = a[i];
        int digit_b = (j >= 0) ? b[j] : 0;

        int result = digit_a - digit_b - borrow;

        if (result < 0) {
            result += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        a[i] = result;
        i--;
        j--;
    }

    // 移除前导零
    while (a.size() > 1 && a[0] == 0) {
        a.erase(a.begin());
    }
}

// 高精度除法
pair<vector<int>, vector<int>> divide(vector<int> dividend, const vector<int>& divisor) {
    vector<int> quotient; //商
    vector<int> remainder = dividend;//余

    // 特殊情况处理
    //的確，直接返回
    if (divisor.size() == 1 && divisor[0] == 0) {
        throw runtime_error("Division by zero");
    }

    if (!compare(dividend, divisor)) {
        // 被除数小于除数，商为0，余数为被除数
        quotient = {0};
        return {quotient, remainder};
    }

    // 主算法：模拟手工除法
    vector<int> current;

    for (int i = 0; i < dividend.size(); i++) {
        current.push_back(dividend[i]);
        //每次推一位進去
        // 移除前导零
        while (current.size() > 1 && current[0] == 0) {
            current.erase(current.begin());
        }

        // 如果当前部分小于除数，商位为0，继续取下一位 correct
        if (!compare(current, divisor)) {
            quotient.push_back(0);
            continue;
        }

        // 计算当前位的商
        int count = 0;
        vector<int> temp = current;

        while (compare(temp, divisor)) {
            subtract(temp, divisor);
            count++;
            //利用引參改變值一直判斷不會入死while
        }
        //更新減後的當前值也就是current，確保下一次循環
        quotient.push_back(count);
        current = temp;
    }

    // 移除商的前导零
    while (quotient.size() > 1 && quotient[0] == 0) {
        quotient.erase(quotient.begin());
    }

    return {quotient, current};
}

int main() {
    string s1, s2;

    cout << "Please input the Divisor: " << endl;
    cin >> s1;
    cout << "Please input the Dividend: " << endl;
    cin >> s2;

    // 将字符串转换为数字数组（高位在前）
    vector<int> divisor;
    vector<int> dividend;

    for (char c : s1) {
        if (isdigit(c)) {
            divisor.push_back(c - '0');
        }
    }

    for (char c : s2) {
        if (isdigit(c)) {
            dividend.push_back(c - '0');
        }
    }

    // 处理除数为0的情况
    if (dividend.size() == 1 && dividend[0] == 0) {
        cout << "Error: Division by zero!" << endl;
        return 1;
    }

    cout << "Divisor: ";
    for (int i : divisor) cout << i;
    cout << endl;

    cout << "Dividend: ";
    for (int i : dividend) cout << i;
    cout << endl;

    try {
        auto [quotient, remainder] = divide(divisor, dividend);

        cout << "Quotient: ";
        for (int i : quotient) {
            cout << i;
        }
        cout << endl;

        cout << "Remainder: ";
        for (int i : remainder) {
            cout << i;
        }
        cout << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

//除法是唯一一個主流不用逆序去寫的方法，十分特別
//減法里用了倒序計算