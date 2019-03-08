#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
const int MaxCityNumber=50;
using namespace std;
class Time
{
public:
    int hour,minute;
    Time(int h,int m):hour(h),minute(m){}
    Time(int m)
    {
        hour=m/60;
        minute=m%60;
    }
    void show()
    {
        if(hour!=0 || minute!=0)
        {
            cout<<setw(5)<<"     ";
            cout<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<minute;
        }
        else
            cout<<setfill(' ')<<setw(10)<<"-";
    }
    int Tminute()
    {
        return hour*60-minute;
    }
    int mi(Time a)
    {
        int mi1=hour*60+minute;
        int mi2=a.hour*60+a.minute;
        if(mi2<=mi1)
            mi2+=24*60;
        return mi2-mi1;
    }
//    friend ostream& operator <<(ostream& os,const Time& a );
};

class Edge
{
public:
    int Number;//机号
    Time Start,End; //时间
    int Cost;//费用
    Edge(int number=0,int sh=0,int sm=0,int eh=0,int em=0,int cost=0):
        Number(number),Start(sh,sm),End(eh,em),Cost(cost){}
    int FlightTime(void)
    {
        return Start.mi(End);
    }
};
void ShowPath(string CityName[],Edge Flight[][MaxCityNumber],int path[],int ta)
{
    if(path[ta]!=-1)
    {
        ShowPath(CityName,Flight,path,path[ta]);
    }
    if(path[ta]!=-1)
        cout<<"-"<<"("<<Flight[ta][path[ta]].Number<<")->"<<CityName[ta];
    else
        cout<<CityName[ta];
}
class MGraph
{
public:
    int CityTotalNumber;
    string CityName[MaxCityNumber];
    Edge Flight[MaxCityNumber][MaxCityNumber];

    //type=1:飞行时间最短,type=2:总用时最短,type=3:费用最小,type=4:中转次数最少
    void Dijkstra(string st,string ed,int type)
    {
        //int parent[MaxCityNumber];
        int path[MaxCityNumber];
        int dis[MaxCityNumber];
        int vis[MaxCityNumber];
        int s=FindCityNumber(st);
        int e=FindCityNumber(ed);
        const int Maxn=9999999;
        for(int i=0;i<CityTotalNumber;i++)
            dis[i]=Maxn,vis[i]=0,path[i]=-1;
        dis[s]=0;
        for(int i=1;i<=CityTotalNumber;i++)
        {
            int minn=Maxn,minth;
            for(int j=0;j<CityTotalNumber;j++)
            {
                if(vis[j]==0 && dis[j]<minn)
                {
                    minn=dis[j];
                    minth=j;
                }
            }
            vis[minth]=1;
//cout<<"minth="<<CityName[minth]<<endl;
            if(minth==e)
                break;
            //cout<<"min="<<minn<<" "<<minth<<endl;
            for(int j=0;j<CityTotalNumber;j++)
            {
                if(vis[j]==0 && Flight[minth][j].Cost!=0)
                {
                    switch(type)//type=1:飞行时间最短,type=2:总用时最短,type=3:费用最小,type=4:中转次数最少
                    {
                    case 1:
                        dis[j]=min(dis[j],dis[minth]+Flight[minth][j].FlightTime());
                        if(dis[j]==dis[minth]+Flight[minth][j].FlightTime())
                            path[j]=minth;
                        break;
                    case 2:
                        if(path[minth]!=-1)
                        {
//                            Flight[minth][j].Start.show();
//                            cout<<" ";
//                            Flight[path[minth]][minth].End.show();
//                            cout<<" ";
                            if(dis[j]>dis[minth]+Flight[path[minth]][minth].End.mi(Flight[minth][j].Start)+Flight[minth][j].FlightTime());  //不能写dis[minth]+Flight[minth][j].End.mi(Flight[path[i]][minth].End) 否则可能会少算一天时间（上飞机必须等到明天的情况）。
                            {
                                dis[j]=dis[minth]+Flight[path[minth]][minth].End.mi(Flight[minth][j].Start)+Flight[minth][j].FlightTime();
                                path[j]=minth;
                            }
                        }
                        else
                        {
                            if(dis[j]>Flight[minth][j].FlightTime())
                            {
                                dis[j]=Flight[minth][j].FlightTime();
                                path[j]=minth;
                            }
                        }
                        break;
                    case 3:
                        if(dis[j]>dis[minth]+Flight[minth][j].Cost)
                        {
                            dis[j]=dis[minth]+Flight[minth][j].Cost;
                            path[j]=minth;
                        }
                        break;
                    case 4:
                        if(dis[j]>1+dis[minth])
                        {
                            dis[j]=1+dis[minth];
                            path[j]=minth;
                        }
                    }
                }
            }
        }
        for(int i=0;i<CityTotalNumber;i++)
        {
            cout<<CityName[i]<<" : ";
            Time(dis[i]).show();
            cout<<" ";
        }
        cout<<endl;
        if(dis[e]<Maxn)
            {
                cout<<st<<"到"<<ed<<"的路径";
                cout<<"找到了\n路径是：";
                ShowPath(CityName,Flight,path,e);
                cout<<"\n总消耗";
                switch(type)//type=1:飞行时间最短,type=2:总用时最短,type=3:费用最小,type=4:中转次数最少
                {
                case 1:
                    cout<<"飞行时间是";
                    Time(dis[e]).show();
                    break;
                case 2:
                    cout<<"时间是";
                    Time(dis[e]).show();
                    break;
                case 3:
                    cout<<"票价是";
                    cout<<dis[e]<<"元";
                    break;
                case 4:
                    cout<<"转机次数是";
                    cout<<dis[e]<<"次";
                    break;
                }
                cout<<endl;
            }
            else
            {
                cout<<st<<"到"<<ed<<"的路径";
                cout<<"找不到\n";
            }
    }
    MGraph()
    {
        CityTotalNumber=0;
    }
    int FindCityNumber(string cityname)
    {
        for(int i=0;i<CityTotalNumber;i++)
            if(CityName[i]==cityname)
                return i;
        return -1;
    }
    bool AddCity(string cityname)
    {
        if(FindCityNumber(cityname)==-1)
        {
            CityName[CityTotalNumber]=cityname;
            CityTotalNumber++;
            return true;
        }
        return false;
    }
    void AddEdge(int number,string st,string ed,int sh,int sm,int eh,int em,int cost)
    {
        AddCity(st),AddCity(ed);
        int s=FindCityNumber(st);
        int e=FindCityNumber(ed);
        Flight[s][e]=Edge(number,sh,sm,eh,em,cost);
    }
    void showCost()
    {
        for(int i=0;i<CityTotalNumber;i++)
        {
            if(i==0)
            {
                cout<<setw(10)<<setfill(' ')<<"花费";
                for(int j=0;j<CityTotalNumber;j++)
                    cout<<setw(10)<<CityName[j];
                cout<<endl;
            }
            cout<<setw(10)<<setfill(' ')<<CityName[i];
            for(int j=0;j<CityTotalNumber;j++)
            {
                if(Flight[i][j].Cost!=0)
                    cout<<setw(10)<<Flight[i][j].Cost;
                else
                    cout<<setw(10)<<"-";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void showStartTime()
    {
        for(int i=0;i<CityTotalNumber;i++)
        {
            if(i==0)
            {
                cout<<setw(10)<<setfill(' ')<<"出发时间";
                for(int j=0;j<CityTotalNumber;j++)
                    cout<<setw(10)<<CityName[j];
                cout<<endl;
            }
            cout<<setw(10)<<setfill(' ')<<CityName[i];
            for(int j=0;j<CityTotalNumber;j++)
            {
                Flight[i][j].Start.show();
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void showEndTime()
    {
        for(int i=0;i<CityTotalNumber;i++)
        {
            if(i==0)
            {
                cout<<setw(10)<<setfill(' ')<<"到达时间";
                for(int j=0;j<CityTotalNumber;j++)
                    cout<<setw(10)<<CityName[j];
                cout<<endl;
            }
            cout<<setw(10)<<setfill(' ')<<CityName[i];
            for(int j=0;j<CityTotalNumber;j++)
            {
                Flight[i][j].End.show();
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
void getTime(ifstream &input,int &h,int &m)
{
    input>>h;
    input.get();
    input.get();
    input>>m;
    cout<<"get Time"<<h<<":"<<m<<endl;
}
int main ()
{
    ifstream input("FlightData.txt",ios::in);
    string head;
    getline(input,head);
    MGraph g;
    //g.AddEdge(6320,"北京","上海",16,20,17,25,680);
//    cin.getline()
    int number;//机号
    string st,ed,st2,ed2;//地点
    int sh,sm,eh,em,sh2,sm2,eh2,em2;//时间
    int cost;//费用
    while(input>>number)
    {
        cout<<"读取了"<<number<<"航班"<<endl;
        input>>st>>ed>>st2>>ed2;
        getTime(input,sh,sm);
        getTime(input,sh2,sm2);
        //cout<<sh<<":"<<sm<<endl;
        getTime(input,eh,em);
        getTime(input,eh2,em2);
        input>>cost;
        g.AddEdge(number,st,ed,sh,sm,eh,em,cost);
        g.AddEdge(number,st2,ed2,sh2,sm2,eh2,em2,cost);
        input.get();
        input.get();
    }
    g.showCost();
    g.showStartTime();
    g.showEndTime();
    char flag='Y';
    string St,Ed;
    int Type;
    while(flag=='Y')
    {
        cout<<"请输入起点城市名\n";
        cin>>St;
        cout<<"请输入起点城市名\n";
        cin>>Ed;
        cout<<"请输入查询的类型：type（type=1:飞行时间最短,type=2:总用时最短,type=3:费用最小,type=4:中转次数最少)\n";
        cin>>Type;
        g.Dijkstra(St,Ed,Type);
        cout<<"还要继续查询吗？（Y/N）\n";
        cin>>flag;
    }

    return 0;
}
