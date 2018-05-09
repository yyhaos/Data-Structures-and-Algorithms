#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=1017
int N, M, ans=0, used[10];
void dp(int th, int x)
{
    if(th==N+1)
        printf("%d\n",x),ans++;

    else
    {
        for(int i = 1 ; i<=N && i<=th+M;i++)
        {
            if(used[i]>0)
                continue;
            else
            {
                used[i]=1;
                dp(th+1,x*10+i);
                used[i]=0;
            }
        }
    }
}
int main ()
{
    void dp(int th, int x);
    memset(used,0,sizeof(used));

    scanf("%d%d",&N,&M);
    dp(1,0);
    printf("%d",ans);
    return 0;
}
