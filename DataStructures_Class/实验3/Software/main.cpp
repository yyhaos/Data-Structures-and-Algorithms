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

    printf("�����A,B,C�ֱ���:\n");
    Output(A);
    Output(B);
    Output(C);

    printf("��A�в���1��\t");
    tmp=Search(A,1);
    if(tmp!=NULL)printf("%d\n",tmp->data);
    else printf("û���ҵ�%d\n",1);

    printf("��B�в���1��\t");
    tmp=Search(B,1);
    if(tmp!=NULL)printf("%d\n",tmp->data);
    else printf("û���ҵ�%d\n",1);

    printf("A��B�Ĳ���\t");
    Union(A,B,D);
    Output(D);

    printf("B��C�Ĳ���\t");
    Union(B,C,D);
    Output(D);

    printf("B��C�ĲB-C����\t");
    Minus(B,C,D);
    Output(D);

    printf("C��A�ĲC-A����\t");
    Minus(C,A,D);
    Output(D);

    printf("A��A�ĲA-A����\t");
    Minus(A,A,D);
    Output(D);


    printf("B��C�Ľ���\t");
    Intersection(B,C,D);
    Output(D);

    printf("A��C�Ľ���\t");
    Intersection(A,C,D);
    Output(D);

    printf("��A��ɾ����1��Ԫ�أ�\t");
    Remove(A,1,tem);
    Output(A);

    printf("��A��������� 4 �� 6��\t");
    insertOne(A,4);
    insertOne(A,6);
    Output(A);

    printf("��B��������� 3 �� 9��\t");
    insertOne(B,3);
    insertOne(B,9);
    Output(B);

    printf("��B��ɾ����2���͵�3��Ԫ�أ�\t");
    Remove(B,2,tem);
    Remove(B,2,tem);    //����3��
    Output(B);

    return 0;
}

