//source removal
//prg 5

#include<stdio.h>

int indegree[10], cost[10][10], n;
void calc_ind() 
{
    for (int i = 0;i < n;i++) 
    {
        indegree[i] = 0;
        for (int j = 0;j < n;j++)
            indegree[i] += cost[j][i];
    }
}

void souceremoval() 
{
    int removed[10] = { 0 }, i,j;
    printf("Topological order\n");
    for (i= 0;i< n;i++)
    {
         calc_ind();
         for (j= 0;j < n;j++) 
        {
            if (removed[j] == 0 && indegree[j] == 0)
                 break;
        }
        if (j==n) 
        {
            printf("Graph is cyclic\n");
            return;
        }
        printf("%d\t", j);
        removed[j] = 1;
        for (int k = 0;k < n;k++)
            cost[j][k] = 0;
    }
}

void main() 
{
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the adj matrix\n");
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++)
            scanf("%d", &cost[i][j]);
    }
    souceremoval();
}
/*
Enter the no. of vertices: 4
Enter the adj matrix
0 1 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Topological order
2       Graph is cyclic
*/

/*
Enter the no. of vertices: 5
Enter the adj matrix
0 1 1 0 0
0 0 0 1 1
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
Topological order
0       1       2       3       4
*/
