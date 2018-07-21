#include<stdio.h>

//Problem   :   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9443#problem/B
int main ()
{
    int ans[55];
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    for(int i=4;i<=50;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]*2-ans[i-2];
    }
    int n;
    while(~scanf("%d",&n))
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
