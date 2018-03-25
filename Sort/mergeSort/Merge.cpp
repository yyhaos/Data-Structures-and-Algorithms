
#include<bits/stdc++.h>
using namespace std;

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
        b[th++]=a[left]<=a[right] ? a[left++] : a[right++];
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
    int k[10005];
    int n;

    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
    }

    mergeSort(k,0,n-1);

    printf("mergeSorted...\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",k[i]);
    }

    return 0;
}
