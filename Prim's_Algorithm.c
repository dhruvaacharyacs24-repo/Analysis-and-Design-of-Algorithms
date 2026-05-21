#include<stdio.h>

int main()
{
    int n,i,j,min,u,v;
    int edges=0,cost=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int a[20][20],vis[20]={0};

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    vis[0]=1;

    printf("Edges in MST:\n");

    while(edges<n-1)
    {
        min=999;

        for(i=0;i<n;i++)
        {
            if(vis[i])
            {
                for(j=0;j<n;j++)
                {
                    if(!vis[j] && a[i][j]<min)
                    {
                        min=a[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n",u,v,min);

        vis[v]=1;
        cost+=min;
        edges++;
    }

    printf("Minimum Cost = %d",cost);
}
