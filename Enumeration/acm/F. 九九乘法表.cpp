#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9406#problem/F
int main ()
{
    for(int i = 1 ; i<=9 ;i++)
    {
        for(int j = 1 ; j<=i ; j++)
        {
            if(j-i)
                printf("%d*%d=%2d  ",i,j,i*j);
            else
                printf("%d*%d=%2d\n",i,j,i*j);
        }
    }
    return 0;
}
