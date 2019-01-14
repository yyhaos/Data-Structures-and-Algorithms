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
    int Number;//����
    Time Start,End; //ʱ��
    int Cost;//����
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

    //type=1:����ʱ�����,type=2:����ʱ���,type=3:������С,type=4:��ת��������
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
                    switch(type)//type=1:����ʱ�����,type=2:����ʱ���,type=3:������С,type=4:��ת��������
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
                            if(dis[j]>dis[minth]+Flight[path[minth]][minth].End.mi(Flight[minth][j].Start)+Flight[minth][j].FlightTime());  //����дdis[minth]+Flight[minth][j].End.mi(Flight[path[i]][minth].End) ������ܻ�����һ��ʱ�䣨�Ϸɻ�����ȵ�������������
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
                cout<<st<<"��"<<ed<<"��·��";
                cout<<"�ҵ���\n·���ǣ�";
                ShowPath(CityName,Flight,path,e);
                cout<<"\n������";
                switch(type)//type=1:����ʱ�����,type=2:����ʱ���,type=3:������С,type=4:��ת��������
                {
                case 1:
                    cout<<"����ʱ����";
                    Time(dis[e]).show();
                    break;
                case 2:
                    cout<<"ʱ����";
                    Time(dis[e]).show();
                    break;
                case 3:
                    cout<<"Ʊ����";
                    cout<<dis[e]<<"Ԫ";
                    break;
                case 4:
                    cout<<"ת��������";
                    cout<<dis[e]<<"��";
                    break;
                }
                cout<<endl;
            }
            else
            {
                cout<<st<<"��"<<ed<<"��·��";
                cout<<"�Ҳ���\n";
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
                cout<<setw(10)<<setfill(' ')<<"����";
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
                cout<<setw(10)<<setfill(' ')<<"����ʱ��";
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
                cout<<setw(10)<<setfill(' ')<<"����ʱ��";
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
    //g.AddEdge(6320,"����","�Ϻ�",16,20,17,25,680);
//    cin.getline()
    int number;//����
    string st,ed,st2,ed2;//�ص�
    int sh,sm,eh,em,sh2,sm2,eh2,em2;//ʱ��
    int cost;//����
    while(input>>number)
    {
        cout<<"��ȡ��"<<number<<"����"<<endl;
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
        cout<<"��������������\n";
        cin>>St;
        cout<<"��������������\n";
        cin>>Ed;
        cout<<"�������ѯ�����ͣ�type��type=1:����ʱ�����,type=2:����ʱ���,type=3:������С,type=4:��ת��������)\n";
        cin>>Type;
        g.Dijkstra(St,Ed,Type);
        cout<<"��Ҫ������ѯ�𣿣�Y/N��\n";
        cin>>flag;
    }

    return 0;
}
