#include<iostream>
#include<stdio.h>
using namespace std;
long long ans = 0;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=2418
void merge(int a[],int low,int high, int mid)
{
    /*
    for(int i = 0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("-%d-%d-%d\n",low,high,mid);
    */
    //subarray1=a[low,mid] , subarray2=a[mid+1,high] , both sorted
    int N=high-low+1;
    int b[N];
    int left=low ,right=mid+1, th=0;
    while(left<=mid && right<=high)
    {
        if(a[left]-a[right]>0)
        {
            ans += (mid+1-left);    //be aware that (right-left) will count repeatedly, though it is the distance between the 2 numbers need to switch;
        }
        b[th++]= a[left]<a[right] ? a[left++] : a[right++];
    }
    while(left<=mid)
        b[th++]=a[left++];
    while(right<=high)
        b[th++]=a[right++];
    for(th=0;th<N;th++)
        a[low+th]=b[th];
}

void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,high,mid);
    }
}

int main ()
{
    int k[500005];
    int n;
    void mergeSort(int a[],int low,int high);
    void merge(int a[],int low,int high, int mid);

    while(~scanf("%d",&n))
    {
        ans=0;
        if(n==0)
            break;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&k[i]);
        }

        mergeSort(k,0,n-1);

        printf("%lld\n",ans);
        /*
        printf("mergeSorted...\n");
        for(int i = 0;i<n;i++)
        {
            printf("%d ",k[i]);
        }
        */
    }

    return 0;
}
