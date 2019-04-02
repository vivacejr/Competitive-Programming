#include<stdio.h>
int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,ans,ryt;
		scanf("%lld",&n);
		//ans=(n*(n+1)*(2*n+10))/12-n  ;//left ulte here
		ryt=(n*(n+2)*(2*n+1)/8);
		printf("%lld\n",ryt);
	}
}
