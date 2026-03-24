#include<bits/stdc++.h>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<map>
#define ll long long
#define lhs printf("\n");
using namespace std;
const int N=1e5+10;
const int M=2024;
const int inf=0x3f3f3f3f;
int n,m;
vector<int> a[N];
vector<int> b[N];
struct node
{
    int sum,maxx;
}dis[N];
void spfa()
{
    for(int i=1;i<=N;i++)
    {
        dis[i].maxx=0;
        dis[i].sum=inf;
    }
    queue<int> q;
    q.push(1);
    dis[1].sum=0;
    while(q.size())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<a[now].size();i++)
        {
            int v=a[now][i];
            int w=b[now][i];
            if(w>dis[now].maxx)
            {
                if(dis[v].sum>dis[now].sum+w+w-dis[now].maxx)
                {
                    dis[v].sum=dis[now].sum+w+w-dis[now].maxx;
                    dis[v].maxx=w;
                    q.push(v);
                }
            }
            else
            {
                if(dis[v].sum>dis[now].sum+w)
                {
                    dis[v].maxx=dis[now].maxx;
                    dis[v].sum=dis[now].sum+w;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x].push_back(y);
        b[x].push_back(z);
        a[y].push_back(x);
        b[y].push_back(z);
    }
    spfa();
    printf("%d\n",dis[n].sum);
    //	for(int i=1;i<=n;i++)
    //	{
    //		cout<<dis[i].sum<<" "<<dis[i].maxx<<"\n";
    //	}
    return 0;
}
//BFS
//Dijkstra 跑路徑出來，然後如果到同一位置就取最小的
/*
7 8
1 2 114
2 3 200
1 3 100
3 4 5
4 6 10
4 5 20
5 7 30
4 7 40
*/

