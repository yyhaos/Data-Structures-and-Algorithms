//Problem Web:https://vjudge.net/problem/HDU-1385
/*
有意思的题目 点权+边权 迪杰斯特拉 字典序最小
*/
//#include<bits/stdc++.h>
#include<stdio.h>

//#include<ext/rope> //using __gnu_cxx
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
const ll N=1005;
ll a[N][N];
ll b[N];

ll dis[N];
ll dis2[N];
struct ed
{
    ll v,w;
    ed(ll _v=0,ll _w=0):v(_v),w(_w){}
    friend bool operator < (ed a, ed b)
    {
        return a.w>b.w;
    }
};
void di(ll u,ll v)
{
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[u]=0;
    priority_queue<ed> pq;
    pq.push(ed(u,0));
    while(!pq.empty()){
        ed tmp=pq.top();
        pq.pop();
        ll now=tmp.v; ll di=tmp.w;
        if(dis[now]>di)
            dis[now]=di;
        for(int i=1;i<=n;i++)
        {
            if(a[now][i]!=-1){
                if(i!=v)
                    if(dis[i] > di+a[now][i]+b[i]){
                        dis[i]=di+a[now][i]+b[i];
                        pq.push(ed(i,dis[i]));
                    }
                if(i==v){
                    if(dis[i] > di+a[now][i]){
                        dis[i]=di+a[now][i];
                        pq.push(ed(i,dis[i]));
                    }
                }
            }
        }
    }
}
void di2(ll u,ll v)
{
    for(int i=1;i<=n;i++){
        dis2[i]=INF;
    }
    dis2[u]=0;
    priority_queue<ed> pq;
    pq.push(ed(u,0));
    while(!pq.empty()){
        ed tmp=pq.top();
        pq.pop();
        ll now=tmp.v; ll di=tmp.w;
        if(dis2[now]>di)
            dis2[now]=di;
        for(int i=1;i<=n;i++)
        {
            if(a[i][now]!=-1){
                if(i!=v)
                    if(dis2[i] > di+a[i][now]+b[i]){
                        dis2[i]=di+a[i][now]+b[i];
                        pq.push(ed(i,dis2[i]));
                }
                if(i==v){
                    if(dis2[i] > di+a[i][now]){
                        dis2[i]=di+a[i][now];
                        pq.push(ed(i,dis2[i]));
                    }
                }
            }
        }
    }
}
void myget(ll u,ll v)
{
    di(u,v);

    di2(v,u);
//    for(int i=1;i<=n;i++){
//        printf("%lld ",dis[i]);
//    }
//    printf("\ndis2: ");
//    for(int i=1;i<=n;i++){
//        printf("%lld ",dis2[i]);
//    }
//    printf("\n");

    printf("From %lld to %lld :\n",u,v);
    printf("Path: %lld",u);
    int now=u;
    while(now!=v) //找关键路径 两点一线 查询中间的点
    {
        printf("-->");
        for(int i=1;i<=n;i++){
            if(i==u || a[now][i]==-1)continue;

            if(i==v){
           //     printf("  now:%lld v:%lld :dis[now]%lld + a[now][i]%lld = dis[v]%lld\n",now,v,dis[now],a[now][i],dis[v]);
                if(dis[now]+a[now][i]==dis[v] )
                {
                    now=v;break;
                }
            }
            else if( dis[now]+a[now][i]+dis2[i]==dis[v] ){
                now=i;break;
            }
        }
        printf("%lld",now);
    }
    printf("\n");
    printf("Total cost : %lld\n\n",dis[v]);
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll u,v;
    while(~scanf("%lld",&n))
    {
        if(n==0)break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",b+i);
        }

        while(~scanf("%lld %lld",&u,&v))
        {
            if(u==-1)break;
            myget(u,v);
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

