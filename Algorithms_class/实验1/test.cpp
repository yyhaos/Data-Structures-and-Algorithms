#include<iostream>
#include<math.h>
#include<random>
#include<time.h>
using namespace std;
#define ll long long
const ll INF=99999999999999999LL;
ll M[22][22];   //���з����ڽӾ���
ll n;   //������
ll dp[1<<21][22];//��̬�滮��¼���� ��������ڴ棬���Ը�С��1<<(n+1))
time_t start,stop;//��¼ʱ��
ll path[15];//��̬�滮·����¼����
ll A[22];   //ö��·����¼����
ll tt[22];  //ö�ٵ�ǰ·��
ll used[122];//ö��used����

void fi(int ce,ll& ans); //�ݹ�ö��
ll DP(ll start, ll tar, ll path[15]);   //��̬�滮
ll get() ; //�ݹ�ö�ٿ�ʼ
void init() ;//��ʼ��
void getdata() ; //�����һЩ�������� ��д�뵽in.txt�ļ��ﱸ��
int main ()
{
    //getdata();
    //return 0;

    //��������
    freopen("in.txt","r",stdin);

    while(cin>>n)
    {
        cout<<"n="<<n<<endl;
        //��ʼ��
        init();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }

        //��̬�滮
        start = clock();
    //foo();//dosomething
        ll tar=(1<<n)-1;
        cout<<"��̬�滮�𰸣�"<<DP(0,tar,path)<<'\t';
        for(int i=1;i<=n;i++)
        {
            cout<<path[i]+1<<" ";
        }
        cout<<endl;
        stop = clock();
        cout<<"��̬�滮ʹ��ʱ�䣺"<<(stop-start)<<endl;

        //ö��
        start = clock();
        cout<<"ö�ٴ𰸣�"<<get()<<"\t\t";
        for(int i=0;i<n;i++)
        {
            cout<<A[i]+1<<" ";
        }
        cout<<endl;
        stop = clock();
        cout<<"ö��ʹ��ʱ��:"<<(stop-start)<<endl<<endl;
    }

    return 0;
}
ll DP(ll start, ll tar, ll path[15])   //��̬�滮
{
    //cout<<start<<" "<<tar<<endl;
    for(int now=start;now<=tar;now++)//ö�ٵ�ǰ״̬�� �����Ʊ�ʾ 0��ʾû���ߵ�ǰ���� 1��ʾ�߹���ǰ����
    {
        if(now==start)    //���
        {
            for(int to=0;to<n;to++)
            {
                dp[1<<to][to]=0;
            }
        }
        else
            for(int pre=0;pre<n;pre++)//ö�ٵ�ǰ״̬���µ����һ������
            {
                for(int to=0;to<n;to++)//ö����һ������
                {
                    if((now & (1<<pre))==0)//���һ�����в������߳�����
                        continue;
                    if((now & (1<<to))==1)//��һ�������Ѿ��ڳ�����
                        continue;
                    dp[now+(1<<to)][to]=min(dp[now+(1<<to)][to],dp[now][pre]+M[pre][to]);//�ɳڲ���
                }
            }
    }


    //�ҵ�·�� ��������һ�飩
    ll ans=INF;
    ll to;
    for(int i=0;i<n;i++)//ö������״̬
    {
        ans=min(ans,dp[tar][i]);//�����С·��
        if(ans==dp[tar][i])
            to=i;
    }
    ll cnt=n,tmp=tar;//tmp��Ϊ����״̬����
    path[cnt--]=to;//��¼ĩվ����
    tmp-=(1<<to);//����tmp
    while(tmp>0)
    {
    //    cout<<tmp<<endl;
        for(int pre=0;pre<n;pre++)//ö��֮ǰ�ĳ���
        {
            if((tmp & (1<<pre))!=0)
            {
                //cout<<pre<<endl;
                if(dp[tmp+(1<<to)][to]==dp[tmp][pre]+M[pre][to])    //���ǰһ����״̬����ת����ǰ״̬���Ǿ������ߵ�·��
                {
                  //  cout<<pre<<endl;
                    path[cnt--]=pre;
                    to=pre;//����״̬
                    tmp-=(1<<pre);
                    break;
                }
            }
        }
    }
    return ans;
}
void fi(int ce,ll& ans) //�ݹ�ö��
{
    if(ce==n)//�ݹ����
    {
        ll tmp=0;
        for(int i=0;i<n-1;i++)
        {
            tmp+=M[tt[i]][tt[i+1]];//������Ч·������
        }
//        for(int i=0;i<=n-1;i++)
//        {
//            cout<<tt[i]+1;//����
//        }
//        cout<<'\t';
        ans=min(ans,tmp);
        if(ans==tmp)//���·������
            for(int i=0;i<n;i++)
            {
                A[i]=tt[i];
            }
        return ;
    }
    else
    {
        for(int i=0;i<n;i++)//��û�߹��ĳ���
        {
            if(used[i]==0)
            {
                //cout<<"i:"<<i<<endl;
                used[i]=1;//���³������
                tt[ce]=i;
                fi(ce+1,ans);//�ݹ���һ��
                used[i]=0;//��Ҫ�� ���³������
            }
        }
        //fi(n-1);
    }
}
ll get()  //�ݹ�ö�ٿ�ʼ
{
    for(int i=0;i<n;i++)
        used[i]=0;
    ll ans=INF;
    fi(0,ans);
    return ans;
}

void init() //��ʼ��
{
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
void getdata()  //�����һЩ�������� ��д�뵽in.txt�ļ��ﱸ��
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
