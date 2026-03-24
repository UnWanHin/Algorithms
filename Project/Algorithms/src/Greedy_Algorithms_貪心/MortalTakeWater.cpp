#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int num_of_people, num_of_faucet, sum_time=0;
    cout<<"Please enter the number of People:"<<endl;
    cin>>num_of_people;
    cout<<"Please enter the number of Faucet:"<<endl;
    cin>>num_of_faucet;

    vector<int> people_array(num_of_people);
    for(int i=0;i<num_of_people;i++) {
        cin>>people_array[i];
    }
    sort(people_array.begin(), people_array.end());

    for(int i=0;i<num_of_people;i++) {
        if (i>=num_of_faucet) { //數組由0開始所以>=
            people_array[i]=people_array[i]+people_array[i-num_of_faucet];
        }
            sum_time+=people_array[i];

    }
    cout<<"Sum(min) time:"<<sum_time<<endl;

    return 0;
}
// 和尚打水調度問題
// Created by unwan on 25-10-17.
//
