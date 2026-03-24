#include <iostream>
using namespace std;
int main() {

    int n;
    cout<<"Size of Array"<<endl;
    cin>>n;
    int array[n];
    for (int i=0;i<n;i++) {
        cout<<"please input no."<< i <<" elements :"<<endl;
        cin>>array[i];
    }
    for (int i=n-1;i>=0;i--) {
        bool swapped = false;
        for (int j=0;j<i;j++) {
            if (array[j]>array[j+1]) {
                swap(array[j],array[j+1]);
                swapped = true;
            }
        }
        if (swapped==false) {
            break;
        }
    }

    for (auto i: array) {
        cout<<i<<" ";
    }

    return 0;
}
//
// Created by unwan on 2026/1/23.
//