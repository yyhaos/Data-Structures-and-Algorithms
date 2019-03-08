#include<bits/stdc++.h>
using namespace std;
const int  monthday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int mday[]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};

struct item
{
    string name;
    double score;
    bool operator < (item & a)
    {
        return score<=a.score;
    }
};
item p[10000];
class date
{
public:
    int year,month,day,week;
    date(int y,int m,int d):
        year(y),month(m),day(d){
            week=(mday[month]+day-1)%7;
        }
    date(int th=1)
        {
            year=2006;
            for(month=1;month<=12;month++)
            {
                if(th>mday[month+1])
                    continue;
                else
                    break;
            }
            day=th-mday[month];
            //cout<<month<<"��"<<day<<endl;
            week=(mday[month]+day-1)%7;
        }
    int th(){
        return mday[month]+day;
    }
    bool operator < (date a){
        return th()<a.th();
    }
    bool operator == (date a){
        if(year==a.year && month == a.month && day==a.day)
            return true;
        return false;
    }
    friend ostream& operator << (ostream& os,const date &a);
    friend istream& operator >> (istream& is,date &a);
};
ostream& operator <<(ostream& os,const date &a)
{
    os<<a.year<<"��"<<a.month<<"��"<<a.day<<"��";
    return os;
}
istream& operator >> (istream& is,date &a)
{
    is>>a.year>>a.month>>a.day;
    return is;
}
class inf
{
public:
    int number;     //320600
    string name;    //��ͨ
    string main_pollution;  //--
    int score;      //43
    string level2;  //I
    string level;   //��
    date time;      //2006 12 31
    inf(int n=1,date a=date(0)){
        number=n;
        time=a;
    }
    friend ostream& operator << (ostream &os,const inf &a);
    friend istream& operator >> (istream &os,inf &a);
    bool operator == (inf a)
    {
        return number==a.number && a.time==time;
    }
};
istream& operator >> (istream& is,inf &a)
{
    is>>a.number>>a.name>>a.main_pollution>>a.score>>a.level2>>a.level>>a.time;
    return is;
}
ostream& operator <<(ostream& os,const inf &a)
{
    if(a.time.day==0)
    {
        cout<<"û������"<<endl;
        return os;
    }
    os<<a.time<<a.name<<"�Ŀ�������Ϊ"<<a.level<<endl;
    //os<<a.year<<"��"<<a.month<<"��"<<a.day<<"��"<<endl;
    return os;
}
int find_su(int N)
{
    int flag=1;
    for(int i=N;i>=2;i--)
    {
        flag=1;
        for(int j=2;j<= sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            return i;
        }
    }
    return -1;
}
const int maxsize=27262*4;
const int mod=find_su(maxsize);
int chongfu=0;
int used[maxsize];
inf D[maxsize];
int f(inf a)   //ɢ�к���
{
    int flag=0;
  //  cout<<" "<<a.name<<a.time<<endl;
    int zhongzi=(a.number*8+a.time.th()*2+a.time.day)%mod;
    while(used[zhongzi])
    {
        if(D[zhongzi]==a)
            return zhongzi;
        //if(a.name=="ʯ��ׯ")
        //cout<<"�ظ�"<<D[zhongzi].name<<D[zhongzi].time<<" "<<a.name<<a.time<<endl;
        chongfu++;
        zhongzi++;
        zhongzi%=maxsize;
    }
    //chongfu+=flag;
    return zhongzi;
}
map<string , int> name2number;
map<int , string> number2name;
map<string , int> level2number;
int th[5000];
int use[1000000]={0};
int citycnt=0;
string levelname[]={"��","��","��΢��Ⱦ","�����Ⱦ","����Ⱦ"};
int main ()
{

    for(int i=0;i<5;i++)
    {
        level2number[levelname[i]]=i;
    }
    //cout<<mod<<endl;
    for(int i=0;i<maxsize;i++)
        use[i]=0;
    inf a;
    ifstream is("data.txt");
    int mycnt=0;
    while(is>>a)
    {
        mycnt++;
        if(used[a.number]==0)
        {
            used[a.number]=1;
            th[citycnt++]=a.number;
        }
        name2number[a.name]=a.number;
        number2name[a.number]=a.name;
        int pos=f(a);
        D[pos]=a;
        used[pos]=1;
    }
   // cout<<chongfu<<endl;
    cout<<"��"<<mycnt<<"������,������"<<citycnt<<"������"<<endl;
    //cout<<mod<<endl;
    string name;
    int Year,Month,Day,number,Week;
    char flag='Y';
    cout<<"��ͨ��ѯ:"<<endl;
    while(flag=='Y')    // ��ͨ��ѯ
    {
        cout<<"�����ѯ�ĳ�������";
        cin>>name;
        number=name2number[name];
        //cout<<number<<endl;
        cout<<"�����ѯ��������";
        int day;
        cin>>day;
        date t(day);
        cout<<D[f(inf(number,t))];

        cout<<"�����ѯ������";
        cin>>Week;
        for(int i=Week*7-6;i<=Week*7;i++)
        {
            if(i<=0 || i>=366)
                continue;
            date tmp(i);
            //cout<<tmp<<endl;
            //cout<<inf(number,tmp)<<endl;;
            //cout<<"f"<<f(inf(number,tmp))<<endl;;
            //cout<<inf(number,tmp)<<endl;
            cout<<D[f(inf(number,tmp))];
        }

        cout<<"�����ѯ������";
        int month;
        cin>>month;
        for(int i=mday[month]+1;i<=mday[month+1];i++)
        {
            if(i<=0 || i>=366)
                continue;
            date tmp(i);
            cout<<D[f(inf(number,tmp))];
        }

        cout<<"�����ѯ�ļ��� ��1 = ��1���� = 1~3�£�";
        int season;
        cin>>season;
        for(int i=mday[season*3-2]+1;i<=mday[season*3+1];i++)
        {
            if(i<=0 || i>=366)
                continue;
            date tmp(i);
            cout<<D[f(inf(number,tmp))];
        }
        cout<<"��Ҫ������ͨ��ѯ�𣿣�Y/N�� N�Ļ�����ͳ�Ʋ�ѯ"<<endl;
        cin>>flag;
    }

    flag='Y';
    cout<<"ͳ�Ʋ�ѯ��1��"<<endl;
    while(flag=='Y')    // ͳ�Ʋ�ѯ1
    {
        cout<<"�����ѯ�ĳ�������";
        cin>>name;
        number=name2number[name];
        //cout<<number<<endl;
        int cnt[10]={0};

        cout<<"�����ѯ������";
        cin>>Week;
        for(int i=Week*7-6;i<=Week*7;i++)
        {
            if(i<=0 || i>=366)
                continue;
            date tmp(i);
            if(D[f(inf(number,tmp))].time.day==0)
            {
                cout<<tmp<<"û������"<<endl;
            }
            else
            {
                cnt[level2number[D[f(inf(number,tmp))].level]]++;
            }
        }
        for(int i=0;i<5;i++)
        {
            cout<<levelname[i]<<" :\t"<<cnt[i]<<endl;
            cnt[i]=0;
        }

        cout<<"�����ѯ������";
        int month;
        cin>>month;
        for(int i=mday[month]+1;i<=mday[month+1];i++)
        {
            if(i<=0 || i>=366)
                continue;
            date tmp(i);
            if(D[f(inf(number,tmp))].time.day==0)
            {
                cout<<tmp<<"û������"<<endl;
            }
            else
            {
                cnt[level2number[D[f(inf(number,tmp))].level]]++;
            }
        }
        for(int i=0;i<5;i++)
        {
            cout<<levelname[i]<<" :\t"<<cnt[i]<<endl;
            cnt[i]=0;
        }

        cout<<"�����ѯ�ļ��� ��1 = ��1���� = 1~3�£�";
        int season;
        cin>>season;
        for(int i=mday[season*3-2]+1;i<=mday[season*3+1];i++)
        {
            if(i<=0 || i>=366)
                continue;
            date tmp(i);
            if(D[f(inf(number,tmp))].time.day==0)
            {
                cout<<tmp<<"û������"<<endl;
            }
            else
            {
                cnt[level2number[D[f(inf(number,tmp))].level]]++;
            }
        }
        for(int i=0;i<5;i++)
        {
            cout<<levelname[i]<<" :\t"<<cnt[i]<<endl;
            cnt[i]=0;
        }

        cout<<"ȫ���ѯ"<<endl;
        int cnt2=0;
        for(int i=1;i<=365;i++)
        {
            date tmp(i);
            if(D[f(inf(number,tmp))].time.day==0)
            {
                cnt2++;
                //cout<<tmp<<"û������"<<endl;
            }
            else
            {
                cnt[level2number[D[f(inf(number,tmp))].level]]++;
            }
        }
        for(int i=0;i<5;i++)
        {
            cout<<levelname[i]<<" :\t"<<cnt[i]<<endl;
            cnt[i]=0;
        }
        cout<<"��"<<cnt2<<"��û������"<<endl;

        cout<<"��Ҫ����ͳ�Ʋ�ѯ��1���𣿣�Y/N�� N�Ļ�����ͳ�Ʋ�ѯ��2��"<<endl;
        cin>>flag;
    }

    cout<<"ͳ�Ʋ�ѯ��2��"<<endl;
    flag='Y';
    string level;
    int levelth;
    int type,x;
    while(flag=='Y')
    {
        int cnt[10]={0};
        cout<<"�����ѯ������";
        cin>>Week;
        cout<<"�����ѯ����Ŀ";

        cin>>level;
        levelth=level2number[level];
        cout<<"�����ѯ������ type x ��type 1: >=x 2: <=x 3: ==x��";
        cin>>type>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            for(int i=Week*7-6;i<=Week*7;i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    cnt[level2number[D[f(inf(number,tmp))].level]]++;
                }
            }
            switch(type)
                {
                    case 1: if(cnt[levelth]>=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 2: if(cnt[levelth]<=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 3: if(cnt[levelth]==x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                }
            for(int i=0;i<5;i++)
            {
                cnt[i]=0;
            }
            //cout<<endl;
        }


        cout<<"\n�����ѯ������";
        int month;
        cin>>month;
        cout<<"�����ѯ����Ŀ";
        //string level;
        cin>>level;
        levelth=level2number[level];
        cout<<"�����ѯ������ type x ��type 1: >=x 2: <=x 3: ==x��";
        cin>>type>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            for(int i=mday[month]+1;i<=mday[month+1];i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    cnt[level2number[D[f(inf(number,tmp))].level]]++;
                }
            }
            switch(type)
                {
                    case 1: if(cnt[levelth]>=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 2: if(cnt[levelth]<=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 3: if(cnt[levelth]==x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                }
            for(int i=0;i<5;i++)
            {
                cnt[i]=0;
            }
            //cout<<endl;
        }

        cout<<"\n�����ѯ�ļ��� ��1 = ��1���� = 1~3�£�";
        int season;
        cin>>season;
        cout<<"�����ѯ����Ŀ";
        //string level;
        cin>>level;
        levelth=level2number[level];
        cout<<"�����ѯ������ type x ��type 1: >=x 2: <=x 3: ==x��";
        cin>>type>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            for(int i=mday[season*3-2]+1;i<=mday[season*3+1];i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    cnt[level2number[D[f(inf(number,tmp))].level]]++;
                }
            }
            switch(type)
                {
                    case 1: if(cnt[levelth]>=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 2: if(cnt[levelth]<=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 3: if(cnt[levelth]==x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                }
            for(int i=0;i<5;i++)
            {
                cnt[i]=0;
            }
            //cout<<endl;
        }

        cout<<"\nȫ���ѯ"<<endl;
        cout<<"�����ѯ����Ŀ";
        //string level;
        cin>>level;
        levelth=level2number[level];
        cout<<"�����ѯ������ type x ��type 1: >=x 2: <=x 3: ==x��";
        cin>>type>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            for(int i=1;i<=365;i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    cnt[level2number[D[f(inf(number,tmp))].level]]++;
                }
            }
            switch(type)
                {
                    case 1: if(cnt[levelth]>=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 2: if(cnt[levelth]<=x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                    case 3: if(cnt[levelth]==x)
                                cout<<number2name[number]<<'('<<cnt[levelth]<<')'<<"\t";
                                break;
                }
            for(int i=0;i<5;i++)
            {
                cnt[i]=0;
            }
            //cout<<endl;
        }

        cout<<"��Ҫ����ͳ�Ʋ�ѯ��2���𣿣�Y/N�� N�Ļ����������ѯ"<<endl;
        cin>>flag;
    }

    cout<<"\n�����ѯ\n";
    flag='Y';
    while(flag=='Y')
    {

        cout<<"�����ѯ������";
        cin>>Week;
        cout<<"�����ѯǰ��λ";
        cin>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            int sum=0;
            int ok=0;
            for(int i=Week*7-6;i<=Week*7;i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    sum+=D[f(inf(number,tmp))].score;
                    ok++;
                }
            }
            if(ok>0)
            {
                p[k].name=number2name[number];
                p[k].score=1.0*sum/ok;
            }
            else
            {
                p[k].score=0;
                p[k].name=number2name[number];
            }
            //cout<<endl;
        }
        sort(p,p+citycnt);
        for(int i=0;i<x;i++)
        {
            cout<<p[i].name<<'('<<p[i].score<<')'<<"\t";
        }
        cout<<"\n";

        cout<<"�����ѯ������";
        int month;
        cin>>month;
        cout<<"�����ѯǰ��λ";
        cin>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            int sum=0;
            int ok=0;
            for(int i=mday[month]+1;i<=mday[month+1];i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    sum+=D[f(inf(number,tmp))].score;
                    ok++;
                }
            }
            if(ok>0)
            {
                p[k].name=number2name[number];
                p[k].score=1.0*sum/ok;
            }
            else
            {
                p[k].score=0;
                p[k].name=number2name[number];
            }
            //cout<<endl;
        }
        sort(p,p+citycnt);
        for(int i=0;i<x;i++)
        {
            cout<<p[i].name<<'('<<p[i].score<<')'<<"\t";
        }
        cout<<"\n";

        cout<<"�����ѯ�ļ���";
        int season;
        cin>>season;
        cout<<"�����ѯǰ��λ";
        cin>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            int sum=0;
            int ok=0;
            for(int i=mday[season*3-2]+1;i<=mday[season*3+1];i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    sum+=D[f(inf(number,tmp))].score;
                    ok++;
                }
            }
            if(ok>0)
            {
                p[k].name=number2name[number];
                p[k].score=1.0*sum/ok;
            }
            else
            {
                p[k].score=0;
                p[k].name=number2name[number];
            }
            //cout<<endl;
        }
        sort(p,p+citycnt);
        for(int i=0;i<x;i++)
        {
            cout<<p[i].name<<'('<<p[i].score<<')'<<"\t";
        }
        cout<<"\n";

        cout<<"ȫ���ѯ\n";
        cout<<"�����ѯǰ��λ";
        cin>>x;
        for(int k=0;k<citycnt;k++)
        {
            number=th[k];
            int sum=0;
            int ok=0;
            for(int i=1;i<=365;i++)
            {
                if(i<=0 || i>=366)
                    continue;
                date tmp(i);
                if(D[f(inf(number,tmp))].time.day==0)
                {
                    //cout<<tmp<<"û������"<<endl;
                }
                else
                {
                    sum+=D[f(inf(number,tmp))].score;
                    ok++;
                }
            }
            if(ok>0)
            {
                p[k].name=number2name[number];
                p[k].score=1.0*sum/ok;
            }
            else
            {
                p[k].score=0;
                p[k].name=number2name[number];
            }
            //cout<<endl;
        }
        sort(p,p+citycnt);
        for(int i=0;i<x;i++)
        {
            cout<<p[i].name<<'('<<p[i].score<<')'<<"\t";
        }
        cout<<"\n";

        cout<<"��Ҫ���������ѯ�𣿣�Y/N�� N�Ļ��Ƴ�����"<<endl;
        cin>>flag;
    }
    return 0;
}

