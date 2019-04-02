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

const ll N=100005;
const ll LOGN=20,INF=1e15;
set<ll> G[N];	
multiset<ll> A[N];
ll dp[N][LOGN],depth[N],sub[N],par[N],ans[N];

ll cnt=0;
ll dfs0(ll a,ll par)
{
	// cout<<a<<endl;
	for(auto it=G[a].begin();it!=G[a].end();it++)
	{
		if(cnt<10)
		{
			cnt++;
		}
		if(*it!=par)
		{
			dp[*it][0]=a;
			depth[*it]=depth[a]+1;
			dfs0(*it,a);
		}
	}
}

int jump(int x, int d){
	for(ll i = LOGN-1 ; i>=0 ; i--){
		if( (1<<i) <= d ){
			x = dp[x][i];
			d -= (1<<i);
		}
	}
	return x;
}

int LCA(int a, int b){
	if( depth[a] > depth[b] )	a = jump(a, depth[a]-depth[b]);
	if( depth[b] > depth[a] )	b = jump(b, depth[b]-depth[a]);

	if( a == b )	return a;
	for(int i = LOGN-1 ; i>=0 ; i--){
		if( dp[a][i] != dp[b][i] ){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

ll dist(ll u,ll v)
{
	return depth[u]+depth[v]-2*depth[LCA(u,v)];
}
	
ll nn=0;

void dfs1(ll u,ll p)
{	
	sub[u]=1;
	nn++;
	for(auto it=G[u].begin();it!=G[u].end();it++)
	{
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
	}
}

ll dfs2(ll u,ll p)
{
	for(auto it=G[u].begin();it!=G[u].end();it++)
	{
		if(*it!=p&&sub[*it]>nn/2)
		{
			return dfs2(*it,u);
		}
	}
	return u;
}

void decompose(ll root,ll p)
{
	nn=0;
	dfs1(root,root);
	ll cd=dfs2(root,root);
	if(p==-1) p=cd;
	par[cd]=p;
	for(auto it=G[cd].begin();it!=G[cd].end();it++)
	{
		if(*it!=cd)
		{
			G[*it].erase(cd);
			decompose(*it,cd);
		}
	}
	G[cd].clear();
}

ll update1(ll u)
{
	ll x=u;
	while(1)
	{
		A[x].insert(dist(x,u));
		ans[x]=min(ans[x],dist(x,u));
		if(x==par[x]) break;
		x=par[x];
	}
}
ll update2(ll u)
{
	ll x=u;
	while(1)
	{
		A[x].erase(A[x].lower_bound(dist(x,u)));
		if(A[x].size()!=0)
		{
			ans[x]=*A[x].begin();
		}
		else
		{
			ans[x]=INF;
		}
		if(x==par[x]) break;
		x=par[x];
	}
}

ll  query(ll u)
{
	ll x=u,ret=INF;

	while(1)
	{
		ret=min(ret,dist(u,x)+ans[x]);
		if(x==par[x]) break;
		x=par[x];
	}
	if(ret==INF) ret=-1;	
	cout<<ret<<endl;
}



int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
	ll n,m;
	cin >> n;

	lp(i,0,n-1)
	{
		ll a,b;
		cin >>a >> b;
		G[a].insert(b);
		G[b].insert(a);
	}	
	dp[1][0]=1;
	dfs0(1,1);
	lp(j,1,LOGN)
	{
		lp(i,1,n+1)
		{
			if(depth[i]-(1<<j)>=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
			else dp[i][j]=1;		
		}
	}
	decompose(1,-1);
	lp(i,0,n+1)
	{
		ans[i]=INF;
	}
	ll col[N];
	cin >> m;
	lp(i,0,n+1) col[i]=0;	
	while(m--)
	{
		ll t,v;
		cin >> t >> v;
		// cerr<<1<<endl;
		if(t==0)
		{
			if(col[v]==0)	update1(v);
			else update2(v);
			col[v]=1-col[v];
		}
		else
		{
			query(v);
		}
	}
	return 0;
}