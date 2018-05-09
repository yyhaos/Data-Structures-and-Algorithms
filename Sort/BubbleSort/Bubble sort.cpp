#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int a[N];
void bubble_sort(int n)
{
    int flag = -1;
    while(flag == -1)
    {
        flag = 1 ;
        for(int i = 0 ; i<n-1 ; i++)
        {
            if(a[i]>a[i+1])
            {
                int tem = a[i];
                a[i]=a[i+1];
                a[i+1] = tem;
                flag = -1;
            }
        }
    }
}
int main ()
{
    int n ;
    scanf("%d",&n);
    for(int i = 0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(n);
    for(int i = 0 ; i<n ; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
