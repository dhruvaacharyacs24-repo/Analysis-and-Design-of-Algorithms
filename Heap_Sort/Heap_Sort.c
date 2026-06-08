#include<stdio.h>
#include<time.h>

void heapify(int a[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int max=i,t;

    if(l<n && a[l]>a[max])
        max=l;

    if(r<n && a[r]>a[max])
        max=r;

    if(max!=i)
    {
        t=a[i];
        a[i]=a[max];
        a[max]=t;

        heapify(a,n,max);
    }
}

int main()
{
    int n,i,t,a[100000];
    clock_t s,e;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    s=clock();

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;

        heapify(a,i,0);
    }

    e=clock();

    printf("Sorted elements:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime Taken = %lf seconds",
           (double)(e-s)/CLOCKS_PER_SEC);
}
