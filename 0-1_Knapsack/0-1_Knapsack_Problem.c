#include<stdio.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int n,w,i,j;

    printf("Enter number of items: ");
    scanf("%d",&n);

    int wt[n],p[n];

    printf("Enter weights:\n");

    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);

    printf("Enter profits:\n");

    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d",&w);

    int k[n+1][w+1];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                k[i][j]=0;

            else if(wt[i-1]<=j)
                k[i][j]=max(
                    p[i-1]+k[i-1][j-wt[i-1]],
                    k[i-1][j]
                );

            else
                k[i][j]=k[i-1][j];
        }
    }

    printf("Maximum Profit = %d",k[n][w]);
}
