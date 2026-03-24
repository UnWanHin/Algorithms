#include<bits/stdc++.h>
using namespace std;
int len;
const int N=1e6+5;
char str[N];
int sa[N];
int ranks[N];
int temp[N];
int k;
bool cmp(int a,int b)
{
    if(ranks[a]!=ranks[b])return ranks[a]<ranks[b];
    int ra=a+k<=len?ranks[a+k]:-1;
    int rb=b+k<=len?ranks[b+k]:-1;
    return ra<rb;
}
void solve()
{
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<=len;i++)
    {
        sa[i]=i;
        ranks[i]=i<len?str[i]:-1;
    }
    for( k=1;k<=len;k<<=1)
    {
        sort(sa,sa+len+1,cmp);
        temp[sa[0]]=0;
        for(int i=1;i<=len;i++)
        {
            temp[sa[i]]=temp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=len;i++)ranks[i]=temp[i];
    }
    for(int i=1;i<=len;i++)printf("%d ",sa[i]+1);
}
int main()
{
    solve();
    return 0;
}

//倍增法
//一直抓