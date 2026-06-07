#include<stdio.h>
#define INF 999

int main() {
    int n, i, j, u, min;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int cost[n][n], dist[n], visited[n];

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(i=0;i<n;i++) {
        dist[i]=cost[0][i];
        visited[i]=0;
    }

    visited[0]=1;

    for(i=1;i<n;i++) {
        min=INF;
        for(j=0;j<n;j++)
            if(!visited[j] && dist[j]<min) {
                min=dist[j];
                u=j;
            }

        visited[u]=1;

        for(j=0;j<n;j++)
            if(!visited[j] && dist[u]+cost[u][j]<dist[j])
                dist[j]=dist[u]+cost[u][j];
    }

    printf("Shortest distances:\n");
    for(i=0;i<n;i++)
        printf("%d ", dist[i]);

    return 0;
}