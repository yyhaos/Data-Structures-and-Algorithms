#include<bits/stdc++.h>
using namespace std;
int fat[1005];
int f(int i)
{
    if(fat[i]==i)
        return i;
    else
        return fat[i]=f(fat[i]);
}
int join(int a , int b)
{
    int fa=f(a);
    int fb=f(b);
    if(fa==fb)
        return 0;
    else
    {
        fat[fa]=fb;
        f(a);
        f(b);
        return 1;
    }
}
int main ()
{
    int n, m;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        scanf("%d",&m);
        int ans = n-1;
        for(int i = 0 ; i<=n ; i++)
            fat[i]=i;
        while(m--)
        {
            int tema,temb;
            scanf("%d%d",&tema,&temb);
            ans-=join(tema,temb);
        }
        printf("%d\n",ans);
    }
}
