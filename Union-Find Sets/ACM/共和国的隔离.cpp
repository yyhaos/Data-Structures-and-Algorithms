#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=4192
int fa[500005];
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
    /*
    if(f(i)==f(j))
        return 1;
    else
    {
        fa[f(i)]=f(j);
        f(i);
        f(j);
        return 0;
    }
    */
    int fa_i=f(i);
    int fa_j=f(j);
    if(fa_i==fa_j)
        return 1;
    else
        fa[fa_i]=fa_j;
    return 0;
}
struct bridge
{
    int a;
    int b;
};
struct action
{
    char flag[3];
    int a;
    int b;
};
int main ()
{
    int n , m, tem, tem_2;
    int t;
    scanf("%d%d",&n,&m);
    bridge br[m+5];
    for(int i = 1 ; i<=n ; i++)
    {
        fa[i]=i;
    }
    for(int i = 1 ; i<=m ; i++)
    {
        scanf("%d%d",&br[i].a,&br[i].b);
    }
    scanf("%d",&t);
    stack <action> acts;
    int unused[500005];
    memset(unused,0,sizeof(unused));
    while(t--)
    {
        action tem_act;
        scanf("%s",tem_act.flag);
        //printf("flag == %s\n",tem_act.flag);
        if(tem_act.flag[0]=='Q')
            scanf("%d%d",&tem_act.a,&tem_act.b);
        else
        {
            scanf("%d",&tem_act.a);
            unused[tem_act.a]++;
        }
        acts.push(tem_act);
    }
    for(int i=1 ; i<=m;i++)
    {
        if(unused[i]==0)
            join(br[i].a,br[i].b);
    }
    stack <int> ans;
    while(!acts.empty())
    {
        action head=acts.top();
        acts.pop();
        if(head.flag[0]=='D')
        {
            if(--unused[head.a]==0)
                join(br[head.a].a,br[head.a].b);
        }
        else
        {
            if(f(head.a)==f(head.b))
                ans.push(1);
            else
                ans.push(0);
        }
    }
    int first = 1;
    while(!ans.empty())
    {
        int head=ans.top();
        ans.pop();
        if(first == 1)
        {
            printf("%d",head);
        }
        else
            printf("\n%d",head);
        first = 0;
    }
    return 0;
}
