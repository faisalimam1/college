 #include<stdio.h>
 int n,m,p[10],w[10];
 
 int max(int a,int b)
 {
	return (a>b?a:b);
 }
 void ksdp()
 {
 	int v[11][11],i,j;
 	for(i=0;i<=n;i++)
 	{
 	
 		for(j=0;j<=m;j++)
 		{
		 
 			if(i==0||j==0)
 				v[i][j]=0;
 			else if(j<w[i])
 				v[i][j]=v[i-1][j];
 			else
 				v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
 		}
    }
 	for(i=0;i<=n;i++)
 	{
 		for(j=0;j<=m;j++)
 			printf("%d ",v[i][j]);
 		printf("\n");
	}
	printf("Items included are : ");
	while(n>0)
	{
		if(v[n][m]!=v[n-1][m])
		{
			printf("%d ",n);
			m=m-w[n];
		}
		n--;
	}
	
 }
 int main()
 {
 	int i;
 	printf("Enter the no of items : ");
 	scanf("%d",&n);
 	printf("Enter the weight of n items : ");
 	for(i=1;i<=n;i++)
 		scanf("%d",&w[i]);
 	printf("Enter the prices of n items : ");
 	for(i=1;i<=n;i++)
 		scanf("%d",&p[i]);
 	printf("Enter the capacity of knapsack : ");
 	scanf("%d",&m);
 	ksdp();
 }
/*
Enter the no. of items: 4
Enter the weights of n items: 7 3 4 5
Enter the prices of n items: 42 12 40 25
Enter the capacity of Knapsack: 10
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 42 42 42 0
0 0 0 12 12 12 12 42 42 42 0
0 0 0 12 40 40 40 52 52 52 0
0 0 0 12 40 40 40 52 52 65 65
Items included are: 4 3
*/
