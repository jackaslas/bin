#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, visited[20],min,ne=1,mincost=0, cost[20][20],a,b,u,v,i,j;
    printf("Enter the number of vertices \n");
    scanf("%d",&n);
    printf("\n Enter the cost adjacent matrix \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
             cost[i][j]=999;
        }
    }
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
     visited[1]=1; 
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==0)
                        continue;
                    else
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n %d Edge (%d,%d)=%d\n",ne,a,b,min);
            ne++;
            mincost=mincost+min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\n Minimum cost is =%d\n", mincost);
}
