#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
ll inf=10000000000;
bool vis[10000];
vector<vector <int> > G(10000);
stack<ll> S;

int dfs(ll a)
{
	vis[a]=1;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i]])
		{
			dfs(G[a][i]);
		}
	}
	S.push(a);

}

int main()
{
	ll n;
	cin >> n;
	ll e;
	cin >> e;
	for (int i = 0; i < e; ++i)
	{
		ll a,b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}

	ll kithon;
	cin >> kithon;
	
	ll stak[n+1];
	ll pos[n+1];
	ll k=1;
	ll dist[n+1];
	while(!S.empty())
	{
		stak[k]=S.top();
		pos[stak[k]]=k;
		S.pop();
		dist[k]=inf;
		k++;
	}
	dist[kithon]=0;

	lp(i,pos[kithon],n+1)
	{
		lp(j,0,G[stak[i]].size())
		{
			dist[G[stak[i]][j]]=min(dist[stak[i]]+1,dist[G[stak[i]][j]]);
		}		
	}
	lp(i,1,n+1)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	return 0;
}