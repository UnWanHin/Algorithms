#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
int v[N][N];
int dp[N][N];//j瓶放到第i朵
int n,m;
int a,b,c;
int pre[N][N];
void print(int k,int pl){
    if(k==0) return;
    print(k-1,pre[k][pl]);
    printf("%d ",pl);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        dp[i][0]=-2e9;
        for(int j=1;j<=m;j++) scanf("%d",&v[i][j]),dp[i][j]=-2e9;
    }
    for(int j=0;j<=m;j++) dp[0][j]=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            for(int k=i-1;k<j;k++){
                if(dp[i][j]<dp[i-1][k]+v[i][j]){
                    dp[i][j]=dp[i-1][k]+v[i][j];
                    pre[i][j]=k;
                }
            }
        }
    }
    int ans=-2e9,pl;
    for(int j=1;j<=m;j++){
        if(ans<dp[n][j]){
            ans=dp[n][j];pl=j;
        }
    }
    printf("%d\n",ans);
    print(n,pl);
    return 0;
}
/*
3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20
*/
//輪着來，從1束花開始