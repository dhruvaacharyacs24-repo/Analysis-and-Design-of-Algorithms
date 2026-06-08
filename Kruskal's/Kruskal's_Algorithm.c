#include<stdio.h>

int parent[20];

int find(int x)
{
    while(parent[x])
        x=parent[x];

    return x;
}

int main()
{
    int n,i,j,min,u,v,a,b;
    int edges=0,cost=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int g[20][20];

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);

            if(i==j || g[i][j]==0)
                g[i][j]=999;
        }
    }

    printf("Edges in MST:\n");

    while(edges<n-1)
    {
        min=999;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]<min)
                {
                    min=g[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);

        if(u!=v)
        {
            parent[v]=u;

            printf("%d -> %d = %d\n",a,b,min);

            cost+=min;
            edges++;
        }

        g[a][b]=g[b][a]=999;
    }

    printf("Minimum Cost = %d",cost);

    return 0;
}
