#include<stdio.h>

long long int vec[100005];

int main()
{
	long long int n,a,k,t,sum=0,max=0;
	scanf("%lld%lld%lld",&n,&k,&t);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&vec[i]);
		sum+=vec[i];
		if(vec[i]>max)
		{
			max=vec[i];
		}

	}
	long long int lo,mid,hi;
	lo=max;
	hi=sum;
	long long int load=0;
	long long int w;
	long long int c=10;
	while(hi>lo)
	{
		mid=(lo + hi) / 2;
		//		cout << lo <<" " << hi << endl;
		w=1;
		load=0;
		for(int i=0;i<n;i++)
		{
			if(load + vec[i]<=mid)
			{
				load+=vec[i];
			}
			else
			{
				w++;
				load=vec[i];
			}
		}
		if(w<=k)
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;	
		}
	}
	printf("%lld\n",hi);
}
