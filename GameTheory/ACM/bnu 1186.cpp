#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=10005;
//Problem   :   http://www.bnuoj.com/v3/problem_show.php?pid=1186
//reference :   http://oeis.org/search?q=1%2C2%2C3%2C5%2C4%2C7%2C6%2C10%2C8%2C13%2C9%2C15&sort=&language=chineseS&go=%E6%90%9C%E7%B4%A2
LL i,k[maxn],flag=1;
int used[maxn];
void show(LL n,LL m)
{
    if(n>m)
    {
        LL tem = n;
        n=m;
        m=tem;
    }
    if(n==int((m-n)*((1+sqrt(5))/2.0)))
        printf("0\n");
    else
        printf("1\n");
    return;
}

int main ()
{
    //printf("11\n");
    void show(LL n,LL m);
    for(i=1;i<maxn;i++)
    {
        used[i]=0;
    }
    for(i=1;i<maxn;i++)
    {
        if(used[i]==0)
        {
            k[i]=i+flag++;
            used[k[i]]=1;
            used[i]=1;
        }
        else
        {
            k[i]=0;
            continue;
        }
    }
    //printf("%lld\n",k[maxn-1]);
    LL n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        show(n,m);
    }
    return 0;
}

