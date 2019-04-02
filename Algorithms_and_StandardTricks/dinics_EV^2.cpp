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
const ll N=1e4+5,inf=1e10;
struct edge
{
	int a,b;
	ll c,f ;
	edge(int u,int v,ll cap):a(u),b(v),c(cap),f(0){}
} ;
struct flows
{
	const static ll inf = 1e18 ;
	int level[N], Dptr[N], s, t ;
	queue<int> Q; vector<edge> E,E2; vll ad[N] ;
	void add(int a,int b,int c)
	{
		if(a==b)return ;
		ad[a].pb(E.size()),E.pb(edge(a,b,c)) ;
		ad[b].pb(E.size()),E.pb(edge(b,a,0)) ;
	}

	bool bfs(void)
	{
		memset(level,0,sizeof(level));
		Q.push(s);
		level[s]=1;
		while(!Q.empty())
		{
			int sz=Q.size(),v ;
			while(sz--)
			{
				v = Q.front();Q.pop() ;
				for(auto &e:ad[v]) 
				{
					if(!level[E[e].b]&&E[e].f<E[e].c)
					{
						level[E[e].b]=level[v]+1;
						Q.push(E[e].b);
					}
				}
			}
		}
		return level[t]>0 ;
	}
	ll dfs(int x,ll flow)
	{
		if(!flow) return 0;
		if(x==t) return flow ;
		for(int &pt=Dptr[x];pt<ad[x].size();++pt)
		{
			int e=ad[x][pt];
			if(level[E[e].b]==level[x]+1)
			{
				if(ll pushed=dfs(E[e].b,min(flow,E[e].c-E[e].f)))
				{
					E[e].f+=pushed ;
					E[e^1].f -= pushed;
					return pushed ;
				}
			}
		}
		return 0 ;
	}

	ll dinic(void)
	{
		ll flow=0 ;
		while(bfs())
		{
			memset(Dptr,0,sizeof(Dptr));
			while(ll pushed=dfs(s,inf)) flow+=pushed;	
		}
		return flow ;
	}
	void reset(void)
	{
		for(auto &e:E)e.f=0;
	}
} ;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,m;
	cin >> n >> m;
	flows F;
	lp(i,0,m)
	{
		ll a,b,w;
		cin >> a >> b >> w;
		F.add(a,b,w);
	}	
	cin >> F.s>> F.t;
	cout<<F.dinic()<<endl;

	return 0;
}