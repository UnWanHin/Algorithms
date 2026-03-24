/* P1080 [NOIP2012 提高组] 国王游戏 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10000 + 1;
struct Node {
    int left, right;
} a[N];

bool cmp(Node &a, Node &b)
{
    return a.left * a.right < b.left * b.right;
}

// 高精度乘法
vector<int> bigint_mul(vector<int> &a, int b)
{
    vector<int> c;
    int r = 0;
    for (int i = 0; i < a.size() || r; i++) {
        if (i < a.size()) r += a[i] * b;
        c.push_back(r % 10);
        r /= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

// 高精度除法
vector<int> bigint_div(vector<int> &a, int b, int &r)
{
    vector<int> c;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        r *= 10, r += a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

// 高精度最大值
vector<int> bigint_max(vector<int> a, vector<int> b)
{
    if (a.size() > b.size()) return a;
    else if (a.size() < b.size()) return b;
    if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend()))
        return a;
    else
        return b;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i].left >> a[i].right;
    sort(a + 1, a + 1 + n, cmp);

    vector<int> t(1, a[0].left);
    vector<int> ans(1, 0);
    int r;
    for (int i = 1; i <= n; i++) {
        ans = bigint_max(ans, bigint_div(t, a[i].right, r));
        t = bigint_mul(t, a[i].left);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}

//axb
//權重