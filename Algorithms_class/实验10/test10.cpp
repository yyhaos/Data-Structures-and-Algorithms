#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge
{
    ll w,v;
    edge(ll _w=0,ll _v=0)
    {
        w=_w;
        v=_v;
    }

    friend bool operator < (edge a, edge b)
    {
        return a.w>b.w;
    }
    void show()
    {
        cout<<v<<"("<<w<<")\t";
    }
};
ll lmaxn=100;
vector < edge > M[100005];
ll dis[100005];
void init(ll n,ll m)
{
    for(int i=1;i<=n;i++)
    {
        M[i].clear();
        dis[i]=n*lmaxn;
    }
    ll u,v,w;
    while(m--)
    {
        u=rand()%n+1;
        v=rand()%n+1;
        w=rand()%lmaxn+1;
       // cout<<u<<" "<<v<<" "<<w<<endl;
        M[u].push_back(edge(w,v));
        M[v].push_back(edge(w,u));
    }
}
void Di(ll st ,ll n, ll m)
{
    priority_queue<edge>pq;
    pq.push(edge(0,st));
    edge top;
    cout<<"下面是Di算法的过程，以"<<st<<"为起点"<<endl;
    while(!pq.empty())
    {
        top=pq.top();
        pq.pop();
     //   cout<<top.v<<" "<<top.w<<endl;
        if(dis[top.v]!=n*lmaxn)
            continue;
        cout<<"找到最近合法节点"<<top.v<<" 距离为"<<top.w<<endl;
        dis[top.v]=top.w;
        ll si=M[top.v].size();
      //  cout<<si<<endl;
      cout<<"合法边入堆：";

        for(int i=0;i<si;i++)
        {
           // cout<<M[top.v][i].v<<" "<<dis[M[top.v][i].v]<<endl;
            if(dis[M[top.v][i].v]==n*lmaxn)
            {
                edge(M[top.v][i].w+dis[top.v],M[top.v][i].v).show();
                pq.push(edge(M[top.v][i].w+dis[top.v],M[top.v][i].v));
            }
        }
         cout<<endl;
    }
}
void show(ll n)
{
    for(int i=1;i<=n;i++)
    {
        ll si=M[i].size();
        cout<<"第"<<i<<"个点的连接边情况为:"<<endl;
        for(int j=0;j<si;j++)
        {
            M[i][j].show();
        }
        cout<<endl;
    }
}
void test(ll n,ll m)
{
    cout<<"对数据规模为： "<<n<<"个节点，"<<m<<"条边的样例进行测试。"<<endl;
    init(n,m);
    show(n);
    Di(1,n,m);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<":"<<dis[i]<<" ";
    }
    cout<<endl;
}
int main ()
{
    ll n,m;
    //cin>>n>>m;
    test(5,8);
    return 0;
}
