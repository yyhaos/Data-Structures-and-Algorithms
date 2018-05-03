#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=4330
bool cmp (long long a,long long b)
{
    return a<b;
}
int main ()
{
    bool cmp(long long a,long long b);
    int n;
    //scanf("%d",&n);
    long long ans, tem, tem_2;
    //long long a[20005];
    priority_queue<long long,vector<long long>,greater<long long> > a;
    while(~scanf("%d",&n))
    {
        ans = 0LL;
        while(!a.empty())
            a.pop();
        for(int i = 0 ; i<n ; i++)
        {
            scanf("%lld",&tem);
            a.push(tem);
        }
        for(int i = 0 ; i<n ; i++)
        {
            if(a.size()==2)
            {
                tem = a.top();
                a.pop();
                tem_2 = a.top();
                ans += tem+tem_2;
                break;
            }
            else
            {
                tem = a.top();
                a.pop();
                tem_2 = a.top();
                a.pop();
                ans += tem+tem_2;
                a.push(tem+tem_2);
            }
            //printf("%d\t",a.size()),a.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
