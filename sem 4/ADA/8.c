
#include<stdio.h>

int x[10], w[10], count=0, d,i,j;

void sumofsubsets(int s, int k, int r) 
{
    x[k] = 1;
    if (s + w[k] == d) 
	{
        printf("\nSubset %d:\n", ++count);
        for (i = 0; i <= k; i++) 
		{
            if (x[i] == 1)
                printf("%d\t", w[i]);
        }
    } 
	else if (s + w[k] + w[k + 1] <= d)
        sumofsubsets(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d)) 
	{
        x[k] = 0;
        sumofsubsets(s, k + 1, r - w[k]);
    }
}

int main() {
    int sum = 0,n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &w[i]);
        sum = sum+w[i];
    }
    
    printf("Enter the sum: ");
    scanf("%d", &d);
    if((sum<d)||(w[0]>d))
    	printf("No subset possible\n");
    else
    	sumofsubsets(0,0,sum);
    
    return 0;
}
