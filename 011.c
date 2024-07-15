#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void mergesort(int a[100],int low,int high);
void display(int a[100],int n);
int main()
{
 int i,low,high,n;
 int a[100],j,k;
 double time_required;
 clock_t begin,end;

 printf("\nEnter the number of elements :");
 scanf("%d",&n);

 for(i=0;i<n;i++)
    a[i]=rand()%1000;
 low=0;
 high=n-1;
  printf("\nBefore Sorting\n");
for(i=0;i<n;i++)
	printf("%d\t",a[i]);
 begin=clock();
 for(j=0;j<700;j++)
 for(k=0;k<700;k++)
 mergesort(a,low,high);
 end=clock();
 display(a,n);
 time_required=((double)(end-begin))/1000;
 printf("\nThe time required is: %f",time_required);

 return 0;
}
void mergesort(int a[10],int low,int high)
{
 int mid;
 void combine(int a[10],int low,int mid,int high);
 if(low<high)
 {
  mid=(low+high)/2;
  mergesort(a,low,mid);
  mergesort(a,mid+1,high);
  combine(a,low,mid,high);
 }
}
void combine(int a[10],int low,int mid,int high)
{
 int i,j,k;
 int temp[10];
 k=low;
 i=low;
 j=mid+1;
 while(i<=mid && j<=high)
 {
  if(a[i]<=a[j])
  {
   temp[k]=a[i];
   i++;
   k++;
  }
  else
  {
   temp[k]=a[j];
   j++;
   k++;
  }
 }
 while(i<=mid)
 {
  temp[k]=a[i];
  i++;
  k++;
 }
 while(j<=high)
 {
  temp[k]=a[j];
  j++;
  k++;
 }
 for(k=low;k<=high;k++)
 a[k]=temp[k];
}
void display(int a[10],int n)
{
 int i;
 printf("\n\nThe sorted list is...\n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}

