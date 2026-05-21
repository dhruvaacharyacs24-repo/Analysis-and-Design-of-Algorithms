/* 4. Quick Sort */

#include<stdio.h>
#include<time.h>

void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int i=l,j=r,p=a[l],t;

        while(i<j)
        {
            while(a[i]<=p && i<r)
                i++;

            while(a[j]>p)
                j--;

            if(i<j)
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }

        a[l]=a[j];
        a[j]=p;

        quicksort(a,l,j-1);
        quicksort(a,j+1,r);
    }
}

int main()
{
    int n,i,a[100000];
    clock_t s,e;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    s=clock();

    quicksort(a,0,n-1);

    e=clock();

    printf("Sorted elements:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime Taken = %lf seconds",
           (double)(e-s)/CLOCKS_PER_SEC);
}
