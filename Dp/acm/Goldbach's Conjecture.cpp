#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9443#problem/C
int main ()
{
    int s[40000];
    int th=1;
    int maxn=40000;
    int used[maxn];
    memset(used,0,sizeof(used));
    for(int i=2 ;i<=maxn;i++)
    {
        if(used[i]!=1)
        {
            s[th++]=i;
            for(int j=1;j*i<maxn;j++)
            {
                used[i*j]=1;
            }
        }
        else
        {
            continue;
        }
    }
    int n,flag,ans;
   // printf("%d",th);
    while(~scanf("%d",&n))
    {
        ans=0;
        if(n==0)
            return 0;
        for(int i=1;i<4205;i++)
        {
            flag=0;
            if(s[i]>n/2)
                break;
            else
            {
                for(int j=1;j<4205;j++)
                {
                    if(s[j]==n-s[i])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            ans+=flag;
        }
        printf("%d\n",ans);
    }
    return 0;
}
