#include<stdio.h>
long long int c[100000000];
int main()
{
	int t,n,count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		while(n>=5)
		{
			count += n/5;
			n /= 5;
		}
		printf("%d\n",count);
	}
	return 0;
}
