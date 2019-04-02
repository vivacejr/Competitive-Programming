#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll dp[21][2000000];
vector<vector<ll> > V(21);
ll ary[21][21];
ll n;

ll init()
{
	ll x=pow(2,n+1);
	lp(i,0,n)
	{
		V[i].clear();
		lp(j,0,x)
		{
			dp[i][j]=-1;
		}
	}
}

ll solve(ll i,ll mask)
{
	if(i==n)
	{
		if(mask==(1<<n)-1) return 1;
		else return 0;
	}
	if(dp[i][mask]==-1)
	{
		dp[i][mask]=0;
		lp(j,0,V[i].size())
		{
			if(!((1<<V[i][j])&mask))
			{
				dp[i][mask]+=solve(i+1,mask|(1<<V[i][j]));
			}
		}
	}
	return dp[i][mask];
}

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		
		cin >> n;
		init();
		lp(i,0,n)
		{
			lp(j,0,n)
			{
				scanf("%lld",&ary[i][j]);
			}
		}
		lp(j,0,n)
		{
			lp(i,0,n)
			{
				if(ary[i][j])
				{
					V[j].pb(i);
				}
			}
		}
		cout<<solve(0,0)<<endl;
	}
	return 0;
}