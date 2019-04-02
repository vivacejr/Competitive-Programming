/*spoj LCA*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair

vector<vector<pair<ll,ll> > > G(100005);
ll parent[100005];
bool vis[100005];
ll dp[100005][22];
ll bda[100005][22];
ll	chota[100005][22];
ll depth[100005];
ll LOGNMAX=22;
ll inf=1000000000000;
ll ans1=inf;
ll ans2=-1;

ll init(ll n)
{
	lp(i,0,n)
	{
		depth[i]=0;
		parent[i]=0;	
		vis[i]=0;
		G[i].clear();
		lp(j,0,LOGNMAX)
		{
			dp[i][j]=-1;
			bda[i][j]=-1;
			chota[i][j]=inf;
		}
	}	
}
int dfs(ll a)
{
	vis[a]=1;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i].first])
		{	
			depth[G[a][i].first]=depth[a]+1;
			bda[G[a][i].first][0]=G[a][i].second;
			chota[G[a][i].first][0]=G[a][i].second;
			// cout<<a<<" "<<G[a][i].first<<" "<<G[a][i].second;
			parent[G[a][i].first]=a;
			dfs(G[a][i].first);
		}
	}
}
int jump(int x, int d){
	for(ll i = LOGNMAX-1 ; i>=0 ; i--){
		if( (1<<i) <= d ){
			ans1=min(ans1,chota[x][i]);
			ans2=max(ans2,bda[x][i]);
			x = dp[x][i];
			d -= (1<<i);
		}
	}
	return x;
}

int LCA(int a, int b){
	if( depth[a] > depth[b] )	a = jump(a, depth[a]-depth[b]);
	if( depth[b] > depth[a] )	b = jump(b, depth[b]-depth[a]);

	if( a == b )	
	{

		return a;
	}
	for(int i = LOGNMAX-1 ; i>=0 ; i--){
		if( dp[a][i] != dp[b][i] ){
			ans1=min(ans1,min(chota[a][i],chota[b][i]));
			ans2=max(ans2,max(bda[a][i],bda[b][i]));
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	ans1=min(ans1,min(chota[a][0],chota[b][0]));
	ans2=max(ans2,max(bda[a][0],bda[b][0]));
	return dp[a][0];
}


int main()
{
	ll n;
	cin >> n ;
	init(n);
	lp(i,0,n-1)
	{
		ll a,b,c;
		cin >> a>>b>>c;
		a--,b--;
		G[a].pb(mp(b,c));
		G[b].pb(mp(a,c));
	}

	depth[0]=0;
	dfs(0);

	

	lp(i,0,n) 
	{
		dp[i][0]=parent[i];
	}
	lp(j,1,LOGNMAX)
	{
		lp(i,0,n)
		{
			if(dp[i][j-1]!=-1	)
			{	
				dp[i][j]=dp[dp[i][j-1]][j-1];
				bda[i][j]=max(bda[i][j-1],bda[dp[i][j-1]][j-1]);
				chota[i][j]=min(chota[i][j-1],chota[dp[i][j-1]][j-1]);
			}
		}
	}
	ll q;
	cin >> q;
	// lp(i,0,n)
	// {
	// 	lp(j,0,5)
	// 	{
	// 		cout<<bda[i][j]<<"||"<<chota[i][j]<<"  ";
	// 	}
	// 	cout<<endl;
	// }
	while(q--)
	{
		ll a,b;
		cin  >> a >>b;
		a--;
		b--;
		ans1=inf;
		ans2=-1;
		ll asli=LCA(a,b);
		cout<<ans1<<" ";
		cout<<ans2<<endl;

	}

return 0;
}