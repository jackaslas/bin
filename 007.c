#include<stdio.h>
int main()
{
float weight[50],profit[50],ratio[50],temp,m,x[50],mp=0;
int n,i,j,rc;
printf("Enter the number of objects:\n");
scanf("%d",&n);
printf("Enter the weights of each object:\n");
for (i=1;i<=n;i++)
{
scanf("%f",&weight[i]);
}
printf("Enter the profits of each object:\n");
for(i=1;i<=n;i++)
{
scanf("%f",&profit[i]);
}
printf("Enter the capacity of knapsack:\n");
scanf("%f",&m);
for(i=1;i<=n;i++)
{
ratio[i]=profit[i]/weight[i];
}
for(i=1;i<=n;i++)
{
for(j=i+1;j<=n;j++)
{
if(ratio[i] < ratio[j])
{
temp = ratio[j];
ratio[j] = ratio[i];
ratio[i] = temp;
temp = weight[j];
weight[j] = weight[i];
weight[i] = temp;
temp = profit[j];
profit[j] = profit[i];
profit[i] = temp;
}
}
}
rc=m;
for(i=1;i<=n;i++)
{
x[i]=0;
}
for(i=1;i<=n;i++)
{
if(weight[i]>rc)
break;
else
{
x[i]=1;
mp= mp+profit[i]*x[i];
rc= rc-weight[i];
}
}
printf("The maximum profit for discreate knapsack is:%f\n",mp);
if(i<=n)
x[i]=rc/weight[i];
mp=mp+(x[i]*profit[i]);
printf("The resultant vector is:");
for(i=1;i<=n;i++)
{
printf("%f\n",x[i]);
}
printf("The maximum profit for continuous knapsack is:%f\n",mp);
return 0;
}
