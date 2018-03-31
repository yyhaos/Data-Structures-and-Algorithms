#include<bits/stdc++.h>
using namespace std;

//Problem   : https://acm.bnu.edu.cn/v3/problem_show.php?pid=42977
bool islfpa(char a)
{
    if(a=='('||a=='{'||a=='[')
        return true;
    else
        return false;
}
bool isripa(char a)
{
    if(a==')'||a=='}'||a==']')
        return true;
    else
        return false;
}
bool isok(char rig,char lft)
{
    if(lft=='(')
    {
        if(rig==')')
            return true;
        else
            return false;
    }
    else if(lft=='[')
    {
        if(rig==']')
            return true;
        else
            return false;
    }
    else if(rig=='}')
        return true;
    else return false;
}
int main ()
{
    stack <char>str;
    char tem;
    int flag=1;
    freopen("test.txt","r",stdin);
    //printf("%d-%d %d-%d %d-%d",'(',')','[',']','{','}');
    while(~scanf("%c",&tem))
    {
        if(tem=='\n')
        {
            while(!str.empty())
            {
                str.pop();
            }
            if(flag==1)
                printf("yes\n");
            else
                printf("no\n");
            flag=1;
        }
        else if(flag==0)
            continue;
        else if(isripa(tem))
        {
            char tem_2;
            flag=0;
            while(!str.empty())
            {
                tem_2=str.top();
                str.pop();
                if(islfpa(tem_2))
                {
                    if(isok(tem,tem_2))
                        flag=1;
                    else
                    {
                        flag=0;
                    }
                    break;
                }
            }
        }
        else
            str.push(tem);
    }
    return 0;
}
