#include<malloc.h>
#include<stdio.h>
#include<iostream>
#define INF ((1<<31)-1)
using namespace std;
typedef int DataType;	//Ԫ�ص���������

//typedef char DataType;
typedef struct node
{         	     //������
    DataType data;                     //���������
    struct node * link;                 //�������
} LinkNode, *LinkList;   	     //��ͷָ��
LinkList first;
void InitList (LinkList & first)
{
    first=(LinkNode*)malloc(sizeof(LinkNode));
    first->link=NULL;
    return;
}
void makeEmpty(LinkList &first)
{
    LinkList q;
    while ( first->link != NULL )
    {	//������ʱ
        q = first->link;		//qָʾ��Ԫ���
        first->link = q->link;	//ժ��qָʾ���
        free (q);        			//�ͷ���
    }
    first->link=NULL;
    return;
}
LinkNode *Search ( LinkList first, DataType x )
{
//�������д�ͷ����������ֵΪ x �Ľ��
    LinkNode *p= first->link; //pΪ���ָ��
    while ( p != NULL && p->data != x )
        p = p->link;
    return p;
}

LinkNode *Locate ( LinkList first, int i )
{
//���ر��е� i ��Ԫ�صĵ�ַ,  ͷ���Ϊ 0 ��
      if ( i < 0 ) return NULL;           // i ֵ������
      LinkNode * p = first;   int k = 0;
      while ( p != NULL && k < i )
             { p = p->link;  k++; }	     //�ҵ� i �����
      return p;
		//�����ص�ַ�ǿ���Ϊ�� i ������ַ
		//���򷵻�NULL
}

void insertRear ( LinkList& first, DataType endTag )    //β�巨��������ΪndTagʱֹͣ����
{
    DataType val;
    LinkNode *s, *rear = first;	//rearָ���β
	scanf ( "%d", &val );		//����һ����
    while ( val != endTag )
    {
        /*if(Search(first,val)!=NULL) //�ظ��Ļ��Ͳ��ܲ�����
        {
            scanf("%d",&val);		//������һ����
            continue;
        }*/
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data = val;  		//�����½�㲢��ֵ
        rear->link = s;
        rear = s;	//���뵽��β
        scanf ( "%d", &val );		//������һ����

    }
    rear->link = NULL;	//����β
}

void insertOne ( LinkList& first,DataType val )
{
    if(Search(first,val)!=NULL) //�ظ��Ļ��Ͳ��ܲ�����
        return;
    LinkNode *s;
    s = (LinkNode *) malloc ( sizeof (LinkNode ));
    s->data = val;                	//�����½��
    LinkNode *pre;
    pre=first->link;
    if(pre==NULL)
    {
        s->link = first->link;  	//���뵽��ǰ��
        first->link = s;
        return;
    }
    while(pre->link!=NULL && pre->link->data < val)
            pre=pre->link;
    s->link=pre->link;
    pre->link=s;
    return ;
}

bool Remove ( LinkList& first, int i, DataType& x )
{
//�ڱ���ɾ���� i ��Ԫ�أ�ͨ�� x ������ֵ
    LinkNode *pre=Locate(first,i-1);
    if(pre==NULL || pre->link==NULL)
        return false;
    else
        pre->link=pre->link->link;

    return true;
}

void Union(LinkList &L1, LinkList &L2,LinkList &L3)  //�� ������L3��
{
    InitList(L3);
    LinkList p;
    p=L1->link;
    while(p!=NULL)
    {
        if(Search(L3,p->data)==NULL)
            insertOne(L3,p->data);
        p=p->link;
    }
    p=L2->link;
    while(p!=NULL)
    {
        if(Search(L3,p->data)==NULL)
            insertOne(L3,p->data);
        p=p->link;
    }
    return;
}

void Intersection(LinkList &L1, LinkList &L2,LinkList &L3)  //�� ������L3��
{
    InitList(L3);
    LinkList p;
    p=L1->link;
    while(p!=NULL)
    {
        if(Search(L2,p->data)!=NULL)
            insertOne(L3,p->data);
        p=p->link;
    }
    return;
}
void Minus(LinkList &L1, LinkList &L2,LinkList &L3)  //��L1-L2 ������L3��
{
    InitList(L3);
    LinkList p;
    p=L1->link;
    while(p!=NULL)
    {
        if(Search(L2,p->data)==NULL)
            insertOne(L3,p->data);
        p=p->link;
    }
    return;
}
void Output(LinkList &first)
{
    LinkNode *p=first;
    if(first->link==NULL)
        printf("The set is empty\n");
    else
    {
        p=first->link;
        while(p)
        {
            printf("%d ",p->data);
            p=p->link;
        }
        printf("\n");
    }
    return;
}
void printList ( LinkList& first ) {	//�������
    for ( LinkNode *p = first; p; p = p->link )
        printf ( "%d ", p->data );
    printf ( "\n" );
}

