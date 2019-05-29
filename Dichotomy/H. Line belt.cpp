//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-10;
const ll INF = 100000000;
const ll maxn=1000;

double p,q,r;
//const ll q=1e9+7;
//ll ksm(ll a,ll b)
//{
//    ll ans=1LL;
//    while(b>0)
//    {
//        if(b&1LL)
//            ans=ans*a%q;
//        a=a*a%q;
//        b/=2LL;
//    }
//    return ans;
//}

ll t,n,m;
inline double fa(double x)
{
    return x*x;
}
struct Point
{
    double x;
    double y;
    void get()
    {
        cin>>x>>y;
    }
    Point(double _x=0,double _y=0)
    {
        x=_x;
        y=_y;
    }
    friend Point operator + (Point a,Point b)
    {
        return Point(a.x+b.x,a.y+b.y);
    }
    friend Point operator / (Point a,double b)
    {
        return Point(a.x/b,a.y/b);
    }
    friend Point operator * (Point a,double b)
    {
        return Point(a.x*b,a.y*b);
    }
    double dis(Point b)
    {
        return sqrt(fa(x-b.x)+fa(y-b.y));
    }
    void show()
    {
        cout<<x<<"-"<<y<<"  ";
    }
};
double ti(double len,double v)
{
    return (len/v);
}
Point st,ed;
double gt(Point &b,Point &c)
{
    double Lab=b.dis(st);
    double Lbc=b.dis(c);
    double Lcd=c.dis(ed);
    return ti(Lab,p)+ti(Lbc,r)+ti(Lcd,q);
}
Point C,D;
double test(Point & b)
{
    Point c,d;
    c=C;
    d=D;
    double ff=0.2;
    Point m1,m2;
    while(c.dis(d)>eps)
    {
        m1=c*ff+d*(1-ff);
        m2=c*(1-ff)+d*ff;
        if(gt(b,m1) > gt(b,m2))
        {
            d=m1;
        }
        else
            c=m2;
    }
    return gt(b,c);
}
double tmp[4];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    Point A,B;
    A.get();
    B.get();

    C.get();
    D.get();
    st=A;
    ed=D;
    cin>>p>>q>>r;
    int cnt=1000;
    Point a1,a2,c1,c2;
    double t1,t2;
    while(A.dis(B)>eps)
    {
      //  A.show();
      //  B.show();
      //  cout<<endl;
        cnt--;
        double ff=0.2;
        a1=A*ff+B*(1-ff);
        a2=A*(1-ff)+B*ff;
      //  a1.show();
      //  a2.show();
      //  cout<<endl;
      //  cout<<"you£º"<<test(a1)<<" "<<test(a2)<<endl;
        if(test(a1)<test(a2))
        {
            A=a2;
        }
        else
            B=a1;
    }
//    B.show();
//    C.show();
//    cout<<endl;
    printf("%.2f\n",test(B));


#ifdef use_t
}
#endif // use_t
    return 0;
}
