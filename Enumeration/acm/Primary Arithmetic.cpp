#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=1006
int judge(int a, int b)
{
    int flag = 0, ans = 0;
    while(1)
    {
        if(a==0 && b==0)
            break;
        int tem_a = a%10;
        int tem_b = b%10;
        if(tem_a+tem_b+flag>=10)
        {
            ans++;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        a/=10;
        b/=10;
    }
    return ans;
}
int main ()
{
    int a,b;
    int judge(int a, int b);

    while(~scanf("%d%d",&a,&b))
    {
        if(a==0 && b==0)
        {
            break;
        }
        int ans =judge(a,b);
        if(ans)
        {
            printf("%d ",ans);
        }
        else
            printf("No ");
        if(ans>1)
            printf("carry operations.\n");
        else
            printf("carry operation.\n");
    }
    return 0;
}
