//Problem Web:https://ac.nowcoder.com/acm/challenge/terminal
#include<bits/stdc++.h>
#include<ext/rope>
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
#define use_t 1
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
ll w[1005];
ll v[1005];
ll dp[105][105];

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
ll c,z;
    cin>>c>>z>>m;
    ll cnt=0;
    ll tar=ksm(c,z);
    for(int a=1;a<=m;a++)
    {
        for(int x=0;x<=m;x++)
        {
            for(int b=1;b<=m;b++)
            {
                for(int y=0;y<=m;y++)
                {
                    if(ksm(a,x) * ksm(b,y)==tar)
                    {
                        cnt++;
                        cout<<a<<"^"<<x<<"*"<<b<<"^"<<y<<"="<<ksm(a,x)<<"*"<<ksm(b,y)<<endl;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;

#ifdef use_t
}
#endif // use_t
    return 0;
}

