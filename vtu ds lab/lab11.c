#include<stdio.h>
#include<stdlib.h>
#define size 20
void bfs(int m[][size],int visited[],int src,int n);
int main()
{
    int n,m[size][size],visited[size],i,j,src;
    printf("enter no of cities\n");
    scanf("%d",&n);
    printf("enter coefficient of matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&m[i][j]);
    }
    printf("enter source\n");
    scanf("%d",&src);
    for(i=0;i<n;i++)

        visited[i]=0;
        bfs(m,visited,src,n);
         for(i=0;i<n;i++)
         {
            if(visited[i]==0)
                printf("%d is not reachable\n",i);
            else
                printf("%d is reachable\n",i);
    }
}
void bfs(int m[][size],int visited[],int src,int n)
{
    int q[size],r=0,f=0,u,v;
    visited[src]=1;
    q[r]=src;
    while(f<=r)
    {
        u=q[f++];
        for(v=0;v<n;v++)
        {
            if((m[u][v]==1)&& (visited[v]==0))
            {
                q[++r]=v;
                visited[v]=1;
            }
        }
    }

}
