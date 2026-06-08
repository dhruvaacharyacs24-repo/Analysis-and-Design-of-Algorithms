#include<stdio.h>

int main()
{
    int n,i,j,u,v,min,s;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int a[20][20],d[20],vis[20]={0};

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);

            if(i!=j && a[i][j]==0)
                a[i][j]=999;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d",&s);

    for(i=0;i<n;i++)
        d[i]=a[s][i];

    d[s]=0;
    vis[s]=1;

    for(i=0;i<n-1;i++)
    {
        min=999;

        for(j=0;j<n;j++)
        {
            if(!vis[j] && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        }

        vis[u]=1;

        for(v=0;v<n;v++)
        {
            if(!vis[v] &&
               d[u]!=999 &&
               a[u][v]!=999 &&
               d[u]+a[u][v] < d[v])
            {
                d[v]=d[u]+a[u][v];
            }
        }
    }

    printf("Shortest distances:\n");

    for(i=0;i<n;i++)
        printf("%d -> %d = %d\n",s,i,d[i]);

    return 0;
}
