#include<iostream>
#include <stdio.h>
#include <malloc.h>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define ll long long

int cnt;
bool used_y[250];    //纵轴
bool used_1[250];    //主对称轴
bool used_2[250];    //反对称轴
char matrix[250][250];
int dfs_recursion(int th,int tar)
{
    int ans=0;
    if(th==tar+1)
    {
        cout<<"第"<<++cnt<<"个："<<endl;
        rep(i,1,tar)
        {
            rep(j,1,tar)
                cout<<matrix[i][j];
            cout<<endl;
        }
        cout<<endl;
        return 1;
    }
    else
    {
        rep(i,1,tar)
        {
            if(used_y[i] && used_1[i-th+tar] && used_2[i+th])
            {
                used_y[i]=used_1[i-th+tar]=used_2[i+th]=false;
                matrix[th][i]='O';
                ans=ans+dfs_recursion(th+1,tar);
                matrix[th][i]='+';
                used_y[i]=used_1[i-th+tar]=used_2[i+th]=true;
            }
        }
        return ans;
    }
}

struct state
{
    int th;
    ll col,md,sd;
    int qe[15];
};
int dfs_not_recursion(int tar)
{
    int ans=0;
    state start;
    rep(i,1,tar)
        start.qe[i]=0;
    start.col=start.md=start.sd=0LL;
    start.th=0;
    stack <state> q;
    q.push(start);
    while(!q.empty())
    {
        state tmp=q.top();
        q.pop();
        if(tmp.th==tar)
        {
            ans++;
            cout<<"第"<<++cnt<<"个："<<endl;
            rep(i,1,tar)
            {
                rep(j,1,tmp.qe[i]-1)
                    cout<<"+";
                cout<<"O";
                rep(j,tmp.qe[i]+1,tar)
                    cout<<"+";
                cout<<endl;
            }
            cout<<endl;
        }
        else
        {
            rep(i,1,tar)
            {
                if(! (tmp.col&(1LL<<i) || tmp.md &(1LL<<(i+tmp.th+1)) || tmp.sd&(1LL<<(-i+tar+tmp.th+1))) )
                {
                    state ne=tmp;
                    ne.col += 1LL<<i;
                    ne.md += (1LL<<(i+tmp.th+1));
                    ne.sd += (1LL<<(-i+tar+tmp.th+1));
                    ne.qe[tmp.th+1]=i;
                    ne.th=tmp.th+1;
                    q.push(ne);
                }
            }
        }
    }
    return ans;
}

void initialize(int n)
{
    cnt=0;
    if(n>=240)
        n=240;
    rep(i,0,n*2+2)
    {
        used_1[i]=used_2[i]=used_y[i]=true;
        rep(j,1,n)
            matrix[i][j]='+';
    }
    return ;
}
int main ()
{
    int n;
    cout<<"请输入n (n<=10)"<<endl;
    cin>>n;
    initialize(n);
    cout<<"递归函数，"<<n<<"皇后的总数是："<<dfs_recursion(1,n)<<endl;
    initialize(n);
    cout<<"非递归函数，"<<n<<"皇后的总数是："<<dfs_not_recursion(n)<<endl;

    return 0;
}

