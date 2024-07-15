#include<stdio.h>
int cost[10][10],n;
void prim()
{
	int vt[10]={0},i,j;
	int a=0,b=0,min,mincost=0,ne=0;
	vt[0]=1;
	while(ne<n-1)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			if(vt[i]==1)
				for(j=0;j<n;j++)
					if(cost[i][j]<min&&vt[j]==0)
					{
						min=cost[i][j];
						a=i;
						b=j;
					}
		}
		printf("edge from vertex %d to veryed %d and cost is %d\n",a,b,min);
		vt[b]=1;
		ne++;
		mincost+=min;
		cost[a][b]=cost[b][a]=999;
		
	}
	printf("minimun cost of spanning tree is %d\n",mincost);
}
int main()
{
	int i,j;
	printf("enter the no of vertices ");
	scanf("%d",&n);
	printf("enter the cost matrx\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		
			scanf("%d",&cost[i][j]);
		
	}
	prim();
}
/*
enter the no of vertices 5
enter the cost matrx
999 5 999 6 999
5 999 1 3 999
999 1 999 4 6
6 3 4 999 2
999 999 6 2 999
edge from vertex 0 to veryed 1 and cost is 5
edge from vertex 1 to veryed 2 and cost is 1
edge from vertex 1 to veryed 3 and cost is 3
edge from vertex 3 to veryed 4 and cost is 2
minimun cost of spanning tree is 11
*/
