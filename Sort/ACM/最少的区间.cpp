#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=1029
struct data
{
    int left,right;
    bool operator < (const data & a) const
    {
        if(left!=a.left)
            return left>=a.left;
        else
            return right<=a.right;
    }
}s;

int main ()
{
//    prior
    priority_queue <data> a;
    int n, tem , tem_2;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&tem,&tem_2);
        data tem_data;
        tem_data.left=tem;
        tem_data.right=tem_2;
        a.push(tem_data);
    }
    int tem_left = -1;
    data top;
    //int tem_left;
    int tem_right=-1;
    while(!a.empty())
    {

        if(tem_left==-1)
        {
            tem_left = a.top().left;
            tem_right = a.top().right;
        }
        top = a.top(),a.pop();
        if(top.left<=tem_right)
        {
            tem_right = max(tem_right,top.right);
        }
        else
        {
            printf("%d %d\n",tem_left,tem_right);
            tem_left = top.left;
            tem_right = top.right;
        }
        //printf("%d\t",a.top().left),a.pop();
    }
    printf("%d %d\n",tem_left,tem_right);
    return 0;
}
