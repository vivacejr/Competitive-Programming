#include<stdio.h>
long long int sum=0;

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
			sum=sum+n1-i;
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
	long long int p,t;
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		printf("\n");
		scanf("%lld",&p);
		long long int ary[p];
		long long int i;
		for(i=0;i<p;i++)
		{
			scanf("%lld",&ary[i]);
		}
		//merge
		mrgsrt(ary,0,p-1);
		printf("%lld\n",sum);
	}
}



