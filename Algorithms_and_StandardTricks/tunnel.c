#include<stdio.h>

int min(int a,int b)
{
	return (a <= b ? a :  b ) ;
}

int tunnel(int a,int n,int S1[],int S2[],int A[],int S[][100])
{
	if(n==0)
	{
		if(a==0)
		{
			S[a][n]=S1[0];
			return(S1[0]);

		}
		else 
		{
			S[a][n]=S2[0];
			return(S2[0]);

		}
	}	
	else if(a==1)
	{
		S[a][n]=min(tunnel(0,n-1,S1,S2,A,S)+A[n-1]+S2[n],tunnel(1,n-1,S1,S2,A,S) +S2[n]) ;
	}
	else
	{
		S[a][n]=min(tunnel(1,n-1,S1,S2,A,S)+A[n-1]+S1[n],tunnel(0,n-1,S1,S2,A,S) +S1[n]) ;
	}
	return (S[a][n]);

}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int S1[n];
	int S2[n];
	int A[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&S1[i]);
	}					
	for(i=0;i<n;i++)
	{
		scanf("%d",&S2[i]);
	}		
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&A[i]);
	}		
	int S[2][100]={0};

	int ans=tunnel(0,n-1,S1,S2,A,S);
	printf("%d\n",ans);

	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",S[i][j]);
		}
		printf("\n");
	}
}
