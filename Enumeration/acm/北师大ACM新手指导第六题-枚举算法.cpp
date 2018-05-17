#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    int used[30005];
    memset(used,0,sizeof(used));
    for(int i = 2 ; i<= n ; i++)
    {
        if(used[i]==0)
        {
            printf("%d\n",i);
            for(int j = 1 ; j*i<=n;j++)
            {
                used[j*i]=1;
            }
        }
        else
            continue;
    }
    return 0;
}
