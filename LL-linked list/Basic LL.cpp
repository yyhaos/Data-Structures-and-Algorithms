#include<bits/stdc++.h>
using namespace std;

void show(int i);
struct Vertex
{
    int item;
    Vertex* next;
};

Vertex a0,a1,a2,a3,* head,* tail;   //both head and tail need *
int i, N;

Vertex* Get(int i)
{
    Vertex* ptr=head;
    for(int k=0;k<i;k++)
    {
        ptr = ptr->next;            //need '->'  not '.'
    }
    //printf("GET = (%d)",ptr->item);
    return ptr;
}

void InsertHead(int v)
{
    Vertex* vtx=new Vertex();
    vtx->item = v;
    vtx->next = head;
    head = vtx;
}

void Insert(int index, int value)
{
    Vertex *pre = Get(index-1);
    Vertex *aft = pre->next;
    Vertex *vtx = new Vertex();
    vtx->item = value;
    vtx->next = aft;
    pre->next = vtx;
}
void InsertTail(int v)
{
    Vertex *vtx = new Vertex();
    vtx->item = v;
    tail->next = vtx;
    tail = vtx;
}
void RemoveHead(void)
{
    if(head == NULL) return ;
    Vertex *temp = head;
    head = temp->next;
   // delete temp;              //The pointer released by the system can not be deleted
}
void Remove(int index)
{
    //show(N+1);
    //Vertex *pre = new Vertex();
    Vertex* del = new Vertex();
    //Vertex *aft = new Vertex();
    Vertex *pre = Get(index-1);
    del = pre->next;
    Vertex *aft = del->next;
    //printf("pre=%d del=%d aft=%d\n",pre->item,del->item,aft->item);
    pre->next = aft;
    //delete del;               //??? The pointer released by the system can not be deleted
}
void RemoveTail(void)
{
    Vertex* pre = head;
    Vertex* temp = new Vertex();
    temp = head->next;
    while(temp->next!=NULL)
        pre = pre->next, temp = temp->next;
    pre->next = NULL;
    delete temp;
    tail = pre;
}
void show(int i)
{
    printf("the Vertex : ");
    for(int j = 0;j<i;j++)
    {
        printf("%d ",Get(j)->item);
    }
    printf("\n");
}
int main ()
{
    N=4;
    a0.item=0,a1.item=1,a2.item=2,a3.item=3;
    a0.next=&a1,a1.next=&a2,a2.next=&a3,a3.next=NULL;
    head=&a0, tail=&a3;

    show(N);
    InsertHead(-1);
    show(N+1);

    head=NULL;
    InsertHead(50);
    printf("head=%d\n",head->item);

    head=&a0;
    Insert(3,55);
    show(N+1);

    InsertTail(2323);
    show(N+2);

    RemoveHead();
    show(N+1);

    Remove(1);
    show(N);

    RemoveTail();
    show(N-1);
    return 0;
}
