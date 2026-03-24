#include<bits/stdc++.h>
#pragma G++ optimize(2)
#pragma G++ optimize("inline")
using namespace std;
int n,m,ans,id,h[105],match[105];
bool vis[105];
struct node{
    int v,ne;
}e[10005];
inline void add(int a,int b){
    e[++id]={b,h[a]},h[a]=id;
}
inline bool dfs(int u){
    for(int i=h[u];i;i=e[i].ne){
        int v=e[i].v;
        if(vis[v]){
            continue;
        }
        vis[v]=true;
        if(!match[v]||dfs(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int a,b;;){
        cin>>a>>b;
        if(a==-1&&b==-1){
            break;
        }
        add(a,b);
    }
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)){
            ans++;
        }
    }
    cout<<ans<<"\n";
    //与【模板】二分图最大匹配的区别
    for(int i=1;i<=n-m;i++){
        if(match[i+m]){
            cout<<match[i+m]<<" "<<i+m<<"\n";
        }
    }
    return 0;
}

//匈牙利算法
//直接開始匹，匹到就用