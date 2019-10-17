#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18,mod=1e9+7;
vll G[N];
ll val[N],levH[N],lev[N];
ll dfs(ll a,ll p)
{
	levH[a]=1;
	val[a]=1;
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=p)
		{
			dfs(x,a);
			lev[a]=max(lev[a],lev[x]+1);
		}
	}
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=p)
			val[a]=(val[a]*(levH[lev[a]]+val[x]))%mod;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin >>n ;
	srand(time(NULL));
	lp(i,0,n-1)
	{
		ll a,b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}	  
	lp(i,0,n+1)
	{
		levH[i]=rand()%(1000000000);
	}
	dfs(1,0);
	cout<<val[1]<<endl;  
	return 0;
}