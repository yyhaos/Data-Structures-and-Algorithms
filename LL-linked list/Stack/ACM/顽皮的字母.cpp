#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://www.bnuoj.com/v3/problem_show.php?pid=44586
bool islover(char a, char b)
{
    //printf("%c==%c\n",a,b);
    int aa=a-'a'+1,bb=b-'a'+1;
//printf("%d==%d\n",aa,bb);
    if(aa>bb)
    {
        int tem=aa;
        aa=bb;
        bb=tem;
    }
    //printf("%d==%d\n",aa,bb);
    if(bb-aa!=1)
        return false;
    else if(aa%2==0)
        return false;
    else
        return true;
}
int main ()
{
    bool islover(char a, char b);
    stack <char> ch,ch2;
    int t,cnt;
    char tems[100050],fro,tem;
    scanf("%d",&t);
    scanf("\n");
    while(t--)
    {
        cnt=1;
        scanf("%s",tems);
        for(int i = 0;tems[i];i++)  //NB
        {
            tem=tems[i];
            if(ch.empty())
                ch.push(tem);
            else
            {
                fro=ch.top();
                if(islover(fro,tem))
                {
                    ch.pop();
                }
                else
                {
                    ch.push(tem);
                }
            }
        }
        while(!ch.empty())
        {
            ch2.push(ch.top());
            //printf("%c",ch.top());
            ch.pop();
            cnt=0;
        }
        while(!ch2.empty())
        {
            //ch2.push(ch.top());
            printf("%c",ch2.top());
            ch2.pop();
        }
        if(cnt)
            printf("sad!");
        if(t)
            printf("\n");
    }
    return 0;
}
