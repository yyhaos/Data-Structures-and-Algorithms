#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://acm.bnu.edu.cn/v3/problem_show.php?pid=5932
int main ()
{
    int N,n,m,tem_n,tem2_n;
    int k[400000*2+5];
    while(~scanf("%d%d",&n,&m))
    {
        for(N=1;N<=n+1;N*=2)
        {
        }
        //printf("N=%d\n",N);
        memset(k,0,sizeof(k));
        for(tem_n=N+1;tem_n<N+n+1;tem_n++)
        {
            scanf("%d",&k[tem_n]);
        }
        while(tem_n--)
        {
            int half_tem_n=tem_n/2;
            k[half_tem_n]=max(k[half_tem_n*2],k[half_tem_n*2+1]);
        }
        char tem[50];
        while(m--)
        {
            scanf("%s",tem);
            int tem_i;
            int tem_j;
            scanf("%d%d",&tem_i,&tem_j);
            if(tem[0]=='Q')
            {
                int ans =0;
                tem_i+=N-1;
                tem_j+=N+1;
                while((tem_i/2)!=(tem_j/2))
                {
                    int half_tem_i = tem_i/2;
                    int half_tem_j = tem_j/2;
                    if(tem_i==half_tem_i*2)
                        ans=max(ans,k[tem_i+1]);
                    if(tem_j==1+half_tem_j*2)
                        ans=max(ans,k[tem_j-1]);
                    tem_i=half_tem_i;
                    tem_j=half_tem_j;

                }
                printf("%d\n",ans);
            }
            else if(tem[0]=='U')
            {
                tem_i+=N;
                k[tem_i]=tem_j;
                tem_i=tem_i/2;
                while(tem_i>0)
                {
                    k[tem_i]=max(k[tem_i*2],k[2*tem_i+1]);
                    tem_i=tem_i/2;
                }
            }
        }
    }
    return 0;
}

