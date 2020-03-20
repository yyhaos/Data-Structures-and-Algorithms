#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20020; const int MAXM = 100010; struct Edge {     int to,next; }edge[MAXM]; int head[MAXN],tot; void init() {     tot = 0;     memset(head,-1,sizeof(head)); }
void addedge(int u,int v)
{     edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
} bool vis[MAXN];//染色标记，为true表示选择
int S[MAXN],top;//栈
bool dfs(int u)
{     if(vis[u^1])return false;     if(vis[u])return true;     vis[u] = true;     S[top++] = u;     for(int i = head[u];i != -1;i = edge[i].next)         if(!dfs(edge[i].to))             return false;     return true;
} bool Twosat(int n)
{     memset(vis,false,sizeof(vis));     for(int i = 0;i < n;i += 2)
    {         if(vis[i] || vis[i^1])continue;         top = 0;         if(!dfs(i))         {             while(top)vis[S[--top]] = false;             if(!dfs(i^1)) return false;
        }     }     return true;
}
int off=30;
int main()
{
    #ifdef yyhaos
    freopen("in.txt","r",stdin);
    #endif // yyhaos
    int n,m;
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        off=n;
//        n*=4;
        if(n==0)break;
        init();
        for(int i=0;i<n;i++)
        {
            addedge(i*2,(i*2+off*2)^1);
            addedge((i*2+off*2)*2,(i*2)^1);
        }
        while(m--)
        {
            char a1,a2;
            scanf("%d%c %d%c",&u,&a1,&v,&a2);
            printf("---%d%c %d%c\n",u,a1,v,a2);
            u--;v--;
            if(a1==a2)
            {
                addedge(u*2,(v*2)^1);
                addedge(v*2,(u*2)^1);
                addedge((u+off)*2,(v*2+off*2)^1);
                addedge((v+off)*2,(u*2+off*2)^1);
            }
            else
            {
                addedge(u*2,((v+off)*2)^1);
                addedge(v*2,(u*2+off*2)^1);
                addedge((u+off)*2,(v*2)^1);
                addedge((v+off)*2,(u*2)^1);
            }
//            addedge(u,v^1);
//            addedge(v,u^1);

        }int fi=0;

        if(Twosat(4*n))
        {
            int ans=0;
            for(int i = 0;i < 4*n;i+=2)
            if(vis[i])
            {
                ans++;
            }
            if(ans>=n/2)
            {
                int tn=n;
                for(int i = 0;i < 4*n && tn>0;i+=2,tn--)
                if(vis[i])
                {
                    if(fi==1)
                    printf(" ");
                    fi=1;
                    if(i<2*n)
                        printf("%dh",i/2+1);
                    else
                        printf("%dw",(i)/2-n+1);
                }
            }
            else
            {
                ans=0;
                for(int i = 1;i < 4*n;i+=2)
            if(vis[i])
            {
                ans++;
            }
            if(ans>=n/2)
            {
                int tn=n;
                for(int i = 1;i < 4*n && tn>0;i+=2,tn--)
                if(vis[i])
                {
                    if(fi==1)
                    printf(" ");
                    fi=1;
                    if(i<2*n)
                        printf("%dh",i/2+1);
                    else
                        printf("%dw",(i)/2-n+1);
                }
            }
            }
            printf("\n");
        }
        else printf("bad luck\n");
    }
    return 0;
}
