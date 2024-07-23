
#include<stdio.h>
#include<math.h>
int i,j;
int place(int x[], int k) 
{
    int i;
    for (i = 1; i < k; i++) 
	{
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
            return 0;
    }
    return 1;
}

int nqueen(int n) 
{
    int x[10], count = 0, k=1;
    x[k] = 0;
    while (k != 0) 
	{
        x[k]++;
        while ((x[k] <= n) && (!place(x, k)))
            x[k]++;
        if (x[k] <= n) 
		{
            if (k == n) 
			{
                
                printf("\nSolution %d:\n", ++count);
                for (i = 1; i <= n; i++) 
				{
                    for (j = 1; j <= n; j++) 
					{
                        printf("%c ", (j == x[i]) ? 'Q' : 'X');
                	}
                    printf("\n");
             	   
                }
            } 
			else 
			{
                ++k;
                x[k] = 0;
            }
        } 
		else
            k--;
    }
    return count;
}

int main() {
    int n;
    printf("Enter the size of chessboard: ");
    scanf("%d", &n);
    printf("\nTotal number of solutions: %d\n", nqueen(n));
    return 0;
}
/*
Enter the size of chessboard: 4
Solution 1
X Q X X
X X X Q
Q X X X
X X Q X
Solution 2
X X Q X
Q X X X
X X X Q
X Q X X
Total no of solutions: 2
*/
