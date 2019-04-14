//#include<bits/stdc++.h>
#include<iostream>
#include<random>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int tar[100000005];//原数组   每次都随机产生
int tmp[100000005];//排序数组 每次都初始化成原数组
void show(int n)//打印排序数组
{
    for(int i=0;i<n;i++)
    {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
}
void init(int n)//用随机数的办法初始化原数组
{
    for(int i=0;i<n;i++)
    {
        tar[i]=(rand() % 20001) - 10000;//数据范围-10000~10000
    }
    return ;
}
void mao(int n)//冒泡排序
{
    double maxn=5;//限制时间

    for(int i=0;i<n;i++)//初始化
        tmp[i]=tar[i];

    clock_t st,ed;//计时用
    st=clock();//记录开始的时间
    for(int i=0;i<n;i++)
    {
        ed=clock();//记录当前的时间
        if((double) (ed-st) / CLOCKS_PER_SEC > maxn)//如果程序运行的时间超过了maxn秒，就退出
        {
            break;
        }
        for(int j=n-1;j>i;j--)
        {
            if(tmp[j]<tmp[j-1])
                swap(tmp[j],tmp[j-1]);
        }
    }

    if((double) (ed-st) / CLOCKS_PER_SEC > maxn)//如果当前时间超过了maxn秒，就说明
    {
        cout<<"冒泡排序运行时间超过"<<maxn<<"秒"<<endl;
        return ;
    }
    else
    {
        cout<<"冒泡排序运行时间为"<<(double) (ed-st) / CLOCKS_PER_SEC <<"s"<<endl;//正常输出
    }
}
void quick(int l,int r)//快速排序的递归函数
{
    //cout<<" "<<l<<" "<<r<<endl;
    if(r<=l)//递归出口
        return;
    int ra=rand()%(r-l)+l;
    swap(tmp[ra],tmp[l]);
    int tar=tmp[l];//基准，目标
    int pl=l+1,pr=r;//两个指针，一前一后
    while(pl<pr)
    {
        if(tmp[pl]<=tar)//正常的序列不用动
        {
            pl++;
            continue;
        }
        if(tmp[pr]>tar)//正常的序列不动
        {
            pr--;
            continue;
        }
        swap(tmp[pl],tmp[pr]);//两边均非正常，交换后就正常了
    }
    if(tar>tmp[pl])//对剩下的唯一一个未排序数进行讨论 小于基准 放在前面
    {
        swap(tmp[l],tmp[pl]);
        quick(l,pl-1);//递归
        quick(pl+1,r);
    }
    else//大于基准，放在后面
    {
        swap(tmp[l],tmp[pl-1]);
        quick(l,pl-2);
        quick(pl,r);
    }
}
void kuai(int n)//调用快速排序
{

    for(int i=0;i<n;i++)//对排序数组
        tmp[i]=tar[i];
    clock_t st,ed;//计时间用
    st=clock();

    quick(0,n-1);//调用快速排序

    ed=clock();
    cout<<"快速排序运行时间为"<<(double)(ed-st)/CLOCKS_PER_SEC<<"s"<<endl;
}
void test(int n )
{
    cout<<"进行规模为"<<n<<"的测试："<<endl;
    double tol=0;

    init(n);

    mao(n);
    //show(n);
    kuai(n);

    cout<<endl;
}
int main ()
{
    for(int i=1;i<=10000000;i*=10)//进行1、10、100、1000...10000000规模的测试
        test(i);
    //show(n);
    return 0;
}
