#include<bits/stdc++.h>
using namespace std;

void InsertSort(int a[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int X = a[i],j; // X is the item to be inserted
        for (j = i-1; j >= 0 && a[j] > X; j--) // can be fast or slow
            a[j+1] = a[j]; // make a place for X
        a[j+1] = X; // this is the insertion point
    }
}
int main()
{
    int k[10005];
    int n;

    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
    }

    InsertSort(k,n);
    for(int i = 0;i<n;i++)
    {
        printf("%d ",k[i]);
    }

    return 0;
}


