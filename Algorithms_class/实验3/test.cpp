#include<iostream>
#include<random>
#include<time.h>
using namespace std;
time_t now;
#define ll long long
const ll Year=5;    //��������
const ll NumShip=24;    //ÿ�´���
const double AveStop=24;    //��ƽ��ͣ��ʱ��
const double HalfRangeStop=20;  //��ͣ��ʱ��İ뼫��
const double AveArrive=30;  //��ƽ���������ʱ��
const double HalfRangeArrive=15;    //��ƽ������ʱ��İ뼫��
const double CostPerHour=1000;  //���ȴ���λʱ������
const ll Month[]={0,0,31,59,90,120,151,181,212,243,273,304,334};
double Arrive[Year*12*NumShip+1];   //ÿһ�Ҵ��ĵ���ʱ��
double Stop[Year*12*NumShip+1]; //ÿһ�Ҵ���ͣ��ʱ��
double getRandom(double ave,double hfrange);   //�õ�һ����ave-hfrange �� ave+hfrange�����������
void init(); //��ʼ��ÿ�Ҵ��ĵ���ʱ�䡢ͣ��ʱ��
double get();    //ģ��һ�Σ�Ĭ��5�꣩�õ�������Ǯ��
double getAve(ll N); //����N��ģ�⣬�����N��ģ��ֵ��ƽ��ֵ
int main ()
{
    srand(time(0)); //���������
    for(int i=10000;i<=20000;i+=1000)
    {
        cout<<i<<"��\t:\t"<<(ll)getAve(i)/10000LL<<"��Ԫ"<<endl;
    }
    return 0;
}
double getRandom(double ave,double hfrange)   //�õ�һ����ave-hfrange �� ave+hfrange�����������
{
    double randnumber=1.0*rand()/RAND_MAX;
    return ave+2.0*hfrange*(randnumber-0.5);
}
void init() //��ʼ��ÿ�Ҵ��ĵ���ʱ�䡢ͣ��ʱ��
{
    Arrive[0]=0;
    for(int i=1;i<=Year*12*NumShip;i++)
    {
        Arrive[i]=Arrive[i-1]+getRandom(AveArrive,HalfRangeArrive);
        Stop[i]=getRandom(AveStop,HalfRangeStop);
    }
}
double get()    //ģ��һ�Σ�Ĭ��5�꣩�õ�������Ǯ��
{
    init();
    double cost=0;
    double preLeaveTime=0;  //��¼��һ�Ҵ����뿪ʱ��
    for(ll i=1;i<=Year*12*NumShip;i++)
    {
        //cost+=max(0.0,CostPerHour*(Arrive[i+1]-Arrive[i]-Stop[i]));���� û�п��ǵȴ���Ĵ��ĵ���ʱ���ı�
        if(i!=1)    //��һ�Ҵ������еȴ�����
        {
            if(Arrive[i]<preLeaveTime)  //��ǰһ�Ҵ���û���뿪��ʱ��͵����´� ��Ҫ�������
            {
                cost+=CostPerHour*(preLeaveTime-Arrive[i]);
                Arrive[i]=preLeaveTime; //������������ʱ��
            }
        }
        preLeaveTime=Arrive[i]+Stop[i]; //�����뿪ʱ��
    }
    return cost;
}
double getAve(ll N) //����N��ģ�⣬�����N��ģ��ֵ��ƽ��ֵ
{
    double sum=0;
    for(int i=1;i<=N;i++)
    {
        sum+=get();
    }
    return sum/N;
}
