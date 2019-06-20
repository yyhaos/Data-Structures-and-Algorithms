#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
db a[1005];
db b[1005];
db dp[1005][1005];
db w[1005][1005];
ll s[1005][1005];
const ll maxn=10000000;
void init(ll n)//初始化 保证和为1
{
    if(n==0)
        return ;
    db sum=0;
    for(ll i = 0;i<=n;i++)
    {
        a[i]=rand()%maxn;
        sum+=a[i];
        if(i>=1)
        {
            b[i]=rand()%maxn;
            sum+=b[i];
        }
    }
    for(ll i = 0 ;i<=n;i++)
    {
        a[i]=a[i]/sum;
        b[i]=b[i]/sum;
    }
}
void showab(ll n)//输出a\b数组的值
{
    db sum=0;
    cout<<"a: ";
    for(int i=0;i<=n;i++)
    {
        sum+=a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"b: ";
    for(int i=1;i<=n;i++)
    {
        sum+=b[i];
        cout<<b[i]<<" ";
    }
    cout<<endl;

    cout<<"概率总和:"<<sum<<endl;

}
db DP(ll n)
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        dp[i+1][i]=0;
        w[i+1][i]=a[i];
    }
    int ed;
    for(int si=0;si<n;si++)
    {
        for(int st=1;st<=n-si;st++)
        {
            ed=st+si;
            w[st][ed]=w[st][ed-1]+a[ed]+b[ed];
            dp[st][ed]=dp[st+1][ed];
            s[st][ed]=st;
            for(int k=st+1;k<=ed;k++)
            {
                db t=dp[st][k-1]+dp[k+1][ed];
                if(t<dp[st][ed])
                {
                    dp[st][ed]=t;
                    s[st][ed]=k;
                }
            }
            dp[st][ed]+=w[st][ed];
        }
    }
}
void test(ll n)
{
    cout<<"进行规模为"<<n<<"的测试"<<endl;
    init(n);
    if(n<=10)
        showab(n);
    DP(n);
    cout<<"最小查找距离权值:"<<dp[1][n]<<endl;
}
int main ()
{
    time_t now=time(NULL);
    srand((int)now);
    ll n=4;
    //init(n);
    for(n=1;n<=1000;n*=10)
    {
        test(n);
    }

    return 0;
}
