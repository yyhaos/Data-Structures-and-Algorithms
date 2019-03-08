#include<malloc.h>
#include<stdio.h>
#include<iostream>
#define INF ((1<<31)-1)
using namespace std;
typedef int DataType;	//元素的数据类型

//typedef char DataType;
typedef struct node
{         	     //链表结点
    DataType data;                     //结点数据域
    struct node * link;                 //结点链域
} LinkNode, *LinkList;   	     //链头指针
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
    {	//链不空时
        q = first->link;		//q指示首元结点
        first->link = q->link;	//摘下q指示结点
        free (q);        			//释放它
    }
    first->link=NULL;
    return;
}
LinkNode *Search ( LinkList first, DataType x )
{
//在链表中从头搜索其数据值为 x 的结点
    LinkNode *p= first->link; //p为检测指针
    while ( p != NULL && p->data != x )
        p = p->link;
    return p;
}

LinkNode *Locate ( LinkList first, int i )
{
//返回表中第 i 个元素的地址,  头结点为 0 号
      if ( i < 0 ) return NULL;           // i 值不合理
      LinkNode * p = first;   int k = 0;
      while ( p != NULL && k < i )
             { p = p->link;  k++; }	     //找第 i 个结点
      return p;
		//当返回地址非空则为第 i 个结点地址
		//否则返回NULL
}

void insertRear ( LinkList& first, DataType endTag )    //尾插法，当输入为ndTag时停止插入
{
    DataType val;
    LinkNode *s, *rear = first;	//rear指向表尾
	scanf ( "%d", &val );		//读入一数据
    while ( val != endTag )
    {
        /*if(Search(first,val)!=NULL) //重复的话就不能插入了
        {
            scanf("%d",&val);		//读入下一数据
            continue;
        }*/
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data = val;  		//创建新结点并赋值
        rear->link = s;
        rear = s;	//插入到表尾
        scanf ( "%d", &val );		//读入下一数据

    }
    rear->link = NULL;	//表收尾
}

void insertOne ( LinkList& first,DataType val )
{
    if(Search(first,val)!=NULL) //重复的话就不能插入了
        return;
    LinkNode *s;
    s = (LinkNode *) malloc ( sizeof (LinkNode ));
    s->data = val;                	//创建新结点
    LinkNode *pre;
    pre=first->link;
    if(pre==NULL)
    {
        s->link = first->link;  	//插入到表前端
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
//在表中删除第 i 个元素，通过 x 返回其值
    LinkNode *pre=Locate(first,i-1);
    if(pre==NULL || pre->link==NULL)
        return false;
    else
        pre->link=pre->link->link;

    return true;
}

void Union(LinkList &L1, LinkList &L2,LinkList &L3)  //并 保存在L3中
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

void Intersection(LinkList &L1, LinkList &L2,LinkList &L3)  //交 保存在L3中
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
void Minus(LinkList &L1, LinkList &L2,LinkList &L3)  //差L1-L2 保存在L3中
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
void printList ( LinkList& first ) {	//输出链表
    for ( LinkNode *p = first; p; p = p->link )
        printf ( "%d ", p->data );
    printf ( "\n" );
}

