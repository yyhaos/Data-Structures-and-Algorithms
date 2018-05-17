#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<queue>
#include<string.h>
#include<algorithm>
#include<bitset>
#define PI acos(-1.0)
using namespace std;
int fa[10005],ans;
int f(int a)
{
    if(fa[a]==a)
        return a;
    else
        return fa[a]=f(fa[a]);
}
int join (int a , int b)
{
    int fa_a=fa[a];
    int fa_b=fa[b];
    if(fa_a==fa_b)
        return 1;
    else
    {
        ans++;
        fa[fa_a]=fa_b;
        f(a);
        f(b);
    }
}
int main ()
{
    int f(int a);
    int join (int a , int b);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n , m;
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i = 1 ; i<=n;i++)
        {
            fa[i]=i;
        }
        while(m--)
        {
            int tem_a,tem_b;
            scanf("%d%d",&tem_a,&tem_b);
            join(tem_a,tem_b);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
