//P2018 消息传递
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define fo(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int mxn=1005;
vector <int> f[mxn];
int n,x,mx=1e8;
int ans[mxn],dp[mxn],du[mxn];
inline void dfs(int u,int fa)
{
    if(fa && du[u]==1)
        return;
    int tmp[mxn],cnt=0;
    for(int i=0;i<f[u].size();i++)
    {
        int v=f[u][i];
        if(v==fa) continue;
        dfs(v,u);
        tmp[++cnt]=dp[v];
    }
    sort(tmp+1,tmp+cnt+1);
    fo(i,1,cnt) dp[u]=max(dp[u],tmp[i]+cnt-i+1);
}
int main()
{
    scanf("%d",&n);
    fo(i,2,n)
    {
        scanf("%d",&x);
        f[x].push_back(i);
        f[i].push_back(x);
    }
    fo(i,1,n)
    {
        memset(dp,0,sizeof dp);
        dfs(i,0);
        ans[i]=dp[i];
        mx=min(mx,ans[i]);
    }
    printf("%d\n",mx+1);
    fo(i,1,n) if(ans[i]==mx) printf("%d ",i);
    printf("\n");
    return 0;
}

//並行
//遞歸