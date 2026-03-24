#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
using namespace std;
void Dynamic_Counting(vector<vector<int>>& Number_Triangles, int high);

int main() {
    cout<<"Please enter the Level of Triangles"<<endl;
    int n;
    cin>>n;
    cout<<"Please Enter the Date to the Triangles"<<endl;
    vector<vector<int>> Number_Triangles(n, vector<int>(n,0));
    for (int i=0;i<n;i++) {
        cout<<"Line :"<<i+1<<endl;
        for (int j=0;j<=i;j++) {
            cin>>Number_Triangles[i][j];
        }
    }
    Dynamic_Counting(Number_Triangles, n-1);
    return 0;
}
//0 到 n-1
void Dynamic_Counting(vector<vector<int>>& Number_Triangles, int high) {
    // 创建DP表
    vector<vector<int>> dp = Number_Triangles;

    // 从底部向上计算最大路径和
    for (int i = high - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = Number_Triangles[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // 输出最大路径和
    cout << "Maximum path sum: " << dp[0][0] << endl;

    // 使用回溯法找到所有最大路径
    vector<vector<pair<int, int>>> allPaths;
    vector<pair<int, int>> currentPath;

    // 回溯函数
    function<void(int, int)> backtrack = [&](int row, int col) {
        currentPath.push_back({row, col});

        // 如果到达底部，保存路径
        if (row == high) {
            allPaths.push_back(currentPath);
        } else {
            // 如果左右两个方向的值相同，说明有多个路径
            if (dp[row + 1][col] == dp[row + 1][col + 1]) {
                // 两个方向都尝试
                backtrack(row + 1, col);     // 左下
                backtrack(row + 1, col + 1); // 右下
            } else if (dp[row + 1][col] > dp[row + 1][col + 1]) {
                backtrack(row + 1, col);     // 左下
            } else {
                backtrack(row + 1, col + 1); // 右下
            }
        }

        currentPath.pop_back();
    };

    // 从顶点开始回溯
    backtrack(0, 0);

    // 输出所有路径
    cout << "Found " << allPaths.size() << " path(s) with maximum sum:" << endl;
    for (int i = 0; i < allPaths.size(); i++) {
        cout << "Path " << i + 1 << ": ";
        for (int j = 0; j < allPaths[i].size(); j++) {
            int r = allPaths[i][j].first;
            int c = allPaths[i][j].second;
            cout << Number_Triangles[r][c];
            if (j < allPaths[i].size() - 1) {
                cout << " -> ";
            }
        }
        cout << " (Sum: " << dp[0][0] << ")" << endl;
    }

    // 可选：打印DP表
    cout << "\nDP table:" << endl;
    for (int i = 0; i <= high; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(4) << dp[i][j];
        }
        cout << endl;
    }
}

//
// Created by unwan on 25-10-28.
//
