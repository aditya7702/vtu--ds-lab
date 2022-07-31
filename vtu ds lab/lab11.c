#include<stdio.h>
#include<stdlib.h>
#define s 20

void bfs(int m[][size],int v[],int src,int n)
{
    int q[s];
    int f=0,r=0,u,v;
    v[src]=1;
    q[r]=src
    while(f<=r)
    {
        u=q[f++];
        for(v=0;v<n;v++){
            if(m[u][v]==1 && v[v]=0)
            {
                q[++r]=v;
                v[v]=1;
            }
            }
    }
}
int main()
{
    int n,src,i,j;
    int m[s][s],v[s];
    printf("enter no of cities\n");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&m[i][j])
    printf("enter source\n");
    scanf("%d",&src);
    for(i=0;i<n;i++)
        v[i]=0;
    bfs(m,v,src,n);
    for(i=0;i<n;i++)
            if(v[i]==0)
                printf("%d is not reachable",i);
            else
                  printf("%d is  reachable",i);


}
