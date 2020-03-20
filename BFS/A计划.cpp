//Problem Web:https://vjudge.net/problem/HDU-2102
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
char M[2][15][15];
ll dis[2][15][15];
int fx[4]={0,0,1,-1};
int fy[4]={1,-1,0,0};
bool ok(int x,int y,int c)
{
    if(c<0 || c>1 || x<0 || y<0 || x>=n || y>=n || M[c][x][y]=='*')
        return false;return true;
}
int tr(int x,int y,int c)
{
    return c*100+y*10+x;
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
ll tt;
cin>>n>>m>>tt;
for(int j=0;j<2;j++)
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<15;k++)
        {
            dis[j][i][k]=999;
        }
        scanf("%s",M[j][i]);
      //  cout<<M[j][i]<<endl;
    }
    queue<int> qq;
    qq.push_back(0);
    dis[0][0][0]=0;
    while(!qq.empty())
    {
        int tq=qq.front();
        qq.pop();
        int ceng=tq/100;
        int x=tq%10;
        int y=(tq/10)%10;
        for(int i=0;i<4;i++)
        {
            int nx=x+fx[i];
            int ny=y+fy[i];
            if(ok(nx,ny,c) && dis[c][nx][ny]==999)
            {
                dis[c][nx][ny]=dis[c][x][y]+1;
                tq.push_back(tr(x,y,c));
            }
        }
        if(M[c][x][y]=='#')
        {
            int nc=1-c;
            if(ok(x,y,nc) && dis[])
        }
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

