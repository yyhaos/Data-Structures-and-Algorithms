#include<bits/stdc++.h>
using namespace std;
//Problem    :   http://acm.bnu.edu.cn/bnuoj/problem_show.php?pid=33986
bool cmp(int a, int b)
{
    return a>b;
}
int main ()
{
    const int N=10;
    int oringinal[N], even[N], odd[N], i ,th_even=0,th_odd=0 ,tem;

    for(i=0;i<N;i++)
    {
        scanf("%d",&tem);
        if(tem%2==0)
            even[th_even++]=tem;
        else
            odd[th_odd++]=tem;
    }
    sort(even,even+th_even,cmp);
    sort(odd,odd+th_odd,cmp);


    for(i=0;i<th_odd;i++)
    {
        printf("%d",odd[i]);
        if(i<th_odd-1  ||  th_even>0)     //trick : there may be only odd numbers
            printf(" ");
    }
    for(i=0;i<th_even;i++)
    {
        printf("%d",even[i]);
        if(i<th_even-1)
            printf(" ");
    }

    return 0;
}
