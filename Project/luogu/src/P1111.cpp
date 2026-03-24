#include <bits/stdc++.h>
using namespace std;
int father[1005];
struct road
{
    int x;
    int y;
    int t;
}r[100005];
int cmp(road x,road y)
{
    return x.t<y.t;
}
int find(int x)
{
    if(father[x]==x) return x;
    else return find(father[x]);
}
void union_set(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    father[fy]=fx;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>r[i].x>>r[i].y>>r[i].t;
    }
    sort(r+1,r+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find(r[i].x)!=find(r[i].y)) 
        {
            union_set(r[i].x,r[i].y);
            n--;
        }
        if(n==1)
        {
            cout<<r[i].t;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}

//應從最快的開始修
//修一次就檢查一次是否全部連通
//通了就合并
