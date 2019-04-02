#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
ll hrz[501][501];
ll ver[501][501];
ll dp[501][501];
ll prehrz[501][501];
ll prever[501][501];
ll n, m;

ll func(ll i,ll j)
{
	if(i<0||j<0)
	{
		return 0;
	}
	if(dp[i][j]==-1)
	{
		dp[i][j]=max(func(i-1,j)+prehrz[i][j],func(i,j-1)+prever[i][j]);
	}
	return dp[i][j];
}

int main()
{
	while(1)
	{
		cin >> n >> m;
		if(n==0&&m==0) break;

		lp(i,0,n)
		{
			lp(j,0,m)
			{
				cin >> hrz[i][j];
			}
		}

		lp(i,0,n)
		{
			lp(j,0,m)
			{
				cin >> ver[i][j];
			}
		}
		lp(i,0,n)
		{
			ll sum=0;
			lp(j,0,m)
			{
				sum+=hrz[i][j];
				prehrz[i][j]=sum;
			}
		}

		lp(i,0,m)
		{
			ll sum=0;
			lp(j,0,n)
			{
				sum+=ver[j][i];
				prever[j][i]=sum;
			}
		}

		lp(i,0,n+1)
		{
			lp(j,0,m+1)
			{
					dp[i][j]=-1;
			}
		}
		cout << func(n-1,m-1)<<endl;
			
	}
}