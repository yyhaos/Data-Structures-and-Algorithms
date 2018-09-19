
#include<bits/stdc++.h>
using namespace std;
typedef char DataType;
typedef struct node
{         	     //链表结点
        DataType data;                     //结点数据域
        struct node * link;                 //结点链域
} LinkNode, *LinkList;   	     //链头指针
                          //链表头指针

void myprint(LinkList first)
{
    LinkList p=first;
    while(p!=NULL)
    {
        printf("%c",p->data);
        p=p->link;
    }
    printf("\n");
}

void trans(LinkList &first)
{
    LinkList p=first,nxtp=p->link,nxtp2;
    p->link=NULL;
    if(p==NULL || nxtp==NULL)
        return;
    while(1)
    {
        nxtp2=nxtp->link;
        nxtp->link=p;
        if(nxtp2==NULL)
        {
            first=nxtp;
            return;
        }
        p=nxtp;
        nxtp=nxtp2;
    }
}
int main ()
{
    LinkList first;
    node a1,a2,a3;
    first=&a1;
    a1.link=&a2;
    a2.link=&a3;
    a3.link=NULL;
    a1.data='1';
    a2.data='2';
    a3.data='3';
    myprint(first);
    trans(first);
    myprint(first);
    return 0;
}
