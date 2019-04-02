#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

int main()
{
	int n,l,i,k,j,min,temp;
	while(scanf("%d",&n))
	{
		int A[101]; //matrix n cross m hogi ...agli m cross kuch hogi so..M[0] = n M[1]=m aise ;
		int M[101][101];
		int S[101][101];
		int presum[101];
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			if(!i)
			presum[i]=presum[i-1]+A[i];
			else 
			presum[i]=A[i];
		}

		lp(i,0,n)
		{
			M[i][i]=A[i];
			lp(j,0,n)
			{
				if(!i)
				S[i][j]=(presum[j]-presum[i-1])%100;
				else
				S[i][j]=presum[j]%100;
			}	
		}

		for(l=2;l<n+1;l++)
		{
			
			for(ll i=0;i<n-l+1;i++)
			{
				j=i+l-1;
				min=1000000;
				for(k=i;k<j;k++)
				{
					temp=M[i][k]+M[k+1][j]+A[i-1]*A[k]*A[j];+S[i][k]*S[k+1][j];
					if (temp<min)
					{
						min=temp;
					}
				}
				M[i][j]=min;
			}
		}
		for(ll i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d",M[i][j]);
			}
			printf("\n");
		}	
	}					
}
