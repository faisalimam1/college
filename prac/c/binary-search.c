#include <stdio.h>
#include <string.h>
int main()
{
    int i,n,a[10],key, found=0,mid,low,high;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for (i=0;i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter key element\n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high && found!=1)
    {
        mid= (low+high)/2;
        if(a[mid]==key)
        {
            found=1;
            break;
        }
        else if (a[mid]<key)
        {
            low= mid+1;
        }
        else
            high=mid-1;
        
    }
    if (found==1)
    {
        printf("Number found at position %d ", mid+1);
    }
    else 
        printf("Number not found");

    return 0;
}
