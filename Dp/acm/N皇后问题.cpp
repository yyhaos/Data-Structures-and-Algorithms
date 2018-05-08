
#include<stdio.h>
#include<iostream>
int dp[15][15];
int n, cnt=0;
int dfs(int s)
{
    if(s>n)
    {
        cnt++;
        return 1 ;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        //dp[s][i]=1;
        int flag =1 ;
        for(int before_s = s-1 ; before_s>=1 ; before_s--)
        {
            int trans_x = s-before_s;
            if(i-trans_x>=1)
            {
                if(dp[before_s][i-trans_x] == 1)
                    flag = 0 ;
            }
            if(i+trans_x<=n)
            {
                if(dp[before_s][i+trans_x] == 1)
                    flag = 0 ;
            }
            if(dp[before_s][i] == 1)
                    flag = 0 ;
        }
        if (flag == 1)
        {
            dp[s][i]=1;
            dfs(s+1);
            dp[s][i]=0;
        }
    }
    return 0;
}
int main ()
{
    //freopen("test.txt","r",stdin);
    //freopen("testout.txt","w",stdout);
    int first = 1 ;
    while(scanf("%d",&n))
    {
        if (n==0)
        {
            return 0;
        }
        if (first == 0 )
            printf("\n");
        first = 0 ;
        for (int i = 1 ; i<=n;i++)
        {
            for (int j = 1 ; j<= n ; j++)
            {
                dp[i][j]=0;
            }
        }
        cnt = 0;
        dfs(1);
        printf("%d",cnt);
    }
}
