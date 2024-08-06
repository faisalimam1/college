//floyds
//prg 3a

#include<stdio.h>
int i,j,k;
int min(int a, int b) 
{
    return a < b ? a : b;
}

void floyds(int d[][10], int n) 
{
    for ( k = 0; k < n; k++) 
    {
        for ( i = 0; i < n; i++) 
        {
            for ( j = 0; j < n; j++) 
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() 
{
    int n, d[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for ( i = 0; i < n; i++) 
    {
        for ( j = 0; j < n; j++)
            scanf("%d", &d[i][j]);
    }
    floyds(d, n);
    printf("all pair shortest path\n");
     for ( i = 0; i < n; i++) 
    {
        for ( j = 0; j < n; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
    
}
/*
Enter the number of vertices: 4
Enter the cost matrix
999 8 4 999
999 999 1 999
4 999 999 999
999 2 9 999
all pair shortest path
8 8 4 999
5 13 1 999
4 12 8 999
7 2 3 999
