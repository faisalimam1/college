#include<stdio.h>

int indegree[10], cost[10][10], n,i,j;

void calculate() 
{
    for (i = 0;i < n;i++) 
    {
        indegree[i] = 0;
        for (j = 0;j < n;j++)
            indegree[i] += cost[j][i];
    }
}

void souceremoval() 
{
    int removed[10] = { 0 };
    printf("Topological order=\n");
    for (i= 0;i < n; i++) 
    {
        calculate();
        for (j = 0;j < n;j++) 
        {
            if (removed[j] == 0 && indegree[j] == 0)
                break;
        }
        if (i == n) 
        {
            printf("Graph is cyclic\n");
            return;
        }
        printf("%d ", i);
        removed[i] = 1;
        for (int k = 0;k < n;k++)
            cost[i][k] = 0;
    }
}

int main() 
{
    
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the adj/cost matrix\n");
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++)
            scanf("%d", &cost[i][j]);
    }
    souceremoval();
  return 0;
}
