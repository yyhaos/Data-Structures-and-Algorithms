//Problem Web:https://vjudge.net/problem/UVA-11780
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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
double ans[1005];
int ne[1005];int cnt;
int fa[1005];
double tmp;
double y;

void dfs(int now,int st,int v)
{
    if(now==0)
    {
        tmp=min(tmp,fabs(y-v));
    }
    for(int i=st;i<cnt;i++)
    {
        if(fa[i]<=now)
        {
            dfs(now-i,i,v+fa[i+1]);
        }
        else
        {
            break;
        }
    }
    return ;
}
double get(double i)
{
    y=i*1.6;
    tmp=9999999999.9;
    dfs(i,1,0);
    return tmp;
}
int main ()
{
    cnt=0;
    int a=0,b=1;
    for(;a<=1000;)
    {
       ne[a]=b;
        int ta=a;
        a=b;
        b=ta+b; fa[cnt++]=a;
    }
//    for(int i=0;i<cnt;i++)
//    {
//        cout<<i<<" "<<fa[i]<<endl;
//    }
//    for(int i=1;i<=1000;i++)
//    {
//        ans[i]=get(i);
//        cout<<i<<" "<<ans[i]<<endl;
//    }
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
double aa[5]={0.4,0.2,0.2,0.4,0};
    while(cin>>n)
    {if(n==0)break;
        printf("%.2f\n",aa[(n-1)%5]);
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

