#include<bits/stdc++.h>
using namespace std;
#define LL long long
//Problem   :   http://www.bnuoj.com/v3/problem_show.php?pid=4323
void show(LL n,LL m)
{
    if(n%2==1 && m%2==1)
        printf("Bob\n");
    else
        printf("Alice\n");
    return;
}
int main ()
{
    LL n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        if(n==0)
            break;
        show(n,m);
    }
    return 0;
}
