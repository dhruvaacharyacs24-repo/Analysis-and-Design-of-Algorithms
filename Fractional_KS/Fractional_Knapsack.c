#include<stdio.h>

int main()
{
    int n,i,j;
    float wt[20],p[20],r[20];
    float cap,tp=0,t;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter weights:\n");

    for(i=0;i<n;i++)
        scanf("%f",&wt[i]);

    printf("Enter profits:\n");

    for(i=0;i<n;i++)
        scanf("%f",&p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f",&cap);

    for(i=0;i<n;i++)
        r[i]=p[i]/wt[i];

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(r[i]<r[j])
            {
                t=r[i];
                r[i]=r[j];
                r[j]=t;

                t=wt[i];
                wt[i]=wt[j];
                wt[j]=t;

                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(wt[i]<=cap)
        {
            tp+=p[i];
            cap-=wt[i];
        }
        else
        {
            tp+=r[i]*cap;
            break;
        }
    }

    printf("Maximum Profit = %f",tp);
}
