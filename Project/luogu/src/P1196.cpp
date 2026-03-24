 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e4 + 10;
int T, fa[N], s[N], b[N];
 
int Find(int x) {
    if (x == fa[x]) return x;
    int k = fa[x];
    fa[x] = Find(fa[x]);
    s[x] += s[k];
    b[x] = b[fa[x]];
    return fa[x];
}
 
void SolveM() {
    int x, y;
    cin >> x >> y;
    int dx = Find(x);
    int dy = Find(y);
    
    fa[dx] = dy;
    s[dx] += b[dy];
    b[dx] = b[dy] = b[dy] + b[dx];
}
 
void SolveC() {
    int x, y;
    cin >> x >> y;
    int dx = Find(x);
    int dy = Find(y);
    
    if (dx != dy) {
        cout << "-1" << endl;
        return;
    }
    cout << abs(s[x] - s[y]) - 1 << endl;
}
 
int main() {
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for (int i = 1; i <= 30000; i++) {
        fa[i] = i;
        s[i] = 0;
        b[i] = 1;
    }
    while (T--) {
        char ch;
        cin >> ch;
        if (ch == 'M') {
            SolveM();
        }
        if (ch == 'C') {
            SolveC();
        }
    }
    return 0;
}
//加一個數組去記錄長度
//路徑壓縮的遞歸過程
//M數組快速得知前面隊伍有多長，更新 s[]
//FIND利用路徑壓縮將局部的距離累加成全局距離
//C利用兩個節點到根的距離差，算出它們之間的相對距離

//帶權並查集