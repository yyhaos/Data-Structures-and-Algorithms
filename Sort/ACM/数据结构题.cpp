//Problem Web:https://ac.nowcoder.com/acm/contest/917/H
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
const ll q=20180623;
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
ll a[100005];
vector <ll> X[20005];
const ll off=10000;
ll fi(ll l,ll r,ll x)
{
    if(x<-10000 || x>10000)
        return 0;
    else
        x+=off;
    ll si=X[x].size();
    //cout<<x<<" "<<si<<endl;
    if(si)
    return upper_bound(X[x].begin(),X[x].end(),r)-lower_bound(X[x].begin(),X[x].end(),l);
    return 0;
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


    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        X[a[i]+off].push_back(i+1);
    }

//    for(ll i=0;i<=20000;i++)//才意识到不用ort ai的位置们就已经有序了
//    {
//        ll si=X[i].size();
//        if(si)
//        {
//            sort(X[i].begin(),X[i].end());
//            for(int j=0;j<si;j++)
//                printf("%lld ",X[i][j]);
//            printf("\n");
//        }
//    }
    ll l,r,l1,r1,x;
    ll fa=1;
    while(m--)
    {
        if(!fa)
            printf("\n");
        fa=0;
        scanf("%lld%lld%lld%lld%lld",&l,&r,&l1,&r1,&x);
        if(l>r)swap(l,r);if(l1>r1)swap(l1,r1);
        printf("%lld\n%lld\n%lld",fi(l,r,x),fi(l1,r1,x),fi(l,r,x)*fi(l1,r1,x)%q);
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
