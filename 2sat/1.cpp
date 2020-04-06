#include<bits/stdc++.h>
using namespace std;
#define ll long long
int th=0;
struct sta
{
    ll x,yv,v,pos;
    friend bool operator < (sta a,sta b)
    {
        return a.v>b.v;
    }
    sta (ll _x,ll _v,ll _pos,ll yv)
    {
        x=_x;v=_v;pos=_pos;
    }
}tmp[1000005];
ll ans[1000005];
bool cmp(sta a,sta b)
{

    return a.x<b.x;
}
int f[1000005];
void fi(int x)
{
    if(f[x]==x)return x;
    return f[x]=fi(f[x]);
}
void del(int x)
{
    used[x]=1;
    f[x]=fi(x-1);
}
int used[1000005];
int now[1000005];
int main ()//X
{
    memset(ans,0,sizeof(ans));
    memset(used,0,sizeof(used));
    memset(now,0,sizeof(now));
    #ifdef yyhao
    freopen( "in.txt","r",stdin);
    #endif // yyh
    int n;
    cin>>n;
    int hou=n-1;
    for(int i=0;i<n;i++)
    {
        f[i]=i;
        scanf("%lld",&tmp[i].x);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&tmp[i].yv);
    }
    sort(tmp,tmp+i,cmp);
    int tans=0;
    for(int i=0;i<n;i++)
    {
        tans+=x;
    }
    tans+=2*tmp[n-1].x;
    priority_queue<sta> pq;
    for(int i =0;i<n-1;i++)
    {
        pq.push( sta(0,tmp[i].yv,i,0));
    }
    if(n>1)
    pq.push( sta(0,tmp[i].yv+(tmp[i].x-tmp[i-1])*2,n-1 ,1));
    else pq.push( sta(0,tmp[i].yv+(tmp[i].x)*2,n-1 ,1));
    int th=0;
    while(!pq.empty())
    {
        sta top=pq.top();
        pq.pop();
        if(used[top.pos]==1 || now[top.pos]>top.x)
        {
            continue;
        }
        else
        {
            ans[th++]=tans-top.v;
            if(top.yv==1)
            {
                used[top.pos]=1;
                int qian=fi(top.pos-1);
                int zaiqian=fi(qian-1);

            }
            else
            {

            }
        }
    }
}
