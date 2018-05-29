#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("matrix.txt","r",stdin);
    int N;
    while(cin>>N)
    {
        if(N==0)
            continue;
        int mt[N+5][N+5];
        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = 1 ; j <= N ; j++)
            {
                cin>>mt[i][j];
                //cout<<mt[i][j]<<' ';
            }
            //cout<<'\n';
        }
        int W[N+5][N+5][N+5];
        for(int i = 1 ; i<=N; i++)
            for(int j = 1 ; j <= N ; j++)
                W[0][i][j]=mt[i][j];
        for(int k = 1 ; k<=N; k++)
        {
            for(int i = 1 ; i<=N; i++)
                for(int j = 1 ; j <= N ; j++)
                    W[k][i][j]=(W[k-1][i][k]+W[k-1][k][j]==2)?1:W[k-1][i][j];
            /*
            //lao version
            for(int i = 1 ; i<=N; i++)
                for(int j = 1 ; j <= N ; j++)
                    W[k][i][j]=W[k-1][i][j];
            int tem[2][N];
            memset(tem,0,sizeof(tem));
            for(int i = 1 ;i<=N;i++)
            {
                if(W[k-1][i][k]==1)
                    tem[0][i]=1;
                if(W[k-1][k][i]==1)
                    tem[1][i]=1;
            }
            for(int i = 1 ;i<=N;i++)
                for(int j = 1 ;j<=N;j++)
                    if(tem[0][i]+tem[1][j]==2)
                        W[k][i][j]=1;
            */
        }

        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = 1 ; j <= N ; j++)
            {
                cout<<W[N][i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
