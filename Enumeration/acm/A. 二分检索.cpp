#include<bits/stdc++.h>
using namespace std;
//Problem   :   https://acm.bnu.edu.cn/v3/contest_show.php?cid=9441#problem/A
int main ()
{
    int n,m;
    int a[1005];
    scanf("%d%d",&n,&m);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&a[j]);
    }
    while(m--)
    {
        int f;
        scanf("%d",&f);
        printf("%d\n",upper_bound(a,a+n,f-1)-a);
    }
    return 0;
}
