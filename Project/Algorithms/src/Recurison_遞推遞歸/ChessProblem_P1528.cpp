#include <iostream>
#include <vector>
using namespace std;

int main() {

    int length, width;
    cout<<"Enter the length of the board: "<<endl;
    cin>>length;
    cout<<"Enter the width of the board: "<<endl;
    cin>>width;

    int sum=0;
    //數論的方法，不算太遞推
    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= length; j++) {
            sum += i*j;
        }
    }
    cout<<sum<<endl;

    vector<vector<int>> square(width+1, vector<int>(length+1, 0));
    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= length; j++) {
            square[i][j] = square[i-1][j]+square[i][j-1]-square[i-1][j-1]+i*j;
        }
    }
    cout<<square[width][length]<<endl;

    for (int i = 0; i <= width; i++) {
        for (int j = 0; j <= length; j++) {
            cout<<square[i][j]<<"    \t";

        }
        cout<<endl;
    }

    return 0;
}

//
// Created by unwan on 25-10-17.
//
