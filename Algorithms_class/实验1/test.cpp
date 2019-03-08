#include<iostream>
#include<math.h>
#include<random>
#include<time.h>
using namespace std;
#define ll long long
const ll INF=99999999999999999LL;
ll M[22][22];   //旅行费用
ll n;
ll dp[1<<15][22];
time_t start,stop;



ll path[15];
ll dfs(ll start, ll tar, ll path[15])
{
    //cout<<start<<" "<<tar<<endl;
    for(int now=start;now<=tar;now++)
    {
        if(now==start)    //起点
        {
            for(int to=0;to<n;to++)
            {
                dp[1<<to][to]=0;
            }
        }
        else
            for(int pre=0;pre<n;pre++)
            {
                for(int to=0;to<n;to++)
                {
                    if((now & (1<<pre))==0)
                        continue;
                    if((now & (1<<to))==1)
                        continue;
                    dp[now+(1<<to)][to]=min(dp[now+(1<<to)][to],dp[now][pre]+M[pre][to]);
                }
            }
    }
    ll ans=INF;
    ll to;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,dp[tar][i]);
        if(ans==dp[tar][i])
            to=i;
    }
    ll cnt=n,tmp=tar;
    path[cnt--]=to;
    tmp-=(1<<to);
    while(tmp>0)
    {
    //    cout<<tmp<<endl;
        for(int pre=0;pre<n;pre++)
        {
            if((tmp & (1<<pre))!=0)
            {
                //cout<<pre<<endl;
                if(dp[tmp+(1<<to)][to]==dp[tmp][pre]+M[pre][to])
                {
                  //  cout<<pre<<endl;
                    path[cnt--]=pre;
                    to=pre;
                    tmp-=(1<<pre);
                    break;
                }
            }
        }
    }
    return ans;
}

ll Acnt=0;
ll A[3628800+5][22];
ll tt[22];
ll used[122];
void fi(int ce)
{
    if(ce==n)
    {
        for(int i=0;i<n;i++)
        {
            A[Acnt][i]=tt[i];
        }
        Acnt++;
        return ;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(used[i]==0)
            {
                //cout<<"i:"<<i<<endl;
                used[i]=1;
                tt[ce]=i;
                fi(ce+1);
                used[i]=0;
            }
        }
        //fi(n-1);
    }
}
void get()
{
    for(int i=0;i<n;i++)
        used[i]=0;
    Acnt=0;
    fi(0);
}

void init() //初始化
{
    Acnt=0;
    for(int i=0;i<=n;i++)
    {
        used[i]=0;
        tt[i]=0;
    }
    for(int i=0;i<1<<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=INF;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            M[i][j]=0;
        }
    }
}
void getdata()
{
    freopen("in.txt","w",stdout);
    for(int i=1;i<=15;i++)
    {
        cout<<i<<endl;
        for(int k=1;k<=i;k++)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<rand()%1000<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
int main ()
{
    //getdata();
    //return 0;

    //读入数据
    freopen("test.txt","r",stdin);

    while(cin>>n)
    {
        cout<<n<<endl;
        //初始化
        init();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }

        start = clock();
    //foo();//dosomething
        ll tar=(1<<n)-1;
        cout<<dfs(0,tar,path)<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<path[i]+1<<" ";
        }
        cout<<endl;
        stop = clock();
        cout<<"Use Time:"<<(stop-start)<<endl<<endl;

        start = clock();
        get();

        ll ans=INF;
        for(int i=0;i<Acnt;i++)
        {
            ll tmp=0;
            for(int j=0;j<n-1;j++)
            {
                tmp+=M[A[i][j]][A[i][j+1]];
                //cout<<A[i][j]<<" ";
            }
            ans=min(ans,tmp);
            if(ans==tmp)
            {
                for(int j=0;j<n;j++)
                {
                    path[j]=A[i][j];
                }
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<path[i]+1<<" ";
        }
        cout<<endl;
        stop = clock();
        cout<<"Use Time:"<<(stop-start)<<endl<<endl;
    }

    return 0;
}
