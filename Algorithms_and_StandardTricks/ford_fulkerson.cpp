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

const ll inf=1e10,N=1005;

ll flow[N][N],cap[N][N],p[N],timer,ans,vis[N];
vll G[N];

bool bfs(ll st,ll end)
{
	queue<ll> q;
	q.push(st);
	while(!q.empty())
	{
		ll a=q.front();
		// cout<<a<<"xxx	";
		q.pop();
		if(a==end)
		{
			return true;
		}
		lp(i,0,G[a].size())
		{
			ll u=G[a][i];
			if( vis[u]!=timer && cap[a][u] > flow[a][u] )
			{
				p[u] = a;
				vis[u]=timer;
				q.push(u);
			}
		}
	}
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,m;
	cin >> n>> m;

	lp(i,0,m)
	{
		ll a,b,w;
		cin >> a >> b >> w;
		G[a].pb(b);
		G[b].pb(a);
		cap[a][b]=w;
	}

	ll st,end;
	cin >> st >> end;

	ll x=inf;
	timer++;
	while(bfs(st,end))
	{
		cout<<endl;
		timer++;
		ll mn=inf;
		ll i=end;
		while(i!=st)
		{
			cout<<i<<" ";
			mn=min(mn,cap[p[i]][i]-flow[p[i]][i]);
			i=p[i];
		}
		cout<<endl;
		i=end;
		while(i!=st)
		{
			flow[p[i]][i]+=mn;
			flow[i][p[i]]-=mn;
			i=p[i];
		}
		cout<<mn<<endl;
		ans+=mn;
		memset(p,0,sizeof p);
	}
	cout<<ans<<endl;

	return 0;
}