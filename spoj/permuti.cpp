#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll dp[15][100];
ll n,k;

ll init()
{
	lp(i,0,n+1)
	{
		lp(j,0,k+1)
		{
			// cout<<i<<" "<<j<<endl;
			dp[i][j]=-1;
		}
	}
}

ll solve(ll i,ll cnt)
{
	if(i==n+1)
	{
		if(cnt==k)
		{
			return 1;
		}
		else return 0;
	}
	if(dp[i][cnt]==-1)
	{
		dp[i][cnt]=0;
		lp(j,0,i)
		{
			if(j+cnt>k)
			{
				break;
			}
			dp[i][cnt]+=solve(i+1,j+cnt);
		}
	}
	return dp[i][cnt];
}


int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		init();
		cout<<solve(1,0)<<endl;
	}

	return 0;
}