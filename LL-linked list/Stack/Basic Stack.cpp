#include<bits/stdc++.h>
using namespace std;

int main ()
{
    stack <int>stk;
    int n,tem_v;
    char tem[10];
    char push[]="push",pop[]="pop";
    //freopen("test.txt","r",stdin);

    while(~scanf("%d",&n))
    {
        while(!stk.empty())
                stk.pop();
        while(n--)
        {
            scanf("\n");
            scanf("%s",tem);
            int flag=1;
            //printf("tem=%s\n",tem);
            if(tem[0]=='p' && tem[1]=='u')
            {
                scanf("%d",&tem_v);
              //  printf("%d",tem_v);
                stk.push(tem_v);
            }
            else if(tem[0]=='p')
            {
                if(stk.empty())
                {
                    printf("this is empty!\n");
                }
                else
                {
                    tem_v=stk.top();
                    stk.pop();
                    printf("%d\n",tem_v);
                }
            }
            else if(tem[0]=='q')
            {
               // flag=0;
                if(stk.empty())
                {
                    printf("this is empty!\n");
                   // flag=1;
                }
                while(!stk.empty())
                {
                   // flag=1;
                    tem_v=stk.top();
                    //printf("tem_v=%d\n",tem_v);
                    stk.pop();
                    printf("%d\n",tem_v);
                    //if(!stk.empty())
//printf("\n");
                }
                //printf("over\n");
            }
            /////if(flag==1 && tem[2]!='s')
            //    printf("\n");
        }
        printf("\n");
    }
    return 0;
}
