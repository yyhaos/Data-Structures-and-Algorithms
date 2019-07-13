//Problem Web:https://codeforces.com/gym/102212/problem/C
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
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
string str;
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
getchar();
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    getline(cin,str);
    char fi;
    int fi1=1;//句首
    int fi2=1;//单词首

    for(int i=0;str[i];i++)
    {

        if(str[i]>='a' && str[i]<='z' || (str[i]>='A' && str[i]<='Z'))
        {
            if(fi2==1)//单词首
            {
                fi=str[i];
                fi2=0;
            }
            else
            {
                if(fi1==1)//句首
                {
                    fi1=0;
                    printf("%c",toupper(str[i]));
                }
                else
                {
                    printf("%c",str[i]);
                }
            }

        }
        else//单词末
        {
            printf("%cay ",tolower(fi));
           // printf("%cay_",tolower(fi));
            fi2=1;
            fi=0;
        }
    }
    if(fi!=0 && fi1==0)//句末
    {
        printf("%cay",tolower(fi));
        //fi=1;
    }
    else if(fi!=0)//第一个单词只有一个字母的特判
    {
        printf("%cay",toupper(fi));
        //fi=1;
    }
    printf("\n");


#ifdef use_t
}
#endif // use_t
    return 0;
}
