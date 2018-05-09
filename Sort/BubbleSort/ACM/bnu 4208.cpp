#include<bits/stdc++.h>
using namespace std;
//Problem :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=4208
const int N = 10005;
int a[N],b[N];
int ans;
int main ()
{
    int t;
    scanf("%d",&t);
    map <int , int> th,th2;
    while(t--)
    {
        ans = -1;
        int n ;
        scanf("%d",&n);
        for(int i = 0 ; i<n ; i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
            th[a[i]]=i;
        }
        sort(b,b+n);
        for(int i = 0 ; i<n ; i++)
        {
            //printf("%d",b[i]);
            //b[i]=a[i];
            th2[b[i]]=i;
        }
        for(int i = 0 ; i<n ; i++)
        {
            int tem_ans = th[a[i]]-th2[a[i]];
            if(tem_ans<0)
            {
                tem_ans = 0;
            }
            ans = max(ans,tem_ans);
        }
        //ans=-0;
        printf("%d\n",ans);
    }
    return 0;
}

