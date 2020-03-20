//Problem Web:https://vjudge.net/problem/UVA-10944
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
const ll ma=(1LL<<16);
ll dis[25][25][ma];
struct sta
{
    ll x,y,len,has,s;
    sta(){}
    sta(ll _x,ll _y, ll _l=0,ll _has=0,ll _s=0)
    {
        x=_x;y=_y;len=_l;has=_has;s=_s;
    }
};
inline ll tr(sta a)
{
    return a.x*100+a.y;
}
inline bool ok(sta a)
{
    if(a.x<0 || a.x>=n || a.y<0 || a.y>=m)return false;return true;
}
char M[25][25];
int fx[8]={-1,-1,0,1,1,1,0,-1};
int fy[8]={0,1,1,1,0,-1,-1,-1};
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
#endif
//cout<<20<<" "<<20<<endl;
//for(int i=0;i<20;i++)
//{
//    for(int j=0;j<20;j++)
//    {
//        cout<<'.';
//    }
//    cout<<endl;
//}
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

        memset(dis,0,sizeof(dis));
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",M[i]);
//            cout<<M[i]<<endl;
        }ll sx,sy;
        map<ll,ll> mp;
        queue<sta> qq;
        ll cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]=='L')
                {sx=i,sy=j;
                    qq.push(sta(i,j,0,0,0));
                }
                if(M[i][j]=='#')
                {
                    mp[tr(sta(i,j,0))]=cnt++;
                }
            }
        }
        sta now;
        ll nx,ny,nlen,ns,nhas;
        while(!qq.empty())
        {
            now=qq.front();
            qq.pop();
//            cout<<now.x<<" "<<now.y<<" "<<now.len<<" "<<now.s<<endl;
            if(now.x==sx && now.y==sy && now.has==cnt)
            {
                printf("%d\n",now.len);
                while(!qq.empty())
                    qq.pop();
                break;
            }

            //if(dis[now.x][now.y][now.has]!=0 )continue;

            //dis[now.x][now.y][now.has]=now.len;

            for(int i=0;i<8;i++)
            {
                nx=fx[i]+now.x;
                ny=fy[i]+now.y;
                nlen=now.len+1;
                ns=now.s;
                nhas=now.has;
//                cout<<nx<<"  :::   "<<ny<<endl;
                if(!ok(sta(nx,ny)))
                    continue;
                if(M[nx][ny]=='#')
                {
                    ll th=mp[tr(sta(nx,ny))];
//                    cout<<th<<" "<<now.s<<" "<<(1LL<<th)<<endl;
                    if( (now.s & (1LL<<th)) ==0)
                    {
//                    cout<<th<<endl;
                        ns|=(1LL<<th);
                        nhas++;
                    }
                    else
                    {

                    }
                }
                sta nn(nx,ny,nlen,nhas,ns);
                if(dis[nx][ny][ns]==0)
                {
//                    cout<<"ru"<<endl;
dis[nx][ny][ns]=1;
                    qq.push(nn);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<(1<<cnt);k++)
                {
                    dis[i][j][k]=0;
                }
            }
        }
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

