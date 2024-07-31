#include<stdio.h>
void warshall(int p[10][10],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if((p[i][j]==0) && (p[i][k]==1) && (p[k][j]==1))
{
p[i][j]=1;
}
}
}
}
}
int main()
{
int p[10][10],i,j,n;
printf("Enter the number of vertices:\n");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&p[i][j]);
}
}
warshall(p,n);
printf("\nThe path matrix is:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d\t",p[i][j]);
}
printf("\n");
}
}
