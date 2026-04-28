#include<stdio.h>

int main() {
    int n, cost[10][10];

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    printf("Routing Table:\n");

    for(int i=0;i<n;i++) {
        printf("Node %d:\n", i);
        for(int j=0;j<n;j++) {
            printf("To %d cost %d\n", j, cost[i][j]);
        }
    }
    return 0;
}