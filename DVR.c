#include<stdio.h>
#define MAX 10
#define INF 9999
int main()
{
    int n, i, j, k;
    int cost[MAX][MAX];
    int dist[MAX][MAX];
    printf("Enter no.of nodes:");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("\n shortest distance matrix:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
} 