#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/bnuoj/problem_show.php?pid=29066
int main ()
{
    int N, i, j;
    scanf("%d",&N);

    printf("%d\n",N*(N-1)/2);
    for(i=1; i<N;i++)
        for(j=1;j<=N-i;j++)
        {
            printf("%d %d\n",j,j+1);
        }
    return 0;
}
