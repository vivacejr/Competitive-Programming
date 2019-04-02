#include<stdio.h>

int merge(long long int ary[],long long int l,long long int m,long long int n)
{
	//temp arrays
	long long int n1 = m-l+1;
	long long int n2 = n-m;
	long long int L[n1];
	long long int R[n2];
	//filling em	
	long long int i,j,k;
	for(i=0;i<n1;i++)
	{
		L[i]=ary[l+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=ary[m+j+1];
	}
	i=0;
	j=0;
	k=l;
	//sorting the array
	while( i<n1 && j<n2 )
	{
		if( L[i] < R[j] )
		{
			ary[k] = L[i];
			i++;
		}
		else
		{
			ary[k] = R[j];
			j++;
		}
		k++;
	}
	//filling the leftovers
	while(i<n1)
	{
		ary[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		ary[k]=R[j];
		j++;
		k++;
	}

}	

int mrgsrt(long long int ary[],long long int l,long long int n)
{
	long long int m;
	if(n>l)
	{
		m = (n + l)/2 ;
		//breaking
		mrgsrt(ary,l,m);
		mrgsrt(ary,m+1,n);
		//merging and sorting
		merge(ary,l,m,n);	
	}

}

int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,k,temp=10000000000;
		scanf("%lld%lld",&n,&k);
		long long int ary[n];
		long long int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&ary[i]);
		}
		//merge
		mrgsrt(ary,0,n-1);
		//sorted now
		for(i=n-1;i>=0+k-1;i--)
		{
			if((ary[i]-ary[i-k+1]) < temp)
			{
				temp=ary[i]-ary[i-k+1] ;
			}
		}
		printf("%lld\n",temp);
	}

}


