#include<iostream>
#include<math.h>
#include<random>
#include<time.h>
using namespace std;
#define ll long long
const ll INF=99999999999999999LL;
ll M[22][22];   //旅行费用邻接矩阵
ll n;   //城市数
ll dp[1<<17][16][16];//动态规划记录数组 分别记录：当前城市遍历情况、起点城市、末站城市。 如果超出内存，可以改小（1<<(n+1))
time_t start,stop;//记录时间
ll path[16];//动态规划路径记录数组
ll A[16];   //枚举路径记录数组
ll tt[16];  //枚举当前路径
ll used[16];//枚举used数组

void fi(int ce,ll& ans); //递归枚举
ll DP(ll start, ll tar, ll path[15]);   //动态规划
ll get() ; //递归枚举开始
void init() ;//初始化
void getdata() ; //随机出一些测试数据 并写入到in.txt文件里备用
int main ()
{
    //getdata();
    //return 0;

    //读入数据
    freopen("in.txt","r",stdin);

    while(cin>>n)
    {
        cout<<"n="<<n<<endl;
        //初始化
        init();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }

        //动态规划
        start = clock();
    //foo();//dosomething
        ll tar=(1<<n)-1;
        cout<<"动态规划答案："<<DP(0,tar,path)<<'\t';
        for(int i=1;i<=n;i++)
        {
            cout<<path[i]+1<<" ";
        }
        cout<<endl;
        stop = clock();
        cout<<"动态规划使用时间："<<(stop-start)<<endl;

        //枚举
        start = clock();
        cout<<"枚举答案："<<get()<<"\t\t";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]+1<<" ";
        }
        cout<<endl;
        stop = clock();
        cout<<"枚举使用时间:"<<(stop-start)<<endl<<endl;
    }

    return 0;
}
ll DP(ll start, ll tar, ll path[15])   //动态规划
{
    if(tar==1)
    {
        path[0]=0;
        return 0;
    }
    //cout<<start<<" "<<tar<<endl;
    for(int beg=0;beg<n;beg++)  //枚举最开始的城市
    {
        for(int now=start;now<=tar;now++)//枚举当前状态量 二进制表示 0表示没有走当前城市 1表示走过当前城市
        {

            if(now==start)    //起点
            {
                for(int to=0;to<n;to++)
                {
                    dp[1<<to][to][to]=0;
                }
            }
            else if((now & (1<<beg))==0)//如果起点城市的情况不是1 则跳过
            {
                continue;
            }
            else
                for(int pre=0;pre<n;pre++)//枚举当前状态量下的最后一个城市
                {
                    if((now & (1<<pre))==0)//最后一个城市不在已走城市中
                        continue;
                    //cout<<beg<<" "<<now<<" "<<pre<<endl;
                    if(now==tar)//所有城市均历遍到了 结束时加上返回的费用
                    {
                        dp[now][beg][pre]+=M[pre][beg];
                    }
                    else
                        for(int to=0;to<n;to++)//枚举下一个城市
                        {
                            if((now & (1<<to))==1)//下一个城市已经在城市中
                                continue;
                            dp[now+(1<<to)][beg][to]=min(dp[now+(1<<to)][beg][to],dp[now][beg][pre]+M[pre][to]);//松弛操作
                        }
                }
        }
    }

    //找到路径 （反着走一遍）
    ll ans=INF;
    ll to;
    ll st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)//枚举最终状态
        {
            if(i==j)
                continue;
            ans=min(ans,dp[tar][i][j]);//解出最小路径
            if(ans==dp[tar][i][j])
            {
                st=i;
                to=j;
            }
        }
    }
    //cout<<st<<" "<<to<<endl;
    ll cnt=n,tmp=tar;//tmp作为城市状态反推
    path[cnt--]=to;//记录末站城市
    tmp-=(1<<to);//更新tmp
    dp[tar][st][to]-=M[to][st];//dp数组还原回去 方便反推
    while(tmp>0)
    {
        for(int pre=0;pre<n;pre++)//枚举之前的城市
        {
            if((tmp & (1<<pre))!=0)
            {
                if(dp[tmp+(1<<to)][st][to]==dp[tmp][st][pre]+M[pre][to])    //如果前一步的状态可以转到当前状态，那就是所走的路径
                {
                    path[cnt--]=pre;
                    to=pre;//更新状态
                    tmp-=(1<<pre);
                    break;
                }
            }
        }
    }
    return ans;
}
void fi(int ce,ll& ans) //递归枚举
{
    if(ce==n)//递归结束
    {
        ll tmp=M[tt[n-1]][tt[0]];
        for(int i=0;i<n-1;i++)
        {
            tmp+=M[tt[i]][tt[i+1]];//计算有效路径长度
        }
//        for(int i=0;i<=n-1;i++)
//        {
//            cout<<tt[i]+1;//测试
//        }
//        cout<<'\t';
        ans=min(ans,tmp);
        if(ans==tmp)//最短路径更新
            for(int i=0;i<n;i++)
            {
                A[i]=tt[i];
            }
        return ;
    }
    else
    {
        for(int i=0;i<n;i++)//找没走过的城市
        {
            if(used[i]==0)
            {
                //cout<<"i:"<<i<<endl;
                used[i]=1;//更新城市情况
                tt[ce]=i;
                fi(ce+1,ans);//递归下一层
                used[i]=0;//重要！ 更新城市情况
            }
        }
        //fi(n-1);
    }
}
ll get()  //递归枚举开始
{
    for(int i=0;i<n;i++)
        used[i]=0;
    ll ans=INF;
    fi(0,ans);
    return ans;
}

void init() //初始化
{
    for(int i=0;i<=n;i++)
    {
        used[i]=0;
        tt[i]=0;
    }
    for(int i=0;i<1<<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                dp[i][j][k]=INF;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            M[i][j]=0;
        }
    }
}
void getdata()  //随机出一些测试数据 并写入到in.txt文件里备用
{
    freopen("in.txt","w",stdout);
    for(int i=1;i<=20;i++)
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
