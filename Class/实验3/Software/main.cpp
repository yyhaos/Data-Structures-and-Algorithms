#include "SetList.h"
#include<iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int main ()
{
    freopen("test.txt","r",stdin);
    LinkList A, B, C, D;
    InitList(A);
    InitList(B);
    InitList(C);
    LinkNode *tmp;
    int endtag,tem;
    scanf("%d",&endtag);

    insertRear(A,endtag);
    insertRear(B,endtag);
    insertRear(C,endtag);

    printf("输入的A,B,C分别是:\n");
    Output(A);
    Output(B);
    Output(C);

    printf("在A中查找1：\t");
    tmp=Search(A,1);
    if(tmp!=NULL)printf("%d\n",tmp->data);
    else printf("没有找到%d\n",1);

    printf("在B中查找1：\t");
    tmp=Search(B,1);
    if(tmp!=NULL)printf("%d\n",tmp->data);
    else printf("没有找到%d\n",1);

    printf("A与B的并：\t");
    Union(A,B,D);
    Output(D);

    printf("B与C的并：\t");
    Union(B,C,D);
    Output(D);

    printf("B与C的差（B-C）：\t");
    Minus(B,C,D);
    Output(D);

    printf("C与A的差（C-A）：\t");
    Minus(C,A,D);
    Output(D);

    printf("A与A的差（A-A）：\t");
    Minus(A,A,D);
    Output(D);


    printf("B与C的交：\t");
    Intersection(B,C,D);
    Output(D);

    printf("A与C的交：\t");
    Intersection(A,C,D);
    Output(D);

    printf("在A中删除第1个元素：\t");
    Remove(A,1,tem);
    Output(A);

    printf("在A中有序插入 4 和 6：\t");
    insertOne(A,4);
    insertOne(A,6);
    Output(A);

    printf("在B中有序插入 3 和 9：\t");
    insertOne(B,3);
    insertOne(B,9);
    Output(B);

    printf("在B中删除第2个和第3个元素：\t");
    Remove(B,2,tem);
    Remove(B,2,tem);    //不是3！
    Output(B);

    return 0;
}

