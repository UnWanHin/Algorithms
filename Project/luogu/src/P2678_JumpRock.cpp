#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;
int L, N, M;
int pos[MAXN];  // pos[0] = 0, pos[1..N] = 岩石位置, pos[N+1] = L

bool check(int mid) {
    int remove = 0;     // 已移走岩石数
    int last = 0;       // 上一次站立的岩石位置（从0开始）
    for (int i = 1; i <= N + 1; ++i) {  // 遍历到终点
        if (pos[i] - last < mid) {
            ++remove;   // 距离太近，移走当前岩石
        } else {
            last = pos[i];  // 可以跳到这里
        }
    }
    return remove <= M;
}

int main() {
    cin >> L >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> pos[i];
    }
    pos[N + 1] = L;  // 终点

    int left = 0, right = L + 1, ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;  // 尝试更大
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

//二分+貪心
// O(N log L)
// mid ++--一直控制然後while left<=right去做