#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int i,int j)
{
    //random version
    int random = rand()%(j-i+1);
    swap (a[i],a[random+i]);

    int p = a[i];
    int m = i;
    for(int k = i+1; k<=j; k++)
    {
        if(a[k]<=p)
        {
            m++;
            swap(a[k],a[m]);
        }
    }
    swap(a[i],a[m]);
    return m;
}

void quickSort(int a[], int low, int high)
{
    if(low <high)
    {
        int pivotIdx = partition(a,low,high);
        quickSort(a,low,pivotIdx-1);
        quickSort(a,pivotIdx+1,high);
    }
}
int main()
{
    int k[10005];
    int n;
    srand((unsigned)time(NULL));

    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
    }

    quickSort(k,0,n-1);

    printf("quickSorted...\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",k[i]);
    }

    return 0;
}

