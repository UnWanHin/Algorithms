#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, a[maxn], sz[maxn], ans[maxn];
bool big[maxn];
vector<int> g[maxn];

int bit[maxn];
int lowbit(int x) {
    return x & -x;
}
void add(int p, int val) {
    while (p <= n) {
        bit[p] += val;
        p += lowbit(p);
    }
}
int query(int p) {
    int res = 0;
    while (p) {
        res += bit[p];
        p -= lowbit(p);
    }
    return res;
}

void dfs_add(int u, int c) {
    add(a[u], c);
    for (auto v : g[u])
        if (!big[v])
            dfs_add(v, c);
}

void dfs0(int u) {
    sz[u] = 1;
    for (auto v : g[u])
        dfs0(v), sz[u] += sz[v];
}

void dfs(int u, bool keep) {
    int son = 0;
    for (auto v : g[u])
        if (sz[v] > sz[son])
            son = v;
    for (auto v : g[u])
        if (v != son)
            dfs(v, false);
    if (son)
        dfs(son, true),
        big[son] = true;
    dfs_add(u, 1);
    ans[u] = query(n) - query(a[u]);
    if (son)
        big[son] = false;
    if (!keep)
        dfs_add(u, -1);
}

void lsh() {
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(a[i]);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    lsh();
    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
    }
    dfs0(1);
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
//下往上開始算