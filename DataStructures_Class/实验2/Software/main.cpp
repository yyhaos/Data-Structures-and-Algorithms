#include "SeqLish.h"
#include<iostream>
using namespace std;
int main ()
{
    SeqList A,B;
    int n,tem;
    freopen("test.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        InitList(A);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tem);
            Insert(A,tem,i+1);
        }
        Copy(B,A);
        printf("A=%f\n",1.0*Sum(A)/A.n);
        printf("B=%f\tB��A�ĸ���\n",1.0*Sum(B)/B.n);    //B��A�ĸ���
    }
    return 0;
}
