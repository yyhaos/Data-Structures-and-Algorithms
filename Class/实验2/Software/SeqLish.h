#include<malloc.h>
#include<stdio.h>
#define INF ((1<<31)-1)
#define initSize 100        	//���������
typedef int DataType;	//Ԫ�ص���������

typedef struct
{
       DataType *data;      	//�洢����
	   int n; 	          		//��ǰ��Ԫ�ظ���
       int maxSize;    		//�����󳤶�
} SeqList;

void InitList (SeqList& L)
{
    L.data=(DataType*)malloc(initSize*sizeof( DataType));
    if ( L.data == NULL)
    {
        printf ("�洢����ʧ��!\n");
        exit (1);
    }
    L.n = 0;  L.maxSize = initSize;
}

int Find ( SeqList& L, DataType x )
{
    for ( int i = 0; i < L.n; i++ )
        if ( L.data[i] == x ) return i;     //���ҳɹ�
    return -1;			          //����ʧ��
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
    //�ڱ��е� i (1��i��n+1) ��λ�ò�����Ԫ�� x
    if ( L.n == L.maxSize )
        Expansion(L);   //�������������
    if ( i < 1 || i > L.n+1 )
        return false;
    for ( int j = L.n-1; j >= i-1; j--)
        L.data[j+1] = L.data[j];
    L.data[i-1] = x;    	//ʵ�ʲ��ڵ�i-1��λ��
    L.n++;
    return true;  	//����ɹ�
}

bool Remove ( SeqList& L, int i, DataType& x )
{
//�ڱ���ɾ���� i ��Ԫ�أ�ͨ�� x ������ֵ
    if ( L.n > 0 && i > 0 && i <= L.n )
    {
        x = L.data[i-1];
        for (int j = i; j < L.n; j++)
            L.data[j-1] = L.data[j];
        L.n--;
        return true;	//ɾ���ɹ�
    }
    else return false;                 //ɾ��ʧ��
}

bool isEmpty(SeqList& L)
{
    if ( L.n ==0 )
        return true;	//���
    else return false;
}

bool isFull(SeqList& L)
{
    if ( L.n == L.maxSize)
        return true;	//����
    else return false;
}

int Len(SeqList& L)
    {return L.n;}

void Copy(SeqList &L1,SeqList &L2)  //��L2���Ƶ�L1
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
    tem+=initSize;  //ÿ�μ�initSize�Ĵ�С

    SeqList L2;
    L2.maxSize=tem;
    L2.n=L.n;
    L2.data=(DataType*)malloc(tem*sizeof( DataType));
    if ( L2.data == NULL)
    {
        printf ("����洢����ʧ��!\n");
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

