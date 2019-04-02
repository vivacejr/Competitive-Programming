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
const ll N=300005;

vll G[N],tree[N];
ll vis[N],st[N],bridge[N],U[N],V[N],low[N];
ll compo=0,t=0;
queue<ll> Q[N];

ll adj(ll u,ll e)
{
	return U[e] == u ? V[e]:U[e];
}

ll dfs0(ll u,ll edge) //finding bridges
{
	vis[u]=1;
	low[u]=t;
	st[u]=t++;
	lp(i,0,G[u].size())
	{
		ll e=G[u][i];
		ll x=adj(u,e);
		if(!vis[x])
		{
			dfs0(x,e);
			low[u]=min(low[u],low[x]);
		}
		else if(e!=edge)
		{
			low[u]= min(low[u],st[x]);
		}
	}
	if(low[u]==st[u]&&edge!=-1)
	{
		bridge[edge]=1;
	}
	vis[u]=0;
}

ll dfs1(ll u)
{
	ll cur=compo;
	Q[cur].push(u);
	vis[u]=1;
	while(!Q[cur].empty())
	{
		ll u=Q[cur].front();
		Q[cur].pop();
		lp(i,0,G[u].size())
		{
			ll e=G[u][i];
			ll x=adj(u,e);
			if(vis[x]) continue;
			if(bridge[e])
			{
				compo++;
				tree[cur].pb(compo);
				tree[compo].pb(cur);
				dfs1(x);
			}
			else
			{
				Q[cur].push(x);
				vis[x]=1;
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,m;
	cin >> n >> m;

	lp(i,0,m)
	{
		ll a,b;
		cin >> a >> b;
		G[a].pb(i);
		G[b].pb(i);
		U[i]=a;
		V[i]=b;
	}	
	dfs0(1,-1);
	dfs1(1);


	return 0;
}