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


vector<vll> G(N);
bool vis[N];
ll low[N],st[N],child[N],par[N];
ll AR[N];
vector<pll> ans;
ll t=0;
ll dfs(ll a)
{	
	vis[a]=1; 
	low[a]=t;
	st[a]=t++;
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(!vis[x])
		{
			child[a]++;
			par[x]=a;
			dfs(x);
			low[a]=min(low[a],low[x]);
			if(low[x]>st[a]) ans.pb(mp(a,x));
		}
		if(par[a]!=x)
			low[a]=min(low[a],low[x]);
	}	
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
	ll n,m;
	cin >> n>>m;

	lp(i,0,m)
	{
		ll a,b;
		cin >> a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}	    
	dfs(1);
	return 0;
}