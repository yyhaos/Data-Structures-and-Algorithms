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
ll w[1005];
ll v[1005];
ll dp[105][105];
ll dpp(ll yu,ll c)
{
    ll ans=v[yu];
    mem(dp,0);
    ll tmp=0;

    for(int nowc=0;nowc<=c;nowc++)
    {
        for(int k=0;k<n;k++)
        {
            if(k>0)
            {
                dp[k][nowc]=dp[k-1][nowc];
            }

            if(k==yu)
            {
                continue;
            }
            if(nowc>=w[k]&& k>0)
            {
                dp[k][nowc]=max(dp[k][nowc],dp[k-1][nowc-w[k]]+v[k]);
            }
            else if(nowc>=w[k])
            {
                dp[k][nowc]=max(dp[k][nowc],v[k]);
            }
            tmp=max(tmp,dp[k][nowc]);
        }
    }
//    cout<<yu<<" "<<tmp+ans<<endl;
//    for(int nowc=0;nowc<=c;nowc++)
//    {
//        for(int k=0;k<n;k++)
//        {
//            cout<<dp[k][nowc]<<" ";
//        }
//        cout<<endl;
//    }
    return tmp+ans;
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
    while(cin>>n)
    {
        mem(v,0);
        mem(w,0);
        if(!n)
            break;
            ll h;
        cin>>m>>h;
        mem(dp,0);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",w+i,v+i);
        }
        ll ans=0;
        if(h>0)
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dpp(i,m+h-1));
        }
        else
        {
            ans=max(ans,dpp(n,m));
        }
         cout<<ans<<endl;
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}
