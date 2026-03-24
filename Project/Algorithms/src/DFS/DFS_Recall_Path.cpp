#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
void DFS_Path_WithObstacle(vector<vector<int>> &v1,int x, int y, int k, int target_x, int target_y, vector<pair<int,int>> &path);
void Print_Path(vector<pair<int,int>> &path);
int count_path_number=1;
//走迷宮
//bool found = false;

int main() {
    int row, col;
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


    DFS_Path_WithObstacle(puzzle_set,0,0,1,row-1,col-1, path);
    //首先先是無障礙的情況，觀察路徑
    for (int i=0;i<puzzle_set.size();i++) {
        for (int j=0;j<puzzle_set[i].size();j++) {
            cout<<setw(5)<<puzzle_set[i][j];
        }
        cout<<endl;
    }
    //if (!found) {
    //    cout << "无路可达！" << endl;
    //}
    return 0;
}
//不帶回溯版本
void DFS_Path_WithObstacle(vector<vector<int>> &v1,int x, int y, int k, int target_x, int target_y, vector<pair<int,int>> &path) {
    //if (found) return;
    //提早返回
    if (v1[x][y]==1||v1[target_x][target_y]) {
        cout<<"Cant arrived"<<endl;
        return;
    }

    path.push_back(make_pair(x,y));
    v1[x][y]=2;
    if (x==target_x && y==target_y) {
        Print_Path(path);
        v1[x][y]=0;
        path.pop_back();
        //found = true;
        return ;
    }

    int rows=v1.size();
    int cols=v1[0].size();
    //然後決定你的順序
    // 向右移动：检查 y+1 是否小于列数，且目标位置为0
    if (y + 1 < cols && v1[x][y + 1] == 0) {
        DFS_Path_WithObstacle(v1, x, y + 1, k + 1, target_x, target_y, path);
        //if (found) return;
    }
    // 向下移动：检查 x+1 是否小于行数，且目标位置为0
    if (x + 1 < rows && v1[x + 1][y] == 0) {
        DFS_Path_WithObstacle(v1, x + 1, y, k + 1, target_x, target_y, path);
        //if (found) return;
    }
    // 向左移动：检查 y-1 是否大于等于0，且目标位置为0
    if (y - 1 >= 0 && v1[x][y - 1] == 0) {
        DFS_Path_WithObstacle(v1, x, y - 1, k + 1, target_x, target_y, path);
        //if (found) return;
    }
    // 向上移动：检查 x-1 是否大于等于0，且目标位置为0
    if (x - 1 >= 0 && v1[x - 1][y] == 0) {
        DFS_Path_WithObstacle(v1, x - 1, y, k + 1, target_x, target_y, path);
        //if (found) return;
    }

    v1[x][y]=0;
    path.pop_back();

};

void Print_Path(vector<pair<int,int>> &path) {
    cout<<"Path:"<<count_path_number<<endl;
    for (auto it = path.begin(); it != path.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ")";
        if (std::next(it) != path.end()) {
            cout << "->";
        }
    }
    count_path_number++;
    cout << endl;
}

//
// Created by unwan on 25-10-25.
//
