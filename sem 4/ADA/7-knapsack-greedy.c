//knapsack using greedy approx
#include<stdio.h>
#include<stdlib.h>

void greedy(int n, int m, float p[], float w[]) 
{
    float profit = 0, max;
    int i, k, count;
    for (count = 0; count < n; count++) 
	{
        max = 0;
        for (i = 0; i < n; i++) 
		{
            if (((p[i] / w[i]) > max)) 
			{
                k = i;
                max = p[i] / w[i];
            }
        }
        if (w[k] <= m) 
		{
            printf("item %d with profit %f is selected\n", (k+1), p[k]);
            profit += p[k];
            m -= w[k];
            p[k] = 0;
        } 
		else
            break;
    }
    printf("Discrete knapsack profit= %f\n", profit);
    profit= profit + (m/w[k])*p[k];
    printf("Continuos knapsack profit= %f", profit);
}

void main() 
{
    int n, m,i;
	float p[1000],w[1000];
    printf("Enter the no. of items: ");
    scanf("%d", &n);
    
    printf("Enter the total capacity: ");
    scanf("%d", &m);

    printf("Enter the profit of %d items: ", n);
    for (int i = 0;i < n;i++)
        scanf("%f", &p[i]);

    printf("Enter the weight of %d items: ", n);
    for (int i = 0;i < n;i++)
        scanf("%f", &w[i]);

    greedy(n, m, p, w);
}

/*
Enter the no. of items: 5
Enter the total capacity: 100
Enter the profit of 5 items: 20 30 60 40 60
Enter the weight of 5 items: 10 20 30 40 50
item 1 with profit 20.000000 is selected
item 3 with profit 60.000000 is selected
item 2 with profit 30.000000 is selected
Discrete knapsack profit= 110.000000
Continuos knapsack profit= 158.000000
*/
