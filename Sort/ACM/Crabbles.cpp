//Problem Web:https://vjudge.net/problem/UVA-10999
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
//#define mp make_pair
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

#define ull unsigned long long
ll t,n,m;
char tmp[15];
char str[200000];
map<ull, int> mp;
int used[10];
int val[10];
char ti[15];
int ans;
char ts[15];
ull k=37;
ull ha(char tmp[15])
{
    ull stt=1;
    for(int i=0;i<10;i++)
    {
        stt*=k;
        stt+=tmp[i];
    }
    return stt;
}
void dfs(int x)
{
    if(x==m)
    {

        int cnt=0;
        int tv=0;
        memset(ts,0,sizeof(ts));
        for(int i=0;i<m;i++)
        {
            if(used[i]==1)
            {
                ts[cnt++]=ti[i];
                tv+=val[i];
            }
        }
        ts[cnt]='\0';
        if(cnt)
        {
            sort(ts,ts+cnt);
            if(mp[ha(ts)]!=0)
            {
                ans=max(ans,tv);
//                for(int i=0;i<m;i++)
//                {
//                    cout<<" "<<used[i];
//                }
//                cout<<endl;
////                cout<<tv<<" "<<ha(ts)<<" "<<ts<<endl;
            }
        }
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            used[x]=i;
            dfs(x+1);
        }
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
cin>>n;
for(int i=0;i<n;i++)
{
    mem(tmp,0);
    scanf("%s",str);
    int l=strlen(str);
    if(l>=11)continue;
    strcpy(tmp,str);
    sort(tmp,tmp+l);
    mp[ha(tmp)]=1;
//    cout<<tmp<<endl;
//    cout<<ha(tmp)<<endl;
}
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    scanf("%d\n",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%c %d\n",ti+i,val+i);
//        cout<<ti[i]<<" "<<val[i]<<endl;
    }
    ans=0;
    dfs(0);
    printf("%d\n",ans);





#ifdef use_t
}
#endif // use_t
    return 0;
}

