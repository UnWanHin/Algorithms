#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;  // 小頂堆
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }
    
    long long ans = 0;
    while (pq.size() > 1) {
        long long x = pq.top(); pq.pop();
        long long y = pq.top(); pq.pop();
        long long sum = x + y;
        ans += sum;
        pq.push(sum);  // 新堆加入
    }
    
    cout << ans << endl;
    return 0;
}

//頂部最高優先級