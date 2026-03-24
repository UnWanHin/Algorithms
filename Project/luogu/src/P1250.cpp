#include<bits/stdc++.h>
#define N 30010
#define H 5010
using namespace std;
int n,h,ans;
struct SEG{
#define lc (x<<1)
#define rc (x<<1|1)
    int sum[N<<2],tag[N<<2];
    void pushup(int x){sum[x]=sum[lc]+sum[rc];}
    void pushdown(int x,int l,int r){
        if(!tag[x]) return;
        int mid=(l+r)>>1;
        sum[lc]=(mid-l+1)*tag[x],sum[rc]=(r-mid)*tag[x];
        tag[lc]=tag[rc]=tag[x],tag[x]=0;
    }
    int kth0(int x,int k,int l,int r){
        if(l==r) return l;
        pushdown(x,l,r);
        int mid=(l+r)>>1,lef0=mid-l+1-sum[lc];
        if(lef0>=k) return kth0(lc,k,l,mid);
        else return kth0(rc,k-lef0,mid+1,r);
    }
    void ser(int x,int a,int b,int v,int l,int r){
        if(a<=l&&r<=b) return tag[x]=v,sum[x]=(r-l+1)*v,void();
        pushdown(x,l,r);
        int mid=(l+r)>>1;
        if(a<=mid) ser(lc,a,b,v,l,mid);
        if(b>mid) ser(rc,a,b,v,mid+1,r);
        pushup(x);
    }
    int query(int x,int a,int b,int l,int r){
        if(a>b) return 0;
        if(a<=l&&r<=b) return sum[x];
        pushdown(x,l,r);
        int mid=(l+r)>>1,ans=0;
        if(a<=mid) ans+=query(lc,a,b,l,mid);
        if(b>mid) ans+=query(rc,a,b,mid+1,r);
        return ans;
    }
}tr;
struct Seg{int l,r,cnt;}a[H];
int main(){
    cin>>n>>h;
    for(int i=1;i<=h;i++) cin>>a[i].l>>a[i].r>>a[i].cnt;
    sort(a+1,a+1+h,[](Seg a,Seg b){return a.l>b.l;});
    for(int i=1;i<=h;i++){
        int sum=tr.query(1,a[i].l,a[i].r,1,n);
        if(sum<a[i].cnt){
            ans+=a[i].cnt-sum;
            int pos=tr.kth0(1,a[i].cnt-sum+a[i].l-1,1,n);
            tr.ser(1,a[i].l,pos,1,1,n);
        }
    }
    cout<<ans<<"\n";
    return 0;
}

//右邊往左邊開始排
//排重疊的
//貪心