#include<bits/stdc++.h>
int n,a,b,k[201];
bool f,u[201];//u 是标记
int ri(){
    int x=0;
    char c=getchar(),f=1;
    while(c<'0'||c>'9'){
        if(c=='-')
            f=-f;
        c=getchar();
    }
    while(c<='9'&&c>='0')
        x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
struct node{
    int x,y;
};
std::queue<node>q;
int bfs(){
    q.push(node{a,0});//入队
    u[a]=1;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;
        q.pop();
        if(x==b)
            return y;//到了 B
        int xn=x+k[x],yn=y+1;
        if(xn<=n&&xn>0&&!u[xn])//上
            q.push(node{xn,yn}),u[xn]=1;
        xn-=2*k[x];
        if(xn<=n&&xn>0&&!u[xn])//下
            q.push(node{xn,yn}),u[xn]=1;
    }
    return-1;
}
int main(){
    n=ri(),a=ri(),b=ri();
    for(int i=1;i<=n;i++)
        k[i]=ri();
    printf("%d",bfs());
    return 0;
}

//quene
//去過的進quene
//反之