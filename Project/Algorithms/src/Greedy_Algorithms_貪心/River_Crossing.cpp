#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int number_of_people, sum_time=0;
    cin>>number_of_people;
    vector<int> people_list(number_of_people, 0);
    for(int i=0;i<number_of_people;i++) {
        cout<<"People number "<<i+1<<" time : "<<endl;
        cin>>people_list[i];
    }

    sort(people_list.begin(), people_list.end());
    for(int i=0;i<number_of_people;i++) {
        if (i>0) {
            people_list[i]=people_list[i]+people_list[0];
            sum_time+=people_list[i];
        }

    }
    sum_time-=people_list[0];
    cout<<sum_time<<endl;
    return 0;
}
// 來回最後一次不用走


// 渡橋時間分配問題，到底我好像還不明白貪心的思想?
// 回答一下我自己
// 貪分不一定是最優的決策，主要思想是用局部的最優去推導一個全局最優但不一定正確

// Created by unwan on 25-10-17.
//
