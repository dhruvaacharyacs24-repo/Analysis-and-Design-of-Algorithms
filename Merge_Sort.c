#include<stdio.h>
#include<time.h>

void merge(int a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0,b[100000];

    while(i<=m && j<=r)
        b[k++]=(a[i]<a[j])?a[i++]:a[j++];

    while(i<=m)
        b[k++]=a[i++];

    while(j<=r)
        b[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=b[k];
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;

        mergesort(a,l,m);
        mergesort(a,m+1,r);

        merge(a,l,m,r);
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

    mergesort(a,0,n-1);

    e=clock();

    printf("Sorted elements:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime Taken = %lf seconds",
           (double)(e-s)/CLOCKS_PER_SEC);
}
