#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
void BFS_Puzzle(vector<vector<int>> &v1, int x, int y, int target_x, int target_y, vector<pair<int,int>> &path);
void Print_Path(vector<pair<int,int>> &path);
int main() {
    int row, col;
    //row col of puzzle不一定好，可以是直接是目標點
    cout<<"Please input ros_of_puzzle"<<endl;
    cin>>row;
    cout<<"Please input col_of_puzzle"<<endl;
    cin>>col;
    vector<vector<int>> puzzle_set(row, vector<int>(col,0));
    //輸入帶障礙的迷宮
    for (auto& temp_row : puzzle_set) {
        // 遍歷當前行的每個元素，不加&就是單純副本
        for (auto& element : temp_row) {
            cin >> element;
        }
    }
    vector<pair<int,int>> path;
    BFS_Puzzle(puzzle_set,0,0,row-1,col-1, path);
    for (int i=0;i<puzzle_set.size();i++) {
        for (int j=0;j<puzzle_set[i].size();j++) {
            cout<<setw(5)<<puzzle_set[i][j];
        }
        cout<<endl;
    }
    // 在BFS函数中调用Print_Path
    return 0;
}
void BFS_Puzzle(vector<vector<int>> &v1, int start_x, int start_y, int target_x, int target_y, vector<pair<int,int>> &path) {
    // 检查起点和终点
    if (v1[start_x][start_y] == 1 || v1[target_x][target_y] == 1) {
        cout << "Cant arrived - start or target is blocked!" << endl;
        return;
    }
    // 方向: 右、下、左、上
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    // 使用队列进行BFS
    queue<pair<int,int>> q;
    // 记录前驱节点，用于重建路径
    vector<vector<pair<int,int>>> prev(v1.size(),
    vector<pair<int,int>>(v1[0].size(), {-1,-1}));
    //相當於這個數組每個格子裝的是前驅的坐標
    // 从起点开始
    //先push進去開始層序
    q.push({start_x, start_y});
    v1[start_x][start_y] = 2; // 标记为已访问
    prev[start_x][start_y] = {-1,-1}; // 起点没有前驱，給一個一定不可能是前驅的坐標
    bool found = false;
    // BFS主循环
    while (!q.empty() && !found) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        // 检查是否到达目标
        //因為是層序，所以即使x,y到了target也會層序走完其他的先
        if (x == target_x && y == target_y) {
            found = true;
            break;
        }
        // 尝试四个方向
        for (auto dir : directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            // 检查新位置是否有效
            if (new_x >= 0 && new_x < v1.size() &&
                new_y >= 0 && new_y < v1[0].size() &&
                v1[new_x][new_y] == 0) {

                // 标记为已访问并加入队列
                v1[new_x][new_y] = 2;
                prev[new_x][new_y] = {x, y};
                q.push({new_x, new_y});
            }
        }
    }
    // 重建路径
    if (found) {
        int x = target_x, y = target_y;
        // 从终点回溯到起点
        while (x != -1 && y != -1) {
            path.push_back({x, y});
            auto p = prev[x][y];
            x = p.first;
            y = p.second;
        }
        // 反转路径，使其从起点到终点
        reverse(path.begin(), path.end());
        // 在迷宫中标记路径
        for (auto p : path) {
            v1[p.first][p.second] = 3;
        }
        cout << "Path found! Length: " << path.size() << endl;
        // 在BFS函数中调用Print_Path
        Print_Path(path);
    }
    else {
        cout << "No path found!" << endl;
    }
}
void Print_Path(vector<pair<int,int>> &path) {
    if (path.empty()) {
        cout << "No path to display." << endl;
        return;
    }
    cout << "\nPath coordinates:" << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << "Step " << setw(2) << i << ": (" << path[i].first
             << ", " << path[i].second << ")" << endl;
    }
}
//Read till understood