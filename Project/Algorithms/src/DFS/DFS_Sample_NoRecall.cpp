//終於進入深搜的地方了
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
void DFS_Path_NoObstacle(vector<vector<int>> &v1,int x, int y, int k);
//走迷宮
int main() {
    int row, col;
    cout<<"Please input ros_of_puzzle"<<endl;
    cin>>row;
    cout<<"Please input col_of_puzzle"<<endl;
    cin>>col;
    vector<vector<int>> puzzle_set(row, vector<int>(col,0));
    DFS_Path_NoObstacle(puzzle_set,0,0,1);
    //首先先是無障礙的情況，觀察路徑
    for (int i=0;i<puzzle_set.size();i++) {
        for (int j=0;j<puzzle_set[i].size();j++) {
            cout<<setw(5)<<puzzle_set[i][j];
        }
        cout<<endl;
    }

    return 0;
}
//不帶回溯版本
void DFS_Path_NoObstacle(vector<vector<int>> &v1,int x, int y, int k) {
    v1[x][y]=k;

    int rows=v1.size();
    int cols=v1[0].size();
    //然後決定你的順序
    // 向右移动：检查 y+1 是否小于列数，且目标位置为0
    if (y + 1 < cols && v1[x][y + 1] == 0) {
        DFS_Path_NoObstacle(v1, x, y + 1, k + 1);
    }
    // 向下移动：检查 x+1 是否小于行数，且目标位置为0
    else if (x + 1 < rows && v1[x + 1][y] == 0) {
        DFS_Path_NoObstacle(v1, x + 1, y, k + 1);
    }
    // 向左移动：检查 y-1 是否大于等于0，且目标位置为0
    else if (y - 1 >= 0 && v1[x][y - 1] == 0) {
        DFS_Path_NoObstacle(v1, x, y - 1, k + 1);
    }
    // 向上移动：检查 x-1 是否大于等于0，且目标位置为0
    else if (x - 1 >= 0 && v1[x - 1][y] == 0) {
        DFS_Path_NoObstacle(v1, x - 1, y, k + 1);
    }
}



//
// Created by unwan on 25-10-20.
//

//GCC
//Clang
//MSVC
