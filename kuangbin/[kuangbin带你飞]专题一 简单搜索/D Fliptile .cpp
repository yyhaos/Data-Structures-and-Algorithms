#include<stdio.h>
#include <string.h>
#include<iostream>
#include<queue>
using namespace std;    // O()=2^15*15*15=7372800
int dp[1<<15+5];
int f[20][20];

int maze[20][20];

void c(int x,int y)
{
    maze[x][y]=1-maze[x][y];
}
int n,m,cnt;

int ans[20][20];
int tem[20][20];
int ff[20][20];

void flip(int x,int y)
{
    ff[x][y]=1;
    cnt++;
    c(x,y);
    for(int i=-1;i<=1;i+=2)
    {
        if(x+i>=1 && x+i<=m)
        {
            c(x+i,y);
        }
        if(y+i>=1 && y+i<=n)
        {
            c(x,y+i);
        }
    }
}

int dfs(int k)
{
    cnt=0;
    memcpy(maze, tem, sizeof(maze));

    for(int i=1;i<=n;i++)
    {
        if(k&(1<<(n-i)))
            flip(1,i);
    }
    for(int j=2;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(maze[j-1][i]==1)
            {
                flip(j,i);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(maze[m][i]==1)
            cnt=9999999999;
    }
    return cnt;
}

int main ()
{
    int ans,ans_way;
    while(~scanf("%d%d",&m,&n))
    {
        memset(tem,0,sizeof(tem));
        ans=9999999;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&tem[i][j]);
            }
        }

        for(int i=0;i<=(1<<n);i++)
        {
            if(dfs(i)<ans)
            {
                ans=dfs(i);
                ans_way=i;
                //break;
            }
        }

        memset(ff,0,sizeof(ff));
      //  printf("%d %d\n",ans,ans_way);
        if(ans<9999999)
        {
            dfs(ans_way);
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    printf("%d",ff[i][j]);
                    if(j!=n)
                        printf(" ");
                }
                printf("\n");
            }
        }
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
