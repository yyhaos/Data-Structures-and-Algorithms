#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9440#problem/B
int main ()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int f[10010];
    f[1]=1;
    f[0]=0;
    int flag=1;
    if(n<=m)
    for(int i=2;i<=1005;i++)
    {
        f[i]=f[i-1]+f[i-2];
        if(f[i]>=n&&f[i]<=m)
        {
            if(flag==1)
            {
                flag=0;
                printf("%d",f[i]);
            }
            else
                printf(" %d",f[i]);
        }
    }
    return 0;
}
