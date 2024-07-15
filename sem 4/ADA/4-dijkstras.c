
//Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted connected graph to other vertices using Dijkstra's algorithm.

#include<stdio.h>

int cost[10][10],n,dist[10];
int minm(int m, int n)
{
	return((m<n)? m: n); 
}
void dijkstra(int source)
{
	int s[10] = {0} ;
	int min, w = 0 ;
	for(int i=0;i<n;i++)
		dist[i]=cost[source][i]; 
	dist[source] = 0; 
	s[source] = 1; 
	for(int i=0; i<n-1; i++) 
	{
		min = 999; 
		for(int j = 0; j<n; j++) 
		{ 
			if((s[j] == 0) && (min>dist[j])) 
			{
				min = dist[j]; 
				w = j;
			} 
		}
		s[w] = 1 ;
		for(int v=0;v<n;v++) 
		{ 
			if(s[v]==0 && cost[w][v]!= 999 )
			{ 
				dist[v]= minm(dist[v],dist[w]+cost[w][v]);

			}
		}
	}
}
int main() 
{
	int source;
	printf("Enter the no.of vertices:"); 
	scanf("%d",&n);
	printf("Enter the cost matrix\n"); 
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	}
	printf("Enter the source vertex:"); 
	scanf("%d", &source);
	dijkstra(source);
	printf("the shortest distance is...\n"); 
	for(int i=0; i<n; i++)
		printf("Cost from %d to %d is %d\n",source,i,dist[i]);

}

/* 

Enter the no. of vertices:5

Enter the cost matrix

0 3 1 999 999

3 0 7 5 1

1 7 0 2 999

999 5 2 0 7

999 1 999 7 0

Enter the source vertex:0

the shortest distance is... 
Cost from 0 to 0 is O

Cost from 0 to 1 is 3

Cost from 0 to 2 is 1

Cost from 0 to 3 is 3

Cost from 0 to 4 is 4
*/
