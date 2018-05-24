#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=51021
struct skill
{
    int time,damage;

};
/*
bool cmp(skill a,skill b)
{
    if(a.time-b.time)
        return a.time<b.time;
    else
        return a.damage>b.damage;
}
*/

struct cmp{
    bool operator() (const skill& a, const skill& b ){
        if(a.time!=b.time)
            return a.time>b.time;
        else
            return a.damage<=b.damage;
    }
};

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        priority_queue <skill,vector<skill>,cmp> sks;
        int n,m,b,cnt;
        cin>>n>>m>>b;
        while (n--)
        {
            skill tem_sk;
            cin>>tem_sk.time>>tem_sk.damage;
            sks.push(tem_sk);
        }
        int time;
        while(!sks.empty())
        {
            cnt=1;
            skill top = sks.top();
            //printf("1 %d-%d\n",top.time,top.damage);
            sks.pop();
            time = top.time;
            int tem_damage=top.damage;
            while(!sks.empty())
            {
                skill top2 = sks.top();
                if(top2.time!=time)
                    break;
                sks.pop();
                cnt++;
                //printf("2 %d-%d\n",top2.time,top2.damage);
                if(cnt<=m)
                    tem_damage+=top2.damage;
                else
                    continue;
            }
            b-=tem_damage;
            if(b<=0)
                break;
        }
        if(b>0)
        {
            printf("alive\n");
        }
        else
        {
            printf("%d\n",time);
        }
    }
    return 0;
}
