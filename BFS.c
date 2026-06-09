#include<stdio.h>
int main() {
    int n, graph[10][10], visited[10]={0}, queue[10], front=0,rear=0;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    queue[rear++]=0;
    visited[0]=1;
    printf("Broadcast tree:\n");
    while(front < rear)
    {
        int node = queue[front++];
        for(int i=0;i<n;i++)
        {
            if(graph[node][i] && !visited[i]) 
            {
                printf("%d -> %d\n", node, i);
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
    return 0;
}