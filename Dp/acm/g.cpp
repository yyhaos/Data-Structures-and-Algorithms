//Problem Web:http://www.bnuoj.com/contest_show.php?cid=9505#problem/G
#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

#define ll long long
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define mem(x,y) memset(x,y,sizeof(x))

#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 10000000;
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
string str[100005];
ll dircnt=4;

ll dis[1000005];
//ll dis2[1005][1005];
char zhang='#';
struct pos
{
    ll x,y;
    pos(ll _x=0,ll _y=0):x(_x),y(_y){}
    friend bool operator == (pos a,pos b){
        return a.x==b.x && a.y==b.y;
    }
    friend pos operator + (pos a,pos b){
        return pos(a.x+b.x,a.y+b.y);
    }
    bool isok(){
        if(x<0 || y<0 || x>=n || y>=m || str[x][y]==zhang)
            return false;
        return true;
    }
};
pos dir[100];

struct state
{
    pos p;
    ll sta;
    ll th;
    state(ll _x=0LL,ll _y=0,ll _s=0,ll _th=0):p(_x,_y),sta(_s),th(_th){}

    state(pos _p,ll _s=0,ll _th=0):p(_p),sta(_s),th(_th){}

    friend bool operator == (state a,state b){
        return a.p==b.p && a.sta==b.sta && a.th==b.th;
    }
};
void init()
{
    rep(i,0,n)
    rep(j,0,m)
    dis[i][j]=INF;
}
void solve()
{
    init();
    pos s,e;
    queue<state>qq;
   // qq.push(state(s,0,0));
    rep(i,0,n-1)
    rep(j,0,m-1)
    {
        if(str[i][j]==st)
            qq.push(state(i,j,1,0));
        if(str[i][j]==ed)
            e=pos(i,j);
    }

    while(!qq.empty())
    {
        state t=qq.front();
        qq.pop();

        if(dis[t.p.x][t.p.y]!=INF)
            continue;
        #ifdef yyhao
        cout<<t.p.x<<" "<<t.p.x<<"="<<t.th<<endl;
        #endif // yyhao
        dis[t.p.x][t.p.y]=t.th;
        rep(i,0,dircnt-1)
        {
            pos nxt=t.p+dir[i];
            if(nxt.isok())
            {
                qq.push(state(nxt,0,t.th+1));
            }
        }
    }
    #ifdef yyhao
    cout<<"步数矩阵:"<<endl;
    rep(i,0,n-1)
    {
        rep(j,0,m-1)
            if(dis[i][j]!=INF)
            cout<<dis[i][j]<<' ';
            else cout<<'-'<<' ';
            cout<<endl;
    }
   // cout<<dis[0][2]<<" ==?== "<<dis[e.x][e.y]<<" "<<e.x<<" "<<e.y<<endl;
    #endif // yyhao
//    if(dis[e.x][e.y]<INF)
//        cout<<dis[e.x][e.y];
//    else cout<<"-1";
}

int main ()
{
    dir[0].x=0;
    dir[1].x=-1;
    dir[2].x=1;
    dir[3].x=0;
    dir[0].y=1;
    dir[1].y=0;
    dir[2].y=0;
    dir[3].y=-1;
#ifdef yyhao
    freopen("in.txt","r",stdin);
    cout<<"方向:";
    rep(i,0,4)
    {
        cout<<dir[i].x<<" "<<dir[i].y<<endl;
    }
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n;
    m=n;
    if(n==0 || m==0)
    {
        cout<<"No"<<endl;
        continue;
    }
    getchar();
    rep(i,0,n-1)
    {
        cin>>str[i];
    }

    solve();



#ifdef use_t
}
#endif // use_t
    return 0;
}



