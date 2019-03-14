#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll M[10][10];

//const ll tx[]={1,2,2,1,-1,-2,-2,-1};//too slow for 7,8
//const ll ty[]={2,1,-1,-2,-2,-1,1,2};
const ll tx[]={-1, 1, -2, 2,-2, 2,-1, 1};//too slow for 6,8
const ll ty[]={-2,-2, -1,-1, 1, 1, 2, 2};

void show(ll n,ll m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
int over=0;
void dfs(ll th,ll x,ll y,ll n,ll m)
{
    //if(n*m==56)
    //cout<<th<<" "<<x<<" "<<y<<endl;

    if(over)    //找到了就不找了
        return ;

    if(th==n*m)
    {
        show(n,m);
        over=1; //找到一个就行
        return ;
    }
    else
    {
        if(th==0)//第一匹马 枚举其起始位置
        {
            for(int i=1;i<=(1+n)/2;i++)
            {
                for(int j=1;j<=(1+m)/2;j++) //由对称性 枚举长方形的1/8就行
                {
                    M[i][j]=1;  //标记
                    dfs(th+1,i,j,n,m);  //递归
                    M[i][j]=0;  //更新
                }
            }
        }
        else
        {
            ll nx,ny;
            for(int i=0;i<8;i++)
            {
                nx=x+tx[i];
                ny=y+ty[i];
                if(nx<1 || nx>n || ny<1 || ny>m)    //跳过界
                    continue;
                if(M[nx][ny]!=0)    //跳过了
                    continue;
                M[nx][ny]=th+1; //标记
                dfs(th+1,nx,ny,n,m);    //递归
                M[nx][ny]=0;    //更新
            }
        }
    }
}
void init()
{
    over=0;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            M[i][j]=0;
}
int main ()
{
    init();
    ll n,m;
//    cin>>n>>m;
//    dfs(0,0,0,n,m);

    for(n=2;n<=8;n++)
    {
        for(m=n;m<=8;m++)
        {
            init();
            cout<<n<<" * "<<m<<endl;
            dfs(0,0,0,n,m);
            if(over==0)
            {
                cout<<"无解"<<endl<<endl;
            }
        }
    }

    return 0;
}
