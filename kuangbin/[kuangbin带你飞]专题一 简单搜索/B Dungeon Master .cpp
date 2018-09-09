#include<stdio.h>
#include <string.h>
#include<iostream>
#include<queue>
using namespace std;
char m[35][35][35];
int L,R,C;
int used[35][35][35];
int ans;
int flag=0;
struct po
{
    int x,y,z,th;
};
queue <po> ps;
po is(int x,int y,int z,int th)
{
    po tem;
    tem.x=x;
    tem.y=y;
    tem.z=z;
    tem.th=th;
    return tem;
}
void dfs(int x,int y,int z,int th)
{
    if(flag==1)
        return ;
    if(m[x][y][z]=='E')
    {
        //memset(used,1,sizeof(used));
        flag=1;
        ans=th;
        return ;
    }
    else if(used[x][y][z]>0)
        return ;
    else
        used[x][y][z]=th;
    for(int i=-1;i<=1;i+=2)
    {
        if(x+i>=0 && x+i<L)
            if(m[x+i][y][z]!='#' && used[x+i][y][z]==0)
                ps.push(is(x+i,y,z,th+1));
        if(y+i>=0 && y+i<R)
            if(m[x][y+i][z]!='#' && used[x][y+i][z]==0)
                ps.push(is(x,y+i,z,th+1));
        if(z+i>=0 && z+i<C)
            if(m[x][y][z+i]!='#' && used[x][y][i+z]==0)
                ps.push(is(x,y,z+i,th+1));
    }
}
int main ()
{
    while(~scanf("%d%d%d",&L,&R,&C))
    {
        while(!ps.empty())
        {
            ps.pop();
        }
        if(L==0)
            break;
        for(int j=0;j<L;j++)
            for(int i=0;i<R;i++)
                scanf("%s",m[j][i]);
        ans=0;
        memset(used,0,sizeof(used));
        flag=0;
        for(int j=0;j<L;j++)
            for(int i=0;i<R;i++)
                for(int k=0;k<C;k++)
                    if(m[j][i][k]=='S')
                    {
                        ps.push(is(j,i,k,1));
                        break;
                    }
        while(!ps.empty())
        {
            if(flag==1)
                break;
            po tem=ps.front();
            ps.pop();
            dfs(tem.x,tem.y,tem.z,tem.th);
        }
        /*
        for(int j=0;j<L;j++)
        {
            for(int i=0;i<R;i++)
            {
                for(int k=0;k<C;k++)
                    printf("%d\t",used[j][i][k]);
                printf("\n");
            }
            printf("\n\n");
        }
*/
        if(ans>=1)
            printf("Escaped in %d minute(s).\n",ans-1);
        else
            printf("Trapped!\n");
    }
    return 0;
}

