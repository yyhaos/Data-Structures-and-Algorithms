//Problem Web:https://vjudge.net/problem/UVA-1549

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
ll D(ll r)
{
    ll x,y,cnt=0;
    for(x=-r;x<=r;x++)
    {
        for(y=-r;y<=r;y++)
        {
            if(x*x+y*y<=r*r)
                cnt++;
        }
    }
    return cnt;
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

    // n;
while(cin>>n){
    ll ans=0;
    ll r=n;
    for(ll i=0;i<=n;++i){
        while(r*r+i*i>n*n)r--;
        ans+=r;
    }
    ans=4*ans+1;
    cout<<n<<"\n"<<ans<<"\n";
}




#ifdef use_t
}
#endif // use_t
    return 0;
}

