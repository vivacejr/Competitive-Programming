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

vector<vector<ll> > G(N);
vector<vector<ll> > G2(N);

const ll LOGN =20,inf=1e15;
ll dp[N][LOGN],depth[N],ans[N];


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

ll dfs(ll a,ll par)
{
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=par)
		{
			dp[x][0]=a;
			depth[x]=depth[a]+1;
			dfs(x,a);
		}
	}
}

ll update(ll u)
{
	ll x=u;
	while(1)
	{
		ans[x]=min(ans[x],dist(x,u));
		// cout<<x<<" "<<u<<" "<<dist(x,u)<<endl;
		if(x==1) break;
		x/=2;
	}
}

ll  query(ll u)
{
	ll x=u,ret=inf;

	while(1)
	{
		ret=min(ret,dist(u,x)+ans[x]);
		if(x==1) break;
		x/=2;
	}
	cout<<ret<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
    ll n,m,a,b;
    cin >> n >> m;
    lp(i,0,n-1)
    {
    	cin >>a >> b;
    	G[a].pb(b);
    	G[b].pb(a);
    }
    dp[1][0]=1;
    dfs(1,1);
    lp(j,1,LOGN)
	{
		lp(i,1,n+1)
		{
			if(depth[i]-(1<<j)>=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
			else dp[i][j]=1;		
		}
	}
	lp(i,0,N) ans[i]=inf;
	update(1);
	while(m--)
	{
		ll t,v;
		cin >> t >> v;
		if(t==1)
		{
			update(v);
		}
		else
		{
			query(v);
		}
	}


	return 0;
}