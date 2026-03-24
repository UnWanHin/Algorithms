#include <iostream>
#include <vector>
#include <boost/math/special_functions/binomial.hpp>

using namespace std;
int num_of_path(int target_x, int target_y, int horse_x, int horse_y);
void marked_points(vector<vector<int>> &coordinate_sys, int horse_x, int horse_y);
bool is_point_valid(int x, int y, int size_x, int size_y);

int main() {
    int horse_x, horse_y;
    int target_x, target_y;
    cout<<"please input the target locate (x,y)"<<endl;
    cin >> target_x >> target_y;
    cout<<"please input the horse x,y"<<endl;
    cin >> horse_x >> horse_y;
    num_of_path(target_x, target_y, horse_x, horse_y);

    return 0;
}

int num_of_path(int target_x, int target_y, int horse_x, int horse_y) {

    //唯一路徑
    if (target_x==0||target_y==0) {
        cout << "There is only one path to get target : 1" << endl;
        return 0;
    }
    //判溢_就是馬的位置不會影響到棋盤
    if (horse_x-target_x>=3||horse_y-target_y>=3) {
        //全路徑 結果為(x+y)Cx或(x+y)Cy
        cout << "Number of paths = " << boost::math::binomial_coefficient<double>(target_x+target_y, target_x) << endl;
        return 0;
    }
    else if (((abs(target_x-horse_x)==2)&&(abs(target_y-horse_y)==1))||((abs(target_x-horse_x)==1)&&(abs(target_y-horse_y)==2))) {
        cout << "Can't reach because Horse is controlling the point"<<endl;
        return 0;
    }

    //建立棋盤，下標對應一下
    vector<vector<int>> coordinate_sys(target_x+1, vector<int>(target_y+1, 1));
    coordinate_sys[horse_x][horse_y] = 0;
    marked_points(coordinate_sys, horse_x, horse_y);
    //finally i got it ;-;


    // 如果起點被馬控制，直接返回0
    if (coordinate_sys[0][0] == 0) {
        cout << "Can't reach because starting point is controlled by horse" << endl;
        return 0;
    }

    // 初始化起點為1（表示有1條路徑到達起點）
    coordinate_sys[0][0] = 1;

    // 計算所有位置的路徑數，包括第0行和第0列
    for (int i = 0; i <= target_x; i++) {
        for (int j = 0; j <= target_y; j++) {
            // 跳過起點，因為它已經初始化為1
            if (i == 0 && j == 0) continue;

            // 如果是馬的控制點，設置為0
            if (coordinate_sys[i][j] == 0) {
                coordinate_sys[i][j] = 0;
            } else {
                // 計算從左邊和上邊來的路徑數
                int from_left = (j > 0) ? coordinate_sys[i][j-1] : 0;
                int from_top = (i > 0) ? coordinate_sys[i-1][j] : 0;
                coordinate_sys[i][j] = from_left + from_top;
            }
        }
    }
    //keep fighting please, dont drop ur remind 2025.10.17

    // for (int i = 1; i <= target_x; i++) {
    //     for (int j = 1; j <= target_y; j++) {
    //         if (coordinate_sys[i][j]==1) {
    //             coordinate_sys[i][j] = coordinate_sys[i-1][j] + coordinate_sys[i][j-1];
    //         }
    //     }
    // }
    cout << coordinate_sys[target_x][target_y] << endl;

    cout<<"target x,y\n"<<target_x<<","<<target_y<<endl;
    cout<<"horse x,y\n"<<horse_x<<","<<horse_y<<endl;

    for (int i = 0; i <= target_x; i++) {
        for (int j = 0; j <= target_y; j++) {
            cout<<coordinate_sys[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

bool is_point_valid(int x, int y, int size_x, int size_y) {
    return x >= 0 && x < size_x && y >= 0 && y < size_y;
}

void marked_points(vector<vector<int>> &coordinate_sys, int horse_x, int horse_y) {

    int size_x = coordinate_sys.size(); //read the puzzle size
    int size_y = (size_x > 0) ? coordinate_sys[0].size() : 0;

    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    //馬本身自己的位置
    if (is_point_valid(horse_x, horse_y, size_x, size_y)) {
        coordinate_sys[horse_x][horse_y] = 0;
    }

    for (int i = 0; i < 8; i++) {
        int New_x=horse_x+moves[i][0];
        int New_y=horse_y+moves[i][1];

        if (is_point_valid(New_x, New_y, size_x, size_y)) {
            coordinate_sys[New_x][New_y] = 0;
            cout<<"己設置"<<New_x<<","<<New_y<<"為0"<<endl;
        }
    }

}


//還有些邊界沒完善，比如如果target_y=0 Horse_control_anypoint_x=0 then just return