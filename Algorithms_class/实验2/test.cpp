#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll tx[]={1,2,2,1,-1,-2,-2,-1};//too slow for 7,8
const ll ty[]={2,1,-1,-2,-2,-1,1,2};
//const ll tx[]={-1,-2,-2,-1,1,2,2,1};
//const ll ty[]={2,1,-1,-2,-2,-1,1,2};
ll M[200][200];
ll over=0;
void show(ll n,ll m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //cout<<1<<endl;
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void init()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            M[i][j]=0;
    over=0;
}
ll cnt(ll x, ll y,ll n,ll m)
{
    ll cnt=0;
    for(int i=0;i<8;i++)
    {
        ll nx=x+tx[i];
        ll ny=y+ty[i];
        if(nx<1 || nx>n || ny<1||ny>m)
                continue;
        if(M[nx][ny]==0)
            cnt++;
    }
    return cnt;
}
struct Tar
{
    ll th,wei;
    Tar(ll t=0, ll w=0)
    {
        th=t;
        wei=w;
    }
    friend bool operator < (Tar a,Tar b)
    {
        return a.wei<=b.wei;
    }
};
void dfs(ll th,ll x, ll y,ll n,ll m)
{
   // if(th==1)
  //  cout<<th<<" "<<x<<" "<<y<<endl;
    if(th==0)
    {
        M[x][y]=1;
        dfs(1,x,y,n,m);
    }
    else if(th==n*m)
    {
        over=1;
        show(n,m);
    }
    else
    {
        if(over==1)
            return ;
        ll nx,ny;
        ll t=0;
        Tar tar[8];
        for(int i=0;i<8;i++)
        {
            nx=x+tx[i];
            ny=y+ty[i];
            if(nx<1 || nx>n || ny<1||ny>m)
                continue;
            if(M[nx][ny]!=0)
                continue;
            //M[nx][ny]=1;
            tar[t++]=Tar(i,cnt(nx,ny,n,m));
            //M[nx][ny]=0;
        }
        //cout<<t<<endl;
        if(t==0)
            return ;
        sort(tar,tar+t);
//        if(th==1)
//        for(int i=0;i<t;i++)
//        {
//            cout<<tar[i].th<<" "<<tar[i].wei<<endl;
//        }
        for(int i=0;i<t;i++)
        {
            ll nx=x+tx[tar[i].th];
            ll ny=y+ty[tar[i].th];
            M[nx][ny]=th+1;
            dfs(th+1,nx,ny,n,m);
            M[nx][ny]=0;
        }
    }
}
int main ()
{
    int n=8;
    //freopen("result.txt","w",stdout);
    for(int i=1;i<=(1+n)/2;i++)
    {
        for(int j=i;j<=(1+n)/2;j++)
        {
            cout<<i<<" * " << j<<endl;
            init();
            dfs(0,i,j,n,n);
            if(over==0)
                cout<<u"吴姐"<<endl;
            cout<<endl;
        }
    }
    return 0;
}
