#include<iostream>
#include<string.h>
#include<string>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define mem(a,b) memset(a,b,sizeof(a))
int maze[105][105];
int ru[105];
int chu[105];
int n,m;
int find_chu(int t)
{
    if(chu[t]!=-1)
        return chu[t];
    int ans=0;
    rep(i,1,n)
    {
        if(maze[t][i]==1)
        {
            ans+=1+find_chu(i);
        }
    }
    chu[t]=ans;
    return ans ;
}

int find_ru(int t)
{
   // cout<<t<<endl;
    if(ru[t]!=-1)
        return ru[t];
    int ans=0;
    rep(i,1,n)
    {
       // cout<<"ll "<<i<<endl;
        if(maze[i][t]==1)
        {

            ans+=1+find_ru(i);
        }
    }
    ru[t]=ans;
    return ans;
}

int main ()
{
    freopen("test.txt","r",stdin);
    mem(maze,0);
    scanf("%d%d",&n,&m);
    rep(i,1,n)
        chu[i]=ru[i]=-1;

    int s,e;

    rep(i,1,m)
    {
        scanf("%d%d",&s,&e);
        maze[e][s]=1;
        //maze[e][s]=-1;
    }
    rep(i,1,n)
    {
        rep(j,1,n)
        cout<<maze[i][j]<<"\t";
        cout<<endl;
    }
    int ans=0;
    rep(i,1,n)
    {
        cout<<find_chu(i)<<" "<<find_ru(i)<<endl;
        if(find_chu(i)+find_ru(i)==n)
            ans++;
    }
    cout<<ans;
    return 0;
}
