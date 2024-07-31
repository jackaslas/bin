#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[60000],c[60000];
void merge(int low,int mid,int high)
{
int i,j,k;
k=low;
i=low;
j=mid+1;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
i=i+1;
k=k+1;
}
else
{
c[k]=a[j];
j=j+1;
k=k+1;
}
}
while(i<=mid)
c[k++]=a[i++];
while(j<=high)
c[k++]=a[j++];
for(i=low;i<=k-1;i++)
a[i]=c[i];
}
void merge_sort(int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
merge_sort(low,mid);
merge_sort(mid+1,high);
merge(low,mid,high);
}
}
int main()
{
int n,i;
double total;
clock_t start,end;
printf("\nEnter the size of an array\n");
scanf("%d",&n);
for(i=0;i<n;i++)
a[i]=rand()%1000;
printf("\n Array before sorting\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
start=clock();
merge_sort(0,n-1);
end=clock();
printf("\n Array after sorting\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
total=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nThe total time taken is %f\n",total);
}
