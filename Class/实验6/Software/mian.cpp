#include<iostream>
using namespace std;
const int heapSize=1000,totalNumber=100;

typedef struct {
	char data;			   //结点的值
	int weight;			   //结点的权
	int parent, lchild, rchild;	   //双亲、左、右子女
} HTNode;

typedef struct {
	HTNode elem[totalNumber];   //树存储数组
	int num, root;			   //外结点数与根
} HFTree;

typedef int HElemType;	      //堆中元素的数据类型
typedef struct {		      //堆结构的定义
    HElemType elem[heapSize];	//小根堆存储数组
    int curSize;			//当前元素个数
} minHeap;

void CreateMinHeap(HFTree &tree,minHeap &heap,int n);
void ShiftUp(HFTree &tree,minHeap &heap,int x);
void ShiftDown(HFTree &tree,minHeap &heap,int x);
void Switch(minHeap &heap,int a,int b);
void ShowHeap(HFTree &tree,minHeap &heap);
void AddHeap(HFTree &tree,minHeap &heap,int pos);
void DeleteHeap(HFTree & tree,minHeap &heap ,int &pos,int &minn);
void AddTree(HFTree &tree,minHeap &heap,int i,int s1,int min1,int s2,int min2);
void ShowPreOrder(const HFTree &tree);
void PreOrder(const int a,const HFTree &tree);
void ShowMidOrder(const HFTree &tree);
void MidOrder(const int a,const HFTree &tree);
void EnCode(const HFTree &tree,int pos,char code[],int &len);
void DeCode(char value[],char tar[],const HFTree &tree,char result[]);

void createHFTree(HFTree& tree,char value[],int fr[], int n)
{
    for(int i=0;i<n;i++)
    {
        tree.elem[i].data=value[i];
        tree.elem[i].weight=fr[i];
        tree.elem[i].lchild=tree.elem[i].rchild=tree.elem[i].parent=-1;
    }
    minHeap heap;
    CreateMinHeap(tree,heap,n);
    //ShowHeap(tree,heap);
    int s1,s2,min1,min2;
    for(int i=n;i<2*n-1;i++)
    {
        DeleteHeap(tree,heap,s1,min1);
        DeleteHeap(tree,heap,s2,min2);
        //cout<<"s:"<<s1<<" "<<s2<<"  min:"<<min1<<" "<<min2<<endl;
        //ShowHeap(tree,heap);
        AddTree(tree,heap,i,s1,min1,s2,min2);
        //ShowHeap(tree,heap);
    }
    tree.num=n;
    tree.root=2*n-2;
}

void AddTree(HFTree &tree,minHeap &heap,int i,int s1,int min1,int s2,int min2)
{
    tree.elem[s1].parent = tree.elem[s2].parent = i;
    tree.elem[i].lchild = s1;  tree.elem[i].rchild = s2;
    tree.elem[i].weight =min1+min2,tree.elem[i].parent=-1;
    AddHeap(tree,heap,i);
}

void CreateMinHeap(HFTree &tree,minHeap &heap,int n)
{
    for(int i=1;i<=n;i++)
    {
        heap.elem[i]=i-1;
    }
    heap.curSize=n;
    //ShowHeap(tree,heap);
    for(int i=heap.curSize;i>=1;i--)
    {
        ShiftUp(tree,heap,i);
    }
}

void ShiftUp(HFTree &tree,minHeap &heap,int x)
{
    if(x<=1)
        return ;
    int nxt=heap.elem[x/2],now=heap.elem[x];
    //cout<<"ShiftUP"<<x<<"->"<<tree.elem[now].weight<<endl;
    if(tree.elem[nxt].weight>tree.elem[now].weight)
    {
        //cout<<"00ShiftUP"<<x<<"->"<<tree.elem[now].weight<<endl;
        Switch(heap,x/2,x);
        ShiftDown(tree,heap,x);
        ShiftUp(tree,heap,x/2);
    }
}

void ShiftDown(HFTree &tree,minHeap &heap,int x)
{
    if(x*2>heap.curSize)
        return ;
    if(x*2==heap.curSize)
    {
        int nxt=heap.elem[x*2],now=heap.elem[x];
        if(tree.elem[now].weight>tree.elem[nxt].weight)
        {
            Switch(heap,x,x*2);
            //ShiftDown(tree,heap,x*2);
        }
    }
    if(x*2<heap.curSize)
    {
        int to_switch=-1;
        int nxt=heap.elem[x*2],nxt2=heap.elem[x*2+1],now=heap.elem[x];
        if(tree.elem[now].weight<tree.elem[nxt].weight && tree.elem[now].weight<tree.elem[nxt2].weight)
            return ;
        if(tree.elem[now].weight>tree.elem[nxt].weight)
            to_switch=x*2;
        if(tree.elem[now].weight>tree.elem[nxt2].weight && tree.elem[nxt2].weight<tree.elem[nxt].weight)
            to_switch=x*2+1;
        Switch(heap,x,to_switch);
    }
   // cout<<"Shift Down"<<nxt<<" "<<x<<endl;
}
void Switch(minHeap &heap,int a,int b)
{
    int tmp=heap.elem[a];
    heap.elem[a]=heap.elem[b];
    heap.elem[b]=tmp;
    return ;
}

void ShowHeap(HFTree &tree,minHeap &heap)
{
    int cnt=1;
    cout<<"heap size:"<<heap.curSize<<endl;
    for(int i=1;cnt<=heap.curSize;i++)
    {
        for(int j=1;j<=i && cnt<=heap.curSize;j++)
        {
            cout<<tree.elem[heap.elem[cnt++]].weight<<" ";
        }
        cout<<endl;
    }
}

void AddHeap(HFTree &tree,minHeap &heap,int pos)
{
    heap.elem[++heap.curSize]=pos;
    ShiftUp(tree,heap,heap.curSize);
    return;
}

void DeleteHeap(HFTree & tree,minHeap &heap ,int &pos,int &minn)
{
    //ShowHeap(tree,heap);
    //cout<<"DeletHeap:"<<heap.curSize<<endl;
    if(heap.curSize<=0)
    {
        pos=minn=-1;
        return ;
    }
    pos=heap.elem[1];
    minn=tree.elem[pos].weight;
    heap.elem[1]=heap.elem[heap.curSize];
    //ShowHeap(tree,heap);
    heap.curSize--;
    ShiftDown(tree,heap,1);
    //ShowHeap(tree,heap);
    //cout<<endl;
    return ;
}

void ShowPreOrder(const HFTree &tree)
{
    cout<<"HFTree 的先序遍历是：";
    PreOrder(tree.root,tree);
    cout<<endl;
}

void PreOrder(const int a,const HFTree &tree)
{
    cout<<"\t"<<tree.elem[a].weight;
    if(tree.elem[a].lchild>=0)
        PreOrder(tree.elem[a].lchild,tree);
    if(tree.elem[a].rchild>=0)
        PreOrder(tree.elem[a].rchild,tree);
}

void ShowMidOrder(const HFTree &tree)
{
    cout<<"HFTree 的中序遍历是：";
    MidOrder(tree.root,tree);
    cout<<endl;
}

void MidOrder(const int a,const HFTree &tree)
{
    if(tree.elem[a].lchild>=0)
        MidOrder(tree.elem[a].lchild,tree);
    cout<<"\t"<<tree.elem[a].weight;
    if(tree.elem[a].rchild>=0)
        MidOrder(tree.elem[a].rchild,tree);
}


void EnCode(const HFTree &tree,int pos,char code[],int &len)
{

    int ans=0,cnt=0;
    int path[totalNumber];
    while(pos!=tree.root)
    {
        //cout<<pos<<endl;
        path[cnt++]=pos;
        pos=tree.elem[pos].parent;
    }
    len=cnt;
    for(int i=0;i<len;i++)
    {
        if(tree.elem[pos].lchild==path[cnt-1-i])
            code[i]='0';
        else
            code[i]='1';
        pos=path[cnt-1-i];
    }
    code[len]='\0';
    return;
}

void DeCode(char value[],char tar[],const HFTree &tree,char result[])
{
    int cnt=0, tmp=tree.root;
    for(int i=0;tar[i];i++)
    {
        if(tar[i]=='0' && tree.elem[tmp].lchild>=0)
        {
            tmp=tree.elem[tmp].lchild;
        }
        else if(tar[i]=='1' && tree.elem[tmp].rchild>=0)
        {
            tmp=tree.elem[tmp].rchild;
        }
        else
        {
            i--;
            result[cnt++]=tree.elem[tmp].data;
            tmp=tree.root;
        }
    }
    result[cnt++]=tree.elem[tmp].data;
    result[cnt]='\0';
}

int main ()
{
    HFTree tree;
    int fr[]={4,7,5,2,9};
    char value[]={'a','b','c','d','e'};
    char code[totalNumber][500];
    int codelen[totalNumber];
    createHFTree(tree,value,fr,5);

    ShowPreOrder(tree);
    ShowMidOrder(tree);


    cout<<endl;
    for(int i=0;i<5;i++)
        EnCode(tree,i,code[i],codelen[i]);
    cout<<"明文\t:\t密文"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<value[i]<<"\t:\t"<<code[i]<<endl;
    }

    cout<<endl;
    char tar[]="11000111000101011";
    char result[500];
    DeCode(value,tar,tree,result);
    cout<<tar<<"的明文是"<<result<<endl;// ecabceeb
}
