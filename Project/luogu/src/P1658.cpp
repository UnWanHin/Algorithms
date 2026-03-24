#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int X, n, a[10000];
    cin >> X >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i == n){
            a[i+1] = 1e7;
        }
    }
 
    sort(a+1, a+n+1);
    
    //当第一个面值不是1时输出-1
    if(a[1] != 1){
        cout << "-1";
        return 0;
    }
 
    //设定游标now，“钱包”总金额sum，硬币总数cnt
    int now, sum = 0, cnt = 0;
    for(now = 1; now <= X; now = sum + 1){
        for(int i = 1; i <= n; i++){//从“仓库”中面值最小的硬币开始枚举
            if(a[i+1] > now){//当下一个硬币的面值比当前目标金额大时
                sum += a[i];
                cnt++;
                break;//打断循环
            }
        }
    }
    cout << cnt;
    return 0;
}

//sum+1下一個，由0開始到X