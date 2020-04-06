//Problem Web:https://vjudge.net/problem/UVA-284
//uva 284
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
#define input 1
#define output 2
#define andg 3
#define org 4
#define notg 5
struct grid
{
    int th;
    int ty;
    vector <int> nxt;
    void show()
    {
        cout<<ty<<" "<<th<<" "<<nxt.size()<<endl;
        if(nxt.size())
        {
            for(int i=0;i<nxt.size();i++)
            {
                cout<<nxt[i]<<" ";
            }
            cout<<endl;
        }
    }
}g[155];
int ji[150];
int ith=0;
int ou[150];
int oth=0;
int te[105],cnt[150];
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
    if(ii!=1)
        cout<<"\n\n";
    ith=0;oth=0;
    for(int i=0;i<100;i++)
    {
        g[i].th=0;
        g[i].ty=0;
        g[i].nxt.clear();
    }
#endif // use_t
string str;
int now=-1;
    while(cin>>str && str!=string("end"))
    {
        int len=str.length();
        if(str==string(".."))
        {
            now=-1;
            continue;
        }

        int pos=(str[0]-'0')*10+str[1]-'0';
        if(len==3)
        {
            now=pos;
            if(str[2]=='i')
            {
                g[pos].ty=input;
                g[pos].th=ith;
                ji[ith]=pos;
                ith++;
            }
            else if(str[2]=='o')
            {
                g[pos].ty=output;
                g[pos].th=oth;
                ou[oth]=pos;
                oth++;
            }
            else if(str[2]=='&')
            {
                g[pos].ty=andg;
            }
            else if(str[2]=='|')
            {
                g[pos].ty=org;
            }
            else if(str[2]=='!')
            {
                g[pos].ty=notg;
            }
            else
            {
                cout<<"3 len error:"<<str<<endl;
            }
        }
        else
        {
            if(now==-1)
            {
                cout<<"nxt error:"<<str<<endl;
            }
            else
            {
                g[now].nxt.push_back(pos);
            }
        }
    }
//    for(int i=0;i<3;i++)
//    {
//        for(int j=0;j<4;j++)
//        {
//            cout<<i<<","<<j<<":";
//            g[i*10+j].show();
//        }
//    }
    int ttt;
    cin>>ttt;
    while(ttt--)
    {
        for(int i=0;i<100;i++)
        {
            cnt[i]=0;
            te[i]=0;
            if(g[i].ty==andg)
            {cnt[i]=2;
                te[i]=1;
            }
            if(g[i].ty==org)
            {cnt[i]=2;
                te[i]=0;
            }
        }
        cin>>str;
        stack<int> ss;
        int ru=str.size();
        for(int i=0;i<ru;i++)
        {
            int inow=ji[i];
            te[inow]=str[i]-'0';
            ss.push(inow);
        }
        while(!ss.empty())
        {
            int no=ss.top();
            ss.pop();
//            printf("%02d _ %d _ %d\n",no,te[no],g[no].nxt.size());
            if(g[no].nxt.size()==0)
            {
                continue;
            }
            int si=g[no].nxt.size();
            for(int i=0;i<si;i++)
            {
                int nxt=g[no].nxt[i];
                if(g[nxt].ty==andg)
                {
                    cnt[nxt]--;
                    if(te[no]==0)
                    {
                        te[nxt]=0;
                    }
                    if(cnt[nxt]==0)ss.push(nxt);
                }
                else if(g[nxt].ty==org)
                {
                    cnt[nxt]--;
                    if(te[no]==1)
                    {
                        te[nxt]=1;
                    }
                    if(cnt[nxt]==0)ss.push(nxt);
                }
                else if(g[nxt].ty==notg)
                {
                    te[nxt]=1-te[no];
                    ss.push(nxt);
                }
                else
                {
                    te[nxt]=te[no];
                    ss.push(nxt);
                }
            }
        }

        for(int i=0;i<oth;i++)
        {

            cout<<te[ou[i]];
        }
         if(ttt!=0)
        {
            cout<<"\n";
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

