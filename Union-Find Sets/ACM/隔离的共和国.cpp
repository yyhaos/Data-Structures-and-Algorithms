#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=4191
int fa[505];
int f(int i)
{
    if(fa[i]==i)
        return i;
    else
    {
        return fa[i]=f(fa[i]);
    }
}
int join(int i,int j)
{
    if(f(i)==f(j))
        return 1;
    else
    {
        fa[f(i)]=f(j);
        f(i);
        f(j);
    }
}
int main ()
{
    int n , m, tem, tem_2;
    int k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1 ; i<= n ; i++)
    {
        fa[i]=i;
    }
    while(k--)
    {
        scanf("%d%d",&tem,&tem_2);
        join(tem,tem_2);
    }
    int target = f(m);
    int cnt = 0;
    for(int i = 1; i<= n ; i++)
    {
        if(i==m)
            continue;
        else
        {
            if(f(i)!=target)
            {
                cnt++;
       //         printf("%d ",i);
            }
        }
    }
    int first = 1;
    if(cnt)
        printf("%d\n",cnt);
    else
        printf("%d",cnt);
    for(int i = 1; i<= n ; i++)
    {
        if(i==m)
            continue;
        else
        {
            if(f(i)!=target)
            {
       //         cnt++;
                if(first)
                {
                    printf("%d",i);
                    first=0;
                }
                else
                    printf(" %d",i);
            }
        }
    }
}
