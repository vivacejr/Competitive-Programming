#include<stdio.h>
int main()
{
	long long int n,k,q,t1,t2,q1,q2;
	long long int ary[200005]={0};

	scanf("%lld%lld%lld",&n,&k,&q);
	while(n--)
	{
		scanf("%lld%lld",&t1,&t2);
		ary[t1]++;
		ary[t2+1]--;
	}		
	long long int i;
	for(i=1;i<=200000;i++)
		ary[i]+=ary[i-1];
	long long int count=0;
	for(i=0;i<=200000;i++)
	{
		if(ary[i]>=k)
		{
			count++;
		}
		ary[i]=count;
	}
	while(q--)
	{
		scanf("%lld%lld",&q1,&q2);
		printf("%lld\n",ary[q2]-ary[q1-1]);
	}


/*	while(q--)
	{	
		long long int count=0;
		scanf("%lld%lld",&q1,&q2);
		for(i=q1;i<=q2;i++)
		{
			if(ary[i]>=k)
				count++;
		}
		printf("%lld\n",count);
	}*/
}
