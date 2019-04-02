#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
ll depth[100000];
vector<vector<pair<ll,ll> > > G(100000);
deque<ll> Q;


ll bfs()
{	
	while(!Q.empty())
	{
		ll a=Q.front();
		Q.pop_front();
		lp(i,0,G[a].size())
		{
			if(depth[G[a][i].first]>depth[a]+G[a][i].second)
			{
				depth[G[a][i].first]>depth[a]+G[a][i].second;	
				if(G[a][i].second) Q.push_back(G[a][i].first);
				else Q.push_front(G[a][i].first);
			}
		}
		
	}
}





int main()
{
	ll n,e;
	cin >> n>>e;
	lp(i,0,e)
	{
		ll a,b,wt;
		cin >> a>>b>>wt;
		G[a].pb(mp(b,wt));
		G[b].pb(mp(a,wt));
	}
	ll source;
	cin >> source;
	depth[source]=0;
	Q.push_back(source);

	lp(i,1,n+1) depth[i]=10000000000;
	
	bfs();
	
	lp(i,1,n+1)
	{
		cout<<depth[i]<<" ";
	}
	cout<<endl;
	return 0;
}