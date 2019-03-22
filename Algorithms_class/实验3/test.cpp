#include<iostream>
#include<random>
#include<time.h>
using namespace std;
time_t now;
#define ll long long
const ll Year=5;    //计算年数
const ll NumShip=24;    //每月船数
const double AveStop=24;    //船平均停泊时间
const double HalfRangeStop=20;  //船停泊时间的半极差
const double AveArrive=30;  //船平均到达相隔时间
const double HalfRangeArrive=15;    //船平均到达时间的半极差
const double CostPerHour=1000;  //船等待单位时间消耗
const ll Month[]={0,0,31,59,90,120,151,181,212,243,273,304,334};
double Arrive[Year*12*NumShip+1];   //每一艘船的到达时间
double Stop[Year*12*NumShip+1]; //每一艘传的停泊时间
double getRandom(double ave,double hfrange);   //得到一个在ave-hfrange 到 ave+hfrange的随机浮点数
void init(); //初始化每艘船的到达时间、停泊时间
double get();    //模拟一次（默认5年）得到的消耗钱数
double getAve(ll N); //进行N次模拟，并求出N次模拟值的平均值
int main ()
{
    srand(time(0)); //随机数种子
    for(int i=10000;i<=20000;i+=2000)
    {
        cout<<i<<"  times:\tCNY "<<(ll)getAve(i)/10000LL<<",0000"<<endl;
    }
    return 0;
}
double getRandom(double ave,double hfrange)   //得到一个在ave-hfrange 到 ave+hfrange的随机浮点数
{
    double randnumber=1.0*rand()/RAND_MAX;
    return ave+2.0*hfrange*(randnumber-0.5);
}
void init() //初始化每艘船的到达时间、停泊时间
{
    Arrive[0]=0;
    for(int i=1;i<=Year*12*NumShip;i++)
    {
        Arrive[i]=Arrive[i-1]+getRandom(AveArrive,HalfRangeArrive);
        Stop[i]=getRandom(AveStop,HalfRangeStop);
    }
}
double get()    //模拟一次（默认5年）得到的消耗钱数
{
    init();
    double cost=0;
    double preLeaveTime=0;  //记录上一艘船的离开时间
    for(ll i=1;i<=Year*12*NumShip;i++)
    {
        //cost+=max(0.0,CostPerHour*(Arrive[i+1]-Arrive[i]-Stop[i]));错误 没有考虑等待后的船的到达时间会改变
        if(i!=1)    //第一艘船不会有等待费用
        {
            if(Arrive[i]<preLeaveTime)  //当前一艘船还没有离开的时候就到了新船 就要计算费用
            {
                cost+=CostPerHour*(preLeaveTime-Arrive[i]);
                Arrive[i]=preLeaveTime; //更新真正到达时间
            }
        }
        preLeaveTime=Arrive[i]+Stop[i]; //更新离开时间
    }
    return cost;
}
double getAve(ll N) //进行N次模拟，并求出N次模拟值的平均值
{
    double sum=0;
    for(int i=1;i<=N;i++)
    {
        sum+=get();
    }
    return sum/N;
}
