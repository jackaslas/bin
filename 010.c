#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int a[],int low,int high);
int partition(int a[],int low,int high);
int main()
{
	int n,a[60000],low,high,i;
	double total;
	clock_t start,end;
	printf("Enter the size of an array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	a[i]=rand()%1000;
	printf("\nArray before sorting\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	low=0;
	high=n-1;
	start=clock();
	quicksort(a,low,high);
	end=clock();
	printf("\nArray after sorting\n");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nThe total time taken is =%f\n",total);
}
void quicksort(int a[],int low,int high)
{
	int s;
	if(low<high)
	{
		s=partition(a,low,high);
		quicksort(a,low,s-1);
		quicksort(a,s+1,high);	
	}
}
int partition(int a[],int low,int high)
{
	int pivot,temp,i,j;
	pivot=a[low];
	i=low+1;
	j=high;
	while(i<=j)
	{
		while(pivot>=a[i]&&i<=high)
	        i++;
	    while(pivot<a[j])
	        j--;
	    if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
