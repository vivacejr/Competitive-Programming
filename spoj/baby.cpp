#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll dp[17][1<<17];
ll n;
ll in[17];
ll final[17];
ll ans;

ll init()
{
	lp(i,0,n+1)
	{
		lp(j,0,(1<<(n+1)))
		{
			dp[i][j]=-1;
		}
	}
	ans=10000000000;
}

ll solve(ll i,ll mask)
{
	// cout<<i<<" "<<sum<<" "<<mask<<endl;	
	if(i==n)
	{
		return 0;
	}
	else if(dp[i][mask]==-1)
	{
		dp[i][mask]=10000000000;
		lp(j,0,n)
		{
			if((mask&(1<<j))==0)
			{
				dp[i][mask]=min(dp[i][mask],abs(j-i)+abs(final[j]-in[i])+solve(i+1,mask|(1<<j)  ));
			}
		}
	}
	return dp[i][mask];
}


int main()
{
	while(1)
	{
		cin >> n;
		if(n==0) break;
		
		lp(i,0,n)
		{
			cin >> in[i];
		}
		lp(i,0,n)
		{
			cin >> final[i];
		}
		init();
		cout<<solve(0,0)<<endl;
	}
	return 0;
}