#include<stdio.h>
#include<stdlib.h>

int x[20],n;

int place(int k,int i)
{
    int j;

    for(j=1;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    }

    return 1;
}

void queen(int k)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;

            if(k==n)
            {
                for(j=1;j<=n;j++)
                    printf("%d ",x[j]);

                printf("\n");
            }
            else
                queen(k+1);
        }
    }
}

int main()
{
    printf("Enter value of N: ");
    scanf("%d",&n);

    printf("Solutions:\n");

    queen(1);
}
