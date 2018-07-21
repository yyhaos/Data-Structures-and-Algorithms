#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9440#problem/C
int ans[10000];
void dp(int n,int k,int th)
{
    if(th>k)
    {
        for(int i=1;i<=k;i++)
        {
            printf("%d",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        ans[th]=i;
        dp(n,k,th+1);
    }
    return ;
}
int main ()
{
    int k;
    int n;
    scanf("%d%d",&n,&k);
    dp(n,k,1);
    return 0;
}
