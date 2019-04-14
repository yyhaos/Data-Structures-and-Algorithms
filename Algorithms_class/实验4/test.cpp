//#include<bits/stdc++.h>
#include<iostream>
#include<random>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int tar[100000005];//ԭ����   ÿ�ζ��������
int tmp[100000005];//�������� ÿ�ζ���ʼ����ԭ����
void show(int n)//��ӡ��������
{
    for(int i=0;i<n;i++)
    {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
}
void init(int n)//��������İ취��ʼ��ԭ����
{
    for(int i=0;i<n;i++)
    {
        tar[i]=(rand() % 20001) - 10000;//���ݷ�Χ-10000~10000
    }
    return ;
}
void mao(int n)//ð������
{
    double maxn=5;//����ʱ��

    for(int i=0;i<n;i++)//��ʼ��
        tmp[i]=tar[i];

    clock_t st,ed;//��ʱ��
    st=clock();//��¼��ʼ��ʱ��
    for(int i=0;i<n;i++)
    {
        ed=clock();//��¼��ǰ��ʱ��
        if((double) (ed-st) / CLOCKS_PER_SEC > maxn)//����������е�ʱ�䳬����maxn�룬���˳�
        {
            break;
        }
        for(int j=n-1;j>i;j--)
        {
            if(tmp[j]<tmp[j-1])
                swap(tmp[j],tmp[j-1]);
        }
    }

    if((double) (ed-st) / CLOCKS_PER_SEC > maxn)//�����ǰʱ�䳬����maxn�룬��˵��
    {
        cout<<"ð����������ʱ�䳬��"<<maxn<<"��"<<endl;
        return ;
    }
    else
    {
        cout<<"ð����������ʱ��Ϊ"<<(double) (ed-st) / CLOCKS_PER_SEC <<"s"<<endl;//�������
    }
}
void quick(int l,int r)//��������ĵݹ麯��
{
    //cout<<" "<<l<<" "<<r<<endl;
    if(r<=l)//�ݹ����
        return;
    int ra=rand()%(r-l)+l;
    swap(tmp[ra],tmp[l]);
    int tar=tmp[l];//��׼��Ŀ��
    int pl=l+1,pr=r;//����ָ�룬һǰһ��
    while(pl<pr)
    {
        if(tmp[pl]<=tar)//���������в��ö�
        {
            pl++;
            continue;
        }
        if(tmp[pr]>tar)//���������в���
        {
            pr--;
            continue;
        }
        swap(tmp[pl],tmp[pr]);//���߾����������������������
    }
    if(tar>tmp[pl])//��ʣ�µ�Ψһһ��δ�������������� С�ڻ�׼ ����ǰ��
    {
        swap(tmp[l],tmp[pl]);
        quick(l,pl-1);//�ݹ�
        quick(pl+1,r);
    }
    else//���ڻ�׼�����ں���
    {
        swap(tmp[l],tmp[pl-1]);
        quick(l,pl-2);
        quick(pl,r);
    }
}
void kuai(int n)//���ÿ�������
{

    for(int i=0;i<n;i++)//����������
        tmp[i]=tar[i];
    clock_t st,ed;//��ʱ����
    st=clock();

    quick(0,n-1);//���ÿ�������

    ed=clock();
    cout<<"������������ʱ��Ϊ"<<(double)(ed-st)/CLOCKS_PER_SEC<<"s"<<endl;
}
void test(int n )
{
    cout<<"���й�ģΪ"<<n<<"�Ĳ��ԣ�"<<endl;
    double tol=0;

    init(n);

    mao(n);
    //show(n);
    kuai(n);

    cout<<endl;
}
int main ()
{
    for(int i=1;i<=10000000;i*=10)//����1��10��100��1000...10000000��ģ�Ĳ���
        test(i);
    //show(n);
    return 0;
}
