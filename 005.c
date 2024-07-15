#include<stdio.h> 
#include<stdlib.h> 
void indegree(int a[20][20],int n,int indeg[]) 
{ 
    int i,j,sum; 
    for(j=1;j<=n;j++) 
    { 
        sum=0; 
        for(i=1;i<=n;i++) 
        { 
            sum=a[i][j]+sum; 
        } 
        indeg[j]=sum; 
    } 
} 
void sort(int a[20][20],int n,int indeg[]) 
{ 
    int s[20],top=-1,t[10],i,u,v,k=1; 
    for(i=1;i<=n;i++) 
    { 
        if(indeg[i]==0) 
        { 
            top=top+1; 
            s[top]=i; 
        } 
    } 
    while(top!=-1) 
    { 
        u=s[top]; 
        top=top-1; 
        t[k]=u; 
        k=k+1; 
        for(v=1;v<=n;v++) 
        { 
            if(a[u][v]==1) 
            { 
                indeg[v]--; 
                if(indeg[v]==0) 
                { 
                    top=top+1; 
                    s[top]=v; 
                } 
            } 
        } 
    } 
    printf("Topological sequence is\n"); 
    for(k=1;k<=n;k++) 
    printf("%d\t",t[k]); 
} 
int main() 
{ 
    int n,i,j,a[20][20],indeg[20]; 
    printf("Enter the number of vertices\n"); 
    scanf("%d",&n); 
    printf("Enter the adjacency matrix\n"); 
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        { 
            scanf("%d",&a[i][j]); 
        } 
    } 
    indegree(a,n,indeg); 
    sort(a,n,indeg); 
} 