#include<stdio.h>
#define INF 99999
int main()
{
    int n,i,j,u,v,min,cost=0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int g[n][n],vis[n],key[n],par[n];
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    for(i=0;i<n;i++){
        vis[i]=0; key[i]=INF; par[i]=-1;
    }
    key[0]=0;
    for(i=0;i<n-1;i++){
        min=INF; u=-1;
        for(j=0;j<n;j++)
            if(!vis[j] && key[j]<min){ min=key[j]; u=j; }
        vis[u]=1;
        for(v=0;v<n;v++)
            if(g[u][v] && !vis[v] && g[u][v]<key[v]){
                key[v]=g[u][v]; par[v]=u;
            }
    }
    printf("MST Edges:\n");
    for(i=1;i<n;i++){
        printf("%d - %d : %d\n",par[i],i,g[par[i]][i]);
        cost+=g[par[i]][i];
    }
    printf("Total Cost = %d\n",cost);
}
