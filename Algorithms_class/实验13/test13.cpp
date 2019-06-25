#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N[100005];
ll sum[100005];
ll select[100005];
ll maxn = 100;//[1,maxn]
void init(ll n)
{
    for(int i=1;i<=n;i++)
    {
        N[i]=maxn/10+(rand()%(maxn-1)/10)+1;//正整数
        //cout<<N[i]<<" ";
    }
    sort(N+1,N+1+n);
    sum[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        sum[i]=sum[i+1]+N[i];
    }
    return ;
}
bool fi(ll n,ll th, ll tmp,ll tar)
{
    //if(tmp>0)
    //cout<<n<<" "<<th<<" "<<tmp<<" "<<tar<<endl;
    if(th>=n+1)
        return false;
    if(tmp==tar)
        return true;
    if(sum[th]+tmp<tar || tmp+N[th]>tar)//剪枝
        return false;


    select[th]=1;
    if(fi(n,th+1,tmp+N[th],tar))
        return true;
    select[th]=0;
    select[th]=0;
    if(fi(n,th+1,tmp,tar))
        return true;
    return false;
}
void showN(ll n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<N[i]<<"\t";
    }
    cout<<endl;
}
void show(ll n)
{
    for(int i=1;i<=n;i++)
    {
        if(select[i])
            cout<<N[i]<<" ";
    }
    cout<<endl;
}
int main ()
{
    ll n=10000;
    maxn=n;
    ll tar=n;
    for(n=10;n<=10000;n*=10)
    {
        init(n);
       // if(n<=100)
       //     showN(n);

        cout<<"对"<<n<<"个整数进行检查，是否存在子集使得子集的和数为"<<tar<<endl;
        if(fi(n,1,0,tar))
        {
            cout<<"存在:"<<endl;
            show(n);
        }
        else
            cout<<"没有找到\n";

    }

    return 0;
}
