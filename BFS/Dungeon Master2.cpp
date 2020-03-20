//#include<bits/stdc++.h>
//#include<ext/rope>
//using namespace __gnu_cxx;
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define int long long
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define pb push_back
#define fi first
#define se second
//#define use_t 1
const double pi=acos(-1.0);
const double eps=1e-8;
const ll inf = 0x3f3f3f3f;
const ll maxn=1e5+7;
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)ans=ans*a%mod;
        a=a*a%mod;
        b/=2LL;
    }
    return ans;
}
char mp[40][40][40];
int vis[40][40][40];
int l,r,c;
struct node{
	int x,y,z,dis;
	node(){}
	node(int q,int w,int e,int d){
		x=q;y=w;z=e;dis=d;
	}
	friend bool operator < (node a,node b){
		return a.dis>b.dis;
	}
};
priority_queue<node> pq;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
signed main ()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
#ifdef yyhaos
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif



#ifdef use_t
ll t;
ll tt=1;
cin>>t;
for(tt=1;tt<=t;tt++)
{
#endif // use_t
while(cin>>l>>r>>c){
	string s;
	if(l==0&&r==0&&c==0)break;
	mem(vis,0);
	for(int i=0;i<l;++i){
		for(int j=0;j<r;++j){
			for(int k=0;k<c;++k){
				cin>>mp[i][j][k];
			}
		}
	}
	/*
	for(int i=0;i<l;++i){
		for(int j=0;j<r;++j){
			cout<<mp[i][j]<<endl;
		}
	}
	*/
	while(!pq.empty()) pq.pop();
	for(int i=0;i<l;++i){
		for(int j=0;j<r;++j){
			for(int k=0;k<c;++k){
				if(mp[i][j][k]=='S') pq.push(node(i,j,k,0));
			}
		}
	}
	int fl=0;
	while(!pq.empty()){
		node th=pq.top();
		int tx=th.x;
		int ty=th.y;
		int tz=th.z;
		int dis=th.dis;
		pq.pop();
		for(int i=0;i<6;++i){
			if(vis[tx+dx[i]][ty+dy[i]][tz+dz[i]]!=0)continue;
			if(mp[tx+dx[i]][ty+dy[i]][tz+dz[i]] == 'E'){
				cout<<"Escaped in "<<dis+1<<" minute(s).\n";
				fl=1;
				break;
			}

			if( mp[tx+dx[i]][ty+dy[i]][tz+dz[i]]=='#'|| tx+dx[i]<0||tx+dx[i]>=l||ty+dy[i]<0||ty+dy[i]>=r||tz+dz[i]<0||tz+dz[i]>=c       ) continue;
			pq.push(node(tx+dx[i],ty+dy[i],tz+dz[i],dis+1));
			vis[tx+dx[i]][ty+dy[i]][tz+dz[i]]++;
		}
		if(fl)break;
	}

	if(!fl)cout<<"Trapped!\n";

}
#ifdef use_t
}
#endif // use_t
return 0;
}
