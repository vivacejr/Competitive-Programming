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
	ll n,l,i,k,j;
	ll min,temp;
	while(cin >> n)
	{
		ll A[101]; //matrix n cross m hogi ...agli m cross kuch hogi so..M[0] = n M[1]=m aise ;
		ll M[101][101];
		ll S[101][101];
		ll presum[101];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);
			if(i!=0)
			{
				presum[i]=(presum[i-1]+A[i])%100;
			}
			else 
			presum[i]=A[i];
		}

		lp(i,0,n)
		{
			M[i][i]=0;
			lp(j,i,n)
			{
				if(i)
				{
						S[i][j]=(presum[j]-presum[i-1]+100)%100;
				}
				else
					S[i][j]=presum[j]%100;
			}	
		}

		for(l=2;l<n+1;l++)
		{
			for(ll i=0;i<n-l+1;i++)
			{
				j=i+l-1;
				min=10000000000;
				for(k=i;k<j;k++)
				{
					temp=M[i][k]+M[k+1][j]+S[i][k]*S[k+1][j];
					if (temp<min)
					{
						min=temp;
					}
				}
				M[i][j]=min;
			}
		}
		cout<<M[0][n-1]<<endl;
	}					
}
