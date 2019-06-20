#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1005][30005];
const ll maxnv=100;
const ll maxnw=30;
struct item
{
    ll v,w;
    item(ll _v=0,ll _w=0):v(_v),w(_w){}
    void show()
    {
        cout<<v<<":"<<w<<"\t";
    }
}it[1000];
void init(ll n)
{
    for(int i=1;i<=n;i++)
    {
        //cout<<rand()*10<<endl;
        it[i].v=rand()%maxnv+1;
        it[i].w=rand()%maxnw+1;
    }
    memset(dp,0,sizeof(dp));
    return ;
}
void show(ll n)
{
    cout<<"��Ʒ��Ϣ(��ֵ:����)��";
    for(int i=1;i<=n;i++)
    {
        it[i].show();
    }
    cout<<endl;
}
ll DP(ll n, ll c)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j>=it[i].w)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-it[i].w]+it[i].v);
            }
        }
    }
    return dp[n][c];
}
void dfs(ll th,ll tv,ll c,ll tw,ll n,ll &ans)
{
    if(tw>c)
        return ;
    ans=max(ans,tv);
    if(th==n+1)
        return ;
    dfs(th+1,tv,c,tw,n,ans);
    dfs(th+1,tv+it[th].v,c,tw+it[th].w,n,ans);
}
ll Bruce(ll n,ll c)
{
    if(n>27)
    {
        cout<<"����ʱ�䳬��10s ����"<<endl;
        return -1;
    }
    ll ans=0LL;
    dfs(1,0,c,0,n,ans);
    return ans;
}
void test(ll n , ll c)
{
    cout<<"���й�ģΪ n="<<n<<"���� ���� c="<<c<<" :"<<endl;
    init(n);
    if(n<=13)show(n);
    cout<<"��̬�滮��: "<<DP(n,c)<<endl;
    cout<<"���Ѵ𰸣�    "<<Bruce(n,c)<<endl;
}
int main ()
{
    ll n;
    for(n=10;n<=1000;)
    {

        test(n,n*50);
        if(n<12)
            n++;
        else
            n*=10;
    }
   // test(n,n*5);

    return 0;
}
