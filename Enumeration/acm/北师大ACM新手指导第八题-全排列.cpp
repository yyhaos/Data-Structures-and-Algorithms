#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9440#problem/D
int used[10];
int ans[10];
void dp(int n, int th)
{
    if(th>n)
    {
        for(int i= 1 ; i<=n;i++)
            printf("%d",ans[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            ans[th]=i;
            dp(n,th+1);
            used[i]=0;
        }
    }
    return ;
}
int main ()
{
    int n;
    memset(used,0,sizeof(used));
    scanf("%d",&n);
    dp(n,1);
    return 0;
}
