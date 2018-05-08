#include<stdio.h>
#include<iostream>
int n, cnt[15]={0,1,0,0,2,10,4,40,92,352,724};
int main ()
{
    //freopen("test.txt","r",stdin);
   // freopen("testout.txt","w",stdout);
    int first = 1 ;
    while(scanf("%d",&n))
    {
        if (n==0)
        {
            return 0;
        }
        if (first == 0 )
            printf("\n");
        first = 0 ;
        printf("%d",cnt[n]);
    }
}
