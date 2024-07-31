#include<stdio.h>
int min(int a,int b)
{
if(a<b)
return a;
else
return b;
}
void floyd(int dist[10][10],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
}
}
}
int main()
{
int dist[10][10],n,i,j;
printf("\nEnter the number of vertices:\n");
scanf("%d",&n);
printf("\nEnter the cost adjaceny matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&dist[i][j]);
}
}
floyd(dist,n);
printf("\nAll Pair Shortest path matrix is:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d\t",dist[i][j]);
}
printf("\n");
}
}
