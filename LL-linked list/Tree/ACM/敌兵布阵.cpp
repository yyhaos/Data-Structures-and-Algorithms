#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=5379
int main ()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int N,n,tem_n,tem2_n;
        int k[65536*2+5];
        scanf("%d",&n);
        n++;
        for(N=1;N<=n;N*=2)
        {

        }
        //printf("N=%d\n",N);
        memset(k,0,sizeof(k));
        for(tem_n=N+1;tem_n<N+n;tem_n++)
        {
            scanf("%d",&k[tem_n]);
        }
        while(tem_n--)
        {
            k[tem_n/2]+=k[tem_n];
        }
        char tem[50];
        printf("Case %d:\n",i);
        while(~scanf("%s",tem))
        {
            int tem_i;
            int tem_jj;
            if(tem[0]=='E')
                break;
            else scanf("%d%d",&tem_i,&tem_jj);
            if(tem[0]=='Q')
            {
                int tem_j=tem_jj;
                int ans =0;
                tem_i+=N-1;
                tem_j+=N+1;
                while((tem_i/2)!=(tem_j/2))
                {
                    int half_tem_i = tem_i/2;
                    int half_tem_j = tem_j/2;
                    if(tem_i==half_tem_i*2)
                        ans+=k[tem_i+1];
                    if(tem_j==1+half_tem_j*2)
                        ans+=k[tem_j-1];
                    tem_i=half_tem_i;
                    tem_j=half_tem_j;

                }
                printf("%d\n",ans);
            }
            else if(tem[0]=='S')
            {
                tem_i+=N;
                while(tem_i>0)
                {
                    k[tem_i]-=tem_jj;
                    tem_i=tem_i/2;
                }
            }
            else if(tem[0]=='A')
            {
                tem_i+=N;
                while(tem_i>0)
                {
                    k[tem_i]+=tem_jj;
                    tem_i=tem_i/2;
                }
            }
        }
    }
    return 0;
}
