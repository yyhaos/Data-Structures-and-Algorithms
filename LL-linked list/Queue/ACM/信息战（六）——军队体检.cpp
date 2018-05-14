#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=1020
int main ()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n,m;
        float p;
        scanf("%d%d%f",&n,&m,&p);
        int a[n+5];
        for(int i = 0 ; i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        priority_queue<int, vector<int>,greater<int>> q;
        for(int i = 0 ; i<m ; i++)
        {
            q.push(a[n-1-i]);
        }
        for(int i = n-1-m ; i>=0 ; i--)
        {
            int head = q.top();
            q.pop();
            head+=a[i];
            q.push(head);
        }
        while(q.size()>=2)
        {
            q.pop();
        }
        printf("%.3f\n",q.top()/p);
        q.pop();
    }
    return 0;
}
