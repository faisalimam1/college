
//prg 1

#include<stdio.h>   
int cost[10][10],n;
void kruskal() 
{
    int par[n]; 
	int a=0,b=0,u=0,v=0, i, j, min, mincost = 0, ne = 0;

    for (i = 0; i < n; i++)
        par[i] = -1;
	printf("The min spanning tree edges are\n");
    while (ne < n-1) 
	{
        min = 999;
        for (i = 0; i < n; i++)
		{
            for (j = 0; j < n; j++)
			{
                if (cost[i][j] < min) 
				{
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
			}
		}
        while (par[u]!= -1)
            u = par[u];
        while (par[v]!= -1)
            v = par[v];

        if (u != v) 
		{
            printf("from vertex %d to vertex %d and the cost=%d\n", a, b, min);
            mincost += min;
            par[v] = u;
            ne++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("cost of MST = %d\n", mincost);
}

int main() 
{
	int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    kruskal();
    return 0;
}
/*
Enter the number of vertices: 4
Enter the cost matrix:
999 2 3 1
2 999 4 999
3 4 999 5
1 999 5 999
The min spanning tree edges are
from vertex 0 to vertex 3 and the cost=1
from vertex 0 to vertex 1 and the cost=2
from vertex 0 to vertex 2 and the cost=3
cost of MST = 6
*/
