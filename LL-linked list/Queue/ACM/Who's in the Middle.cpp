#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=2507
int main ()
{
    int n;
    scanf("%d",&n);
    long long a[n+5];
    for(int i = 0 ; i<n ; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    printf("%lld",a[n/2]);
    return 0;
}
