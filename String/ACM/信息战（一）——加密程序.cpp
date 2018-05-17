#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=1015

bool isa(char x)
{
    if(x>='a'&&x<='z')
        return true ;
    else if(x>='A'&&x<='Z')
        return true;
    else
        return false;
}
char change(char x)
{
    if(x>='A'&&x<='Z')
        return x;
    else
        return (x+'A'-'a');
}
int change_y(int cnt,int y)
{
    //printf("cnt%d y%d\t",cnt,y);
    int tem_y=(cnt-1)/y +1;
   // printf("tem_x=%d\t",tem_x);
    return tem_y;
}
int change_x(int cnt,int y)
{
    int tem_x=cnt%y;
    if(tem_x==0)
        tem_x=y;
   // printf("tem_y=%d\n",tem_y);
    return tem_x;
}
int main()
{
   // freopen("test.txt","r",stdin);
    int x , y;
    scanf("%d%d",&x,&y);
    int cnt=0;
    char ma[x+5][y+5];
    char c;
    c=getchar();
    while(~scanf("%c",&c))
    {
        //printf("c===%c\n",c);
        if(c=='\n')
        {
            for(int i = cnt+1;i<=x*y;i++)
            {
                ma[change_x(i,y)][change_y(i,y)]=(char)(((int)('A'))+((i-cnt-1)%26));
            }
            for(int i = 1 ; i<= y;i++)
            {
                for(int j = 1 ;j<=x;j++)
                {
                    printf("%c",ma[j][i]);
                }
            }
            printf("\n");
            cnt=0;
        }
        //printf("c==%c\n",c);
        if(isa(c))
        {
            cnt++;
            ma[change_x(cnt,y)][change_y(cnt,y)]=change(c);
        }
        else
            continue;
    }
     for(int i = cnt+1;i<=x*y;i++)
            {
                ma[change_x(i,y)][change_y(i,y)]=(char)(((int)('A'))+((i-cnt-1)%26));
            }
            for(int i = 1 ; i<= y;i++)
            {
                for(int j = 1 ;j<=x;j++)
                {
                    printf("%c",ma[j][i]);
                }
            }
            printf("\n");
    return 0;
}
