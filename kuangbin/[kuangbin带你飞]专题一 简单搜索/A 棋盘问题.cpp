#include<stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
char m[10][10];
int n,k;
int used[10];
int ans;
void dfs(int th,int kk)
{
    if(kk==k)
    {
        ans++;
        return;
    }
    if(th==n)
    {
        if(kk==k)
            ans++;
        return;
    }
    for(int h=th;h<n;h++)
    {
        for(int k=0;k<n;k++)
        {
            if(m[h][k]=='#'&&used[k]==0)
            {
                used[k]=1;
                dfs(h+1,kk+1);
                used[k]=0;
            }
        }
    }
}
int main ()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%s",m[i]);
        }
        ans=0;
        memset(used,0,sizeof(used));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
