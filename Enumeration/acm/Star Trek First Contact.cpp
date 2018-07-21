#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=44583
int power[1005],damage[1005],used[1005];
int A,B,N;

bool dp(int s)
{
    if(B<=0)
        return true;
    for(int i = s ;i<=N;i++)
    {
        if(used[i]==1 || A<power[i])
            continue;
        else
        {
            A-=power[i];
            used[i]=1;
            B-=damage[i];
            if(dp(s+1))
                return true;
            B+=damage[i];
            used[i]=0;
            A+=power[i];
        }
    }

    return false;
}

int main ()
{
    int t;
    cin>>t;
    for(int s=1;s<=t;s++)
    {
        cin>>A>>B>>N;
        memset(used,0,sizeof(used));
        for(int i = 1 ; i<=N;i++)
        {
            scanf("%d",&power[i]);
        }
        for(int i = 1 ; i<=N;i++)
        {
            scanf("%d",&damage[i]);
        }
        for(int i = 1 ; i<=N;i++)
        {
            if(power[i]==0)
            {
                B-=damage[i];
                used[i]=1;
            }
            if(damage[i]==0)
                used[i]=1;
        }
        if(dp(1))
            printf("Case #%d: YES\n",s);
        else
            printf("Case #%d: NO\n",s);
    }
    return 0;
}
