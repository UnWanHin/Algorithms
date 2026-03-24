#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> bricks;  // 存 (行, 列, c)
// t=top
// h=hole
// q=quadrant

void solve(int tr, int tc, int hr, int hc, int size) {
    if (size == 1) return;

    int half = size / 2;
    int qr = (hr >= tr + half) ? 1 : 0;
    int qc = (hc >= tc + half) ? 1 : 0;

    int c, cr, cc;  // 1-based
    if (qr == 0 && qc == 0) {        // 空格左上
        c = 1; cr = tr + half + 1; cc = tc + half + 1;
    } else if (qr == 0 && qc == 1) {  // 空格右上
        c = 2; cr = tr + half + 1; cc = tc + half;
    } else if (qr == 1 && qc == 0) {  // 空格左下
        c = 3; cr = tr + half;     cc = tc + half + 1;
    } else {                         // 空格右下
        c = 4; cr = tr + half;     cc = tc + half;
    }

    bricks.emplace_back(cr, cc, c);

    // 递归四个子区域
    // 左上
    int nhr = (qr == 0 && qc == 0) ? hr : tr + half - 1;
    int nhc = (qr == 0 && qc == 0) ? hc : tc + half - 1;
    solve(tr, tc, nhr, nhc, half);

    // 右上
    nhr = (qr == 0 && qc == 1) ? hr : tr + half - 1;
    nhc = (qr == 0 && qc == 1) ? hc : tc + half;
    solve(tr, tc + half, nhr, nhc, half);

    // 左下
    nhr = (qr == 1 && qc == 0) ? hr : tr + half;
    nhc = (qr == 1 && qc == 0) ? hc : tc + half - 1;
    solve(tr + half, tc, nhr, nhc, half);

    // 右下
    nhr = (qr == 1 && qc == 1) ? hr : tr + half;
    nhc = (qr == 1 && qc == 1) ? hc : tc + half;
    solve(tr + half, tc + half, nhr, nhc, half);
}

int main() {
    int k, x, y;
    cin >> k;
    cin >> x >> y;
    int size = 1 << k;
    solve(0, 0, x - 1, y - 1, size);  // 转为0-based

    for (auto [r, c, tp] : bricks) {
        cout << r << " " << c << " " << tp << endl;
    }
    return 0;
}