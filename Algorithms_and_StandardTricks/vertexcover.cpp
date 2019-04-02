#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll>
#define pll pair<ll,ll> 
const ll N=1e5+5;
ll dp[N][2];
vll G[N];
ll solve(ll a,ll par,ll flag)
{
	if(dp[a][flag]!=-1)
	{	
		return dp[a][flag];
	}
	ll sum=0;
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=par)
		{
			sum+=max(solve(x,a,1),solve(x,a,0));
		}
	}
	ll sum1;
	if(flag==1)
	{
		sum1=1;
		lp(i,0,G[a].size())
		{
			ll x=G[a][i];
			if(x!=par)
			{
				sum1+=solve(x,a,0);
			}
		}
	}
	else sum1=sum;
	dp[a][flag]=max(sum,sum1);
	return dp[a][flag];
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n;
	cin >> n;
	lp(i,0,n-1)
	{
		ll a,b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	memset(dp,-1,sizeof dp);
	cout <<max(solve(1,1,1),solve(1,1,0))<<endl;
	return 0;
}