#include<stdio.h>
#include<stdlib.h>
int main()
{
int weight[20],profit[20],v[20][20];
int n,i,j,m,val1,val2;
printf("Enter the number of object\n");
scanf("%d",&n);
printf("Enter the weight of each object\n");
for(i=1;i<=n;i++)
{
scanf("%d",&weight[i]);
}
printf("Enter the profit for each object\n");
for(i=1;i<=n;i++)
{
scanf("%d",&profit[i]);
}
printf("Enter the knapsack capacity\n");
scanf("%d",&m);
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
if(i==0||j==0)
v[i][j]=0;
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(weight[i]>j)
v[i][j]=v[i-1][j];
else
{
val1=(v[i-1][j]);
val2=(v[i-1][j-weight[i]]+profit[i]);
if(val1>val2)
v[i][j]=val1;
else
v[i][j]=val2;
}
}
}
printf("The resultant matrix is\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
printf("%d\t",v[i][j]);
}
printf("\n");
}
printf("the max profit is %d\n",v[n][m]);
}
