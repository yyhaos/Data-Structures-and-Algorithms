//Problem Web:https://vjudge.net/problem/UVA-11997
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
int s[1000][1000];
int zeng[1000000];
struct add
{

    int v,pos;
    add(){}
    add(int _v,int _p){
        v=_v;pos=_p;
    }
    friend bool operator < (add a, add b)
    {
        return a.v>b.v;
    }
};
int cnt[1000];
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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        int k=n;
        for(int i=1;i<=n;i++)
        sort(s[i]+1,s[i]+1+n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",s[i][j]);
            }
            cnt[i]=1;
            printf("\n");
        }
        priority_queue<add> pq;
        int ans=0;
        //int cnt=0;
        for(int i=1;i<=n;i++)
        {
            ans+=s[i][1];
            pq.push(add(s[i][2]-s[i][1],i));
        }
        printf("%d",ans);
        for(int i=2;i<=k;i++)
        {
            ans+=pq.top().v;
            int tp=pq.top().pos;
            pq.pop();
            if(cnt[tp]!=n)
            {
                cnt[tp]++;
                pq.push(add(s[tp][cnt[tp]]-s[tp][cnt[tp]-1],tp));
            }
            printf(" %d",ans);
        }
        printf("\n");


    }


#ifdef use_t
}
#endif // use_t
    return 0;
}

