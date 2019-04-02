//QTREE spoj

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
const ll LOGNMAX =20;

vector<vector<pll> > G(N);
vector<vll> ind(N);
ll vis[N],SC[N],Cid[N],head[N],Cpos[N],Csiz[N],base[N],pbase[N];
ll SCcost[N],tree[4*N],otherend[N];
ll cur=0,pos=0,n;
ll dp[N][20],depth[N],parent[N];

int jump(int x, int d){
	for(ll i = LOGNMAX-1 ; i>=0 ; i--){
		if( (1<<i) <= d ){
			x = dp[x][i];
			d -= (1<<i);
		}
	}
	return x;
}

int lca(int a, int b){
	if( depth[a] > depth[b] )	a = jump(a, depth[a]-depth[b]);
	if( depth[b] > depth[a] )	b = jump(b, depth[b]-depth[a]);
	if( a == b )	return a;
	for(int i = LOGNMAX-1 ; i>=0 ; i--){
		if( dp[a][i] != dp[b][i] ){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

ll dfs(ll a)
{
	vis[a]=1;
	ll sum=1,mx=-1,id=-1,c=-1;
	lp(i,0,G[a].size())
	{
		ll x=G[a][i].first;
		if(!vis[x])
		{
			depth[x]=depth[a]+1;
			parent[x]=a;
			otherend[ind[a][i]]=x;
			ll temp=dfs(x);
			if(mx<temp)
			{
				mx=temp;
				id=x;
				c=G[a][i].second;
			}
			sum+=temp;
		}
	}
	vis[a]=0;
	SC[a]=id;
	SCcost[a]=c;
	return sum;
}
void hld(ll a,ll cost)	
{
	if(head[cur]==0) head[cur]=a;
	Cid[a]=cur;
	Cpos[a]=Csiz[cur];
	Csiz[cur]++;
	pbase[a]=pos;
	base[pos++]=cost;

	vis[a]=1;
	if(SC[a]>=0) hld(SC[a],SCcost[a]);
	lp(i,0,G[a].size())
	{
		ll x=G[a][i].first;
		if(!vis[x]&&x!=SC[a])
		{
			cur++;
			hld(x,G[a][i].second);
		}
	}

}

ll build(ll node,ll s,ll e)
{
	if(s==e)
	{
		tree[node]=base[s];
		return 0;
	}
	ll mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}


ll query_tree(ll node,ll s,ll e,ll l,ll r)
{
	if(s>r||e<l||s>e) 		return -1;

	if(s>=l&&e<=r)		return tree[node];

	ll mid=(s+e)/2;
	return max(query_tree(2*node,s,mid,l,r),query_tree(2*node+1,mid+1,e,l,r));
}

ll update_tree(ll node,ll s,ll e,ll id,ll val)
{
	if(id>e||id<s) return 0;

	if(s==e&&s==id) 
	{
		tree[node]=val;
		return 0;
	}
	ll mid=(s+e)/2;
	update_tree(2*node,s,mid,id,val);
	update_tree(2*node+1,mid+1,e,id,val);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}

ll up(ll u,ll v)
{
	if(u==v) return 0;
	ll uc,vc=Cid[v],ans=-1;
	while(1)
	{
		uc=Cid[u];
		if(uc==vc)
		{
			if(u==v) break;

			ans=max(ans,query_tree(1,0,n-1,pbase[v]+1,pbase[u]));
			break;
		}
		ans=max(ans,query_tree(1,0,n-1,pbase[head[uc]],pbase[u]));
		u=head[uc];
		u=parent[u];
	}
	return ans;
}

ll update(ll id,ll val)
{
	ll u=otherend[id];
	update_tree(1,0,n-1,pbase[u],val);
}

ll query(ll u,ll v)
{
	ll x=lca(u,v);
	cout<<max(up(u,x),up(v,x))<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    ll t;
    cin >> t;
    while(t--)
   	{

   		ll a,b,wt;
   		cin >> n;
   		lp(i,0,n-1)
   		{
   			cin >> a >> b >> wt;
   			G[a].pb(mp(b,wt));
   			G[b].pb(mp(a,wt));
	   		ind[a].pb(i);
   			ind[b].pb(i);
   		}
   		depth[1]=0;
   		dfs(1);
		hld(1,-1);

		lp(i,1,n+1) dp[i][0]=parent[i];
		dp[1][0]=1;
		lp(j,1,LOGNMAX)
		{
			lp(i,1,n+1)
			{
				if(depth[i]-(1<<j)>=0)
					dp[i][j]=dp[dp[i][j-1]][j-1];
				else dp[i][j]=1;
			}
		}

		build(1,0,n-1);
   		
   		string s;
   		while(1)
   		{
   			cin >> s;
   
   			if(s[0]=='D') break;
   			else if(s[0]=='Q')
   			{
   				cin >>a >> b;
   				query(a,b);

   			}
   			else
   			{
   				cin >>a >> b;
   				update(a-1,b);
   			}
   		}
   		
   		lp(i,0,n+1)
   		{
   			G[i].clear();
   			ind[i].clear();
   			head[i]=0;
   			vis[i]=0;
   			Csiz[i]=0;
   			pos=0;
   			cur=0;
   		}
   	} 
	return 0;
}