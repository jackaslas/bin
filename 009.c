#include<stdio.h> 
#include<time.h> 
#include<stdlib.h> 
void selectionsort(int a[],int n); 
int main() 
{ 
int n,a[60000],i; 
double total; 
clock_t start,end; 
printf("\nEnter the size of an array\n"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
a[i]=rand()%1000+1; 
printf("\n Array before sorting\n"); 
for(i=0;i<n;i++) 
printf("%d\t",a[i]); 
start=clock(); 
selectionsort(a,n); 
end=clock(); 
printf("\n Array after sorting\n"); 
for(i=0;i<n;i++) 
printf("%d\t",a[i]); 
total=(double)(end-start)/CLOCKS_PER_SEC; 
printf("\nThe total time taken is %f\n",total); 
} 
void selectionsort(int a[],int n) 
{ 
int i,j,temp,min; 
for(i=0;i<n-1;i++) 
{ 
min=i; 
for(j=i+1;j<n;j++) 
{ 
if(a[j]<a[min]) 
{ 
min=j; 
} 
} 
temp=a[min]; 
a[min]=a[i]; 
a[i]=temp; 
} 
}