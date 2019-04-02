#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
vector<vector<ll> > G(100000);
ll parent[100000];
bool vis[100000];
ll dp[10000][100];
ll depth[10000];
ll LOGN=20;
ll init(ll n)
{
	lp(i,0,n+1)
	{
		depth[i]=0;
		parent[i]=0;	
		vis[i]=0;
		G[i].clear();
		lp(j,0,LOGN)
		{
			dp[i][j]=0;
		}
	}	
}
int dfs(ll a)
{
	vis[a]=1;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i]])
		{	
			depth[G[a][i]]=depth[a]+1;
			parent[G[a][i]]=a;
			dfs(G[a][i]);
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


int main()
{
	ll n;
	cin >> n ;
	
	init(n);
	ll R[n];
	lp(i,0,n) 
	{
		ll k;
		cin >> k;
		lp(j,0,k)
		{
			ll child;
			cin >> child;
			child--;
			G[i].pb(child);
			G[child].pb(i);
		}
	}
	ll root=1;
	depth[root]=0;
	dfs(root);

	

	lp(i,1,n+1) dp[i][0]=parent[i];
	
	lp(j,1,LOGN)
	{
		lp(i,1,n+1)
		{
			if(depth[i]-(1<<j)>=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
			else dp[i][j]=1;
		}
	}
	
	ll q;
	cin >> q;

	while(q--)
	{		
		ll a,b;
		cin >> a>> b;
		a--;
		b--;
		cout<<LCA(a,b)<<endl;
	}

	return 0;
}