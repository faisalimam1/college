#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int a[10000],n,count;
void selection_sort()
{
  for(int i=0;i<n-1;i++)
  {
    int min = i;
    for(int j=i+1;j<n;j++)
    {
      count++;
      if(a[j]<a[min])
        min=j;
    }
    int temp=a[i];
    a[i]=a[min];
    a[min]=temp;
  }
}
int main()
{
  printf("Enter the number of elements in an array:");
  scanf("%d",&n);
  printf("All the elements:");
  srand(time(0));
  for(int i=0;i<n;i++)
  {
    a[i]=rand();
    printf("%d ",a[i]);
  }
  selection_sort();
  printf("\nAfter sorting\n");
  for(int i=0;i<n;i++)
    printf("%d ", a[i]);
  printf("\nNumber of basic operations = %d\n",count);
}

/*
Sample Input and Output:
Enter the number of elements in an array:5
All the elements:
24152 32742 28304 4804 22274
After sorting
4804 22274 24152 28304 32742
Number of basic operations = 10
*/
