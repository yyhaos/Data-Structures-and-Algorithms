//Problem Web:http://www.bnuoj.com/contest_show.php?cid=9509#problem/B
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
ll ab[250005];
ll A,B,C;
ll a[505],b[505],c[595];
void ge(ll a,ll A[])
{
    for(int i=0;i<a;i++)
    {
        scanf("%lld",A+i);
    }
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
while(~scanf("%lld%lld%lld",&A,&B,&C))
{
#endif // use_t

    ge(A,a);
    ge(B,b);
    ge(C,c);
    ll cnt=0;
    rep(i,0,A-1)
    rep(j,0,B-1)
    {
        ab[cnt++]=a[i]+b[j];
    }

    sort(ab,ab+A*B);

    ll qu;
    ll tar=0,tmp;
    scanf("%lld",&qu);
    printf("Case %lld:\n",ii++);
    ll flag;
    while(qu--)
    {
        scanf("%lld",&tar);
        flag=0;
        rep(i,0,C-1)
        {
            if(flag)
                break;
            tmp=tar-c[i];
            ll pos=lower_bound(ab,ab+A*B,tmp)-ab;
            if(ab[pos]==tmp)
            {
                flag=1;
            }
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
