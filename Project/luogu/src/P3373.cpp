#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i <= e; i++) // 定义循环宏，从s到e
#define ll long long // 定义长整型别名
#define lc rt * 2 // 左子节点索引
#define rc rt * 2 + 1 // 右子节点索引
#define lson lc, l, mid // 左子树参数
#define rson rc, mid + 1, r // 右子树参数
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f; // 定义常量

// 线段树节点结构体
struct node {
    ll sum, addlazy, mullazy; // 区间和、加法懒标记、乘法懒标记
};
node t[N * 4]; // 线段树数组
ll n, m, a[N], mod; // 元素个数、操作次数、原始数组、模数

// 下传标记函数
void down(int rt, int l, int r, ll addlazy, ll mullazy) {
    // 更新当前节点的sum值：先乘后加
    t[rt].sum = (t[rt].sum * mullazy + (r - l + 1) * addlazy) % mod;
    // 更新加法标记：先乘后加
    t[rt].addlazy = (t[rt].addlazy * mullazy + addlazy) % mod;
    // 更新乘法标记：直接相乘
    t[rt].mullazy = (t[rt].mullazy * mullazy) % mod;
}

// 下传当前节点的标记到子节点
void pushdown(int rt, int l, int r) {
    // 如果没有标记则直接返回
    if (t[rt].addlazy == 0 && t[rt].mullazy == 1) return;
    int mid = (r + l) / 2;
    // 下传标记到左子树
    down(lc, l, mid, t[rt].addlazy, t[rt].mullazy);
    // 下传标记到右子树
    down(rc, mid + 1, r, t[rt].addlazy, t[rt].mullazy);
    // 重置当前节点的标记
    t[rt].addlazy = 0;
    t[rt].mullazy = 1;
}

// 更新当前节点的sum值为左右子节点sum之和
void pushup(int rt) {
    t[rt].sum = (t[lc].sum + t[rc].sum) % mod; // 记得取模
}

// 构建线段树
void build(int rt, int l, int r) {
    // 初始化标记
    t[rt].addlazy = 0;
    t[rt].mullazy = 1;
    // 如果是叶子节点
    if (l == r) {
        t[rt].sum = a[l] % mod; // 直接赋值并取模
        return;
    }
    int mid = (l + r) / 2;
    // 递归构建左右子树
    build(lson);
    build(rson);
    // 更新当前节点
    pushup(rt);
}

// 区间加法操作
void add(int rt, int l, int r, int x, int y, int z) {
    // 如果当前区间与目标区间无交集
    if (r < x || l > y) return;
    // 如果当前区间完全包含在目标区间内
    if (x <= l && r <= y) {
        // 更新sum和加法标记
        t[rt].sum = (t[rt].sum + (r - l + 1) * z) % mod;
        t[rt].addlazy = (t[rt].addlazy + z) % mod;
        return;
    }
    int mid = (l + r) / 2;
    // 下传标记
    pushdown(rt, l, r);
    // 递归处理左右子树
    add(lson, x, y, z);
    add(rson, x, y, z);
    // 更新当前节点
    pushup(rt);
}

// 区间乘法操作
void mul(int rt, int l, int r, int x, int y, int z) {
    // 如果当前区间与目标区间无交集
    if (r < x || l > y) return;
    // 如果当前区间完全包含在目标区间内
    if (x <= l && r <= y) {
        // 更新sum、加法标记和乘法标记
        t[rt].sum = (t[rt].sum * z) % mod;
        t[rt].addlazy = (t[rt].addlazy * z) % mod;
        t[rt].mullazy = (t[rt].mullazy * z) % mod;
        return;
    }
    int mid = (l + r) / 2;
    // 下传标记
    pushdown(rt, l, r);
    // 递归处理左右子树
    mul(lson, x, y, z);
    mul(rson, x, y, z);
    // 更新当前节点
    pushup(rt);
}

// 区间查询操作
ll query(int rt, int l, int r, int x, int y) {
    // 如果当前区间与目标区间无交集
    if (r < x || y < l) return 0;
    // 如果当前区间完全包含在目标区间内
    if (x <= l && r <= y) return t[rt].sum;
    int mid = (l + r) / 2;
    // 下传标记
    pushdown(rt, l, r);
    // 递归查询左右子树并求和
    ll sum = (query(lson, x, y) + query(rson, x, y)) % mod;
    return sum;
}

int main() {
    // 读取输入数据
    scanf("%lld%lld%lld", &n, &m, &mod);
    f(i, 1, n) scanf("%lld", &a[i]);
    // 构建线段树
    build(1, 1, n);
    // 处理每个操作
    while (m--) {
        int op, x, y, z;
        scanf("%d", &op);
        if (op == 1) { // 区间乘法
            scanf("%d%d%d", &x, &y, &z);
            mul(1, 1, n, x, y, z);
        } else if (op == 2) { // 区间加法
            scanf("%d%d%d", &x, &y, &z);
            add(1, 1, n, x, y, z);
        } else if (op == 3) { // 区间查询
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y) % mod);
        }
    }
    return 0;
}

//拖到真要輸出時再搞
//不然就用分配律處理下