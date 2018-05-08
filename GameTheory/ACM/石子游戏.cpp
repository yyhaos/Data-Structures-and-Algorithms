#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://www.bnuoj.com/v3/problem_show.php?pid=4098
//simple one    :   1061
#define LL long long
void show(LL a,LL n,LL m)
{
    if(a%(m+n)==0 || a%(m+n)>n)
        printf("WIN\n");
    else
        printf("LOST\n");
    return;
}
int main ()
{
    void show(LL a,LL n,LL m);
    LL  c,n,m,a;
    while(~scanf("%lld%lld%lld",&a,&n,&m))
        show(a,n,m);
    return 0;
}
