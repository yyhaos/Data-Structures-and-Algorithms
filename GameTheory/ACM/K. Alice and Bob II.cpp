#include<bits/stdc++.h>
using namespace std;
//Problem   £»   http://acm.bnu.edu.cn/v3/contest_show.php?cid=9406#problem/K
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;
        if(n%5!=0 && n%5>=2)
        {
            printf("Alice\n");
        }
        else
            printf("Bob\n");
    }
    return 0;
}
