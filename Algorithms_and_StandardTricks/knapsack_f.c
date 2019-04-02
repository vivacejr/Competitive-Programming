#include<stdio.h>

int max(int a,int b)
{
	return ( a>b ? a : b );
}

int knapsack(int n,int m,int W[],int V[],int A[][8])
{
	if(A[n][m] != -1)
	{	
		return (A[n][m]) ;
	}
	else	
	{
		if(n==0 || m==0)
		{
			return 0;
		}
		else if(m>=W[n-1] )
		{	

			A[n][m]=max(knapsack(n-1,m,W,V,A),V[n-1]+knapsack(n-1,m-W[n-1],W,V,A));
			return(A[n][m]);
		}
		else
		{
			A[n][m]=knapsack(n-1,m,W,V,A);
			return(A[n][m]);
		}
	}

}

int main()
{
	int ans;
	int i,j;
	int W[4]={1,3,4,5};	//array containing weights
	int V[4]={1,4,5,7};	//array with their respective values
	int A[5][8];		//memorize krne wala array  max values ko
	for(i=0;i<5;i++)
	{
		for(j=0;j<8;j++)
		{
			A[i][j]=-1;
		}
	}
	ans=knapsack(4,7,W,V,A);	
	printf("%d\n",ans);
	for(i=0;i<5;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d,%d=%d ",i,j,A[i][j]);
		}
		printf("\n");

	}
}
