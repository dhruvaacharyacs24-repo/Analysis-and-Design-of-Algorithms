#include<stdio.h>

int a[20][20],in[20],n;

void topo()
{
    int i,j,k;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            in[j]+=a[i][j];

    printf("Topological Order: ");

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                printf("%d ",i);
                in[i]=-1;

                for(j=0;j<n;j++)
                    if(a[i][j])
                        in[j]--;

                break;
            }
        }
    }
}

int main()
{
    int i,j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    topo();
}
