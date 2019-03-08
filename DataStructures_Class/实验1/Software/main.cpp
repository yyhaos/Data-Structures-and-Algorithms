#include<stdio.h>
//最大子序列求和问题 复杂度O(n)
int get_max(int len,int a[])
{
    int ans,sum,minn,maxx;// sum:前缀和 minn:前i个sum里最小值 maxx:前i个sum里最大值
    sum = a[0];
    minn = 0>a[0] ? a[0]:0;
    maxx = 0>a[0] ? 0:a[0];
    ans = maxx-minn;
    for(int i=1;i<len;i++)
    {
        sum = sum+a[i];
        minn = minn>sum ? sum:minn;
        maxx = maxx>sum ? maxx:sum;
        ans = ans>maxx-minn ? ans:maxx-minn;
        //printf("%d : %d %d %d %d\n",i,sum[i],minn[i],maxx[i]);
    }
    return ans;
}

int main ()
{
    int N = 1000;
    int a[N] = {-2,11,-4,13,-5,-2};
    int len = 6;
    printf("%d",get_max(len,a));
    return 0;
}
