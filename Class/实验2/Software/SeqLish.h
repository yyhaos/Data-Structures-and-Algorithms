#include<malloc.h>
#include<stdio.h>
#define INF ((1<<31)-1)
#define initSize 100        	//最大允许长度
typedef int DataType;	//元素的数据类型

typedef struct
{
       DataType *data;      	//存储数组
	   int n; 	          		//当前表元素个数
       int maxSize;    		//表的最大长度
} SeqList;

void InitList (SeqList& L)
{
    L.data=(DataType*)malloc(initSize*sizeof( DataType));
    if ( L.data == NULL)
    {
        printf ("存储分配失败!\n");
        exit (1);
    }
    L.n = 0;  L.maxSize = initSize;
}

int Find ( SeqList& L, DataType x )
{
    for ( int i = 0; i < L.n; i++ )
        if ( L.data[i] == x ) return i;     //查找成功
    return -1;			          //查找失败
}

int Locate(SeqList& L,int th)
{
    if(th<=0 || th>L.n)
        return INF;
    else
        return L.data[th-1];
}
bool Insert ( SeqList& L, DataType x, int i )
{
    bool Expansion(SeqList &L);
    //在表中第 i (1≤i≤n+1) 个位置插入新元素 x
    if ( L.n == L.maxSize )
        Expansion(L);   //表满则进行扩充
    if ( i < 1 || i > L.n+1 )
        return false;
    for ( int j = L.n-1; j >= i-1; j--)
        L.data[j+1] = L.data[j];
    L.data[i-1] = x;    	//实际插在第i-1个位置
    L.n++;
    return true;  	//插入成功
}

bool Remove ( SeqList& L, int i, DataType& x )
{
//在表中删除第 i 个元素，通过 x 返回其值
    if ( L.n > 0 && i > 0 && i <= L.n )
    {
        x = L.data[i-1];
        for (int j = i; j < L.n; j++)
            L.data[j-1] = L.data[j];
        L.n--;
        return true;	//删除成功
    }
    else return false;                 //删除失败
}

bool isEmpty(SeqList& L)
{
    if ( L.n ==0 )
        return true;	//表空
    else return false;
}

bool isFull(SeqList& L)
{
    if ( L.n == L.maxSize)
        return true;	//表满
    else return false;
}

int Len(SeqList& L)
    {return L.n;}

void Copy(SeqList &L1,SeqList &L2)  //把L2复制到L1
{
    L1.n=0;
    L1.maxSize=L2.maxSize;
    L1.data=(DataType*)malloc(L1.maxSize*sizeof( DataType));
    for(int i=0;i<L2.n;i++)
    {
        Insert(L1,L2.data[i],1+i);
    }
    return ;
}

bool Expansion(SeqList &L)
{
    int tem=L.maxSize;
    tem+=initSize;  //每次加initSize的大小

    SeqList L2;
    L2.maxSize=tem;
    L2.n=L.n;
    L2.data=(DataType*)malloc(tem*sizeof( DataType));
    if ( L2.data == NULL)
    {
        printf ("扩充存储分配失败!\n");
        exit (1);
    }
    for(int i=0;i<L.n;i++)
        L2.data[i]=L.data[i];
    //free(L.data);
    Copy(L,L2);
   // for(int i=0;i<L.n;i++)
   //     L.data[i]=L2.data[i];
    L.maxSize=tem;
    return true;
    //free(L2);
}

int Sum(SeqList L)
{
    int sum=0;
    for(int i=0;i<L.n;i++)
        sum+=L.data[i];
    return sum;
}

