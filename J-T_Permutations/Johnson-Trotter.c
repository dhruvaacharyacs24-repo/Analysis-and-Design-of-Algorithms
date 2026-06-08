#include<stdio.h>

int main()
{
    int n,i,j,m,p,t;

    printf("Enter value of n: ");
    scanf("%d",&n);

    int a[n],d[n];

    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        d[i]=-1;
    }

    printf("Permutations:\n");

    while(1)
    {
        for(i=0;i<n;i++)
            printf("%d ",a[i]);

        printf("\n");

        m=-1;

        for(i=0;i<n;i++)
        {
            if(d[a[i]-1]==-1 && i>0 && a[i]>a[i-1] && a[i]>m)
                m=a[i];

            if(d[a[i]-1]==1 && i<n-1 && a[i]>a[i+1] && a[i]>m)
                m=a[i];
        }

        if(m==-1)
            break;

        for(i=0;i<n;i++)
            if(a[i]==m)
                p=i;

        j=p+d[m-1];

        t=a[p];
        a[p]=a[j];
        a[j]=t;

        for(i=m;i<n;i++)
            d[i]=-d[i];
    }
}
