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
#define endl "\n"
const ll N=200005;
const ll LOGNMAX =20;

vector<vector<pll> > G(N);
ll vis[N],SC[N],Cid[N],head[N],Cpos[N],Csiz[N],base[N],pbase[N];
ll SCcost[N],lazy[4*N],tree[4*N],otherend[N];
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
void hld(ll a)	
{
	if(head[cur]==0) head[cur]=a;
	Cid[a]=cur; //chain id of a
	Cpos[a]=Csiz[cur]; //a's pos in its chain
	Csiz[cur]++; //size of chain
	pbase[a]=pos; //base tree mein a ki pos
	// base[pos++]=cost; //base mein daal diya vo iss ques mein no need
	pos++;
	vis[a]=1;
	if(SC[a]>=0) hld(SC[a]);
	lp(i,0,G[a].size())
	{
		ll x=G[a][i].first;
		if(!vis[x]&&x!=SC[a])
		{
			cur++;
			hld(x);
		}
	}

}

ll build(ll node,ll s,ll e)
{
	if(s==e)
	{
		tree[node]=0;
		lazy[node]=0;
		return 0;
	}
	ll mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	tree[node]=0;
}


ll query_tree(ll node,ll s,ll e,ll l,ll r)
{
	if(lazy[node])
	{
		tree[node]+=(e-s+1)*lazy[node];
		if(s!=e)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(s>r||e<l||s>e) 		return 0;

	if(s>=l&&e<=r)		return tree[node];

	ll mid=(s+e)/2;
	return query_tree(2*node,s,mid,l,r)+query_tree(2*node+1,mid+1,e,l,r);
}

ll update_tree(ll node,ll s,ll e,ll l,ll r,ll val)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(e-s+1)*lazy[node];
		if(s!=e)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l>e||r<s) return 0;

	if(s>=l&&e<=r) 
	{
		tree[node]+=(e-s+1)*val;
		lazy[2*node]+=val;
		lazy[2*node+1]+=val;
		return 0;
	}
	ll mid=(s+e)/2;
	update_tree(2*node,s,mid,l,r,val);
	update_tree(2*node+1,mid+1,e,l,r,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}

ll up(ll u,ll v)
{
	if(u==v) return 0;
	ll uc,vc=Cid[v],ans=0;
	while(1)
	{
		uc=Cid[u];
		if(uc==vc)
		{
			if(u==v) break;

			ans+=query_tree(1,0,n-1,pbase[v]+1,pbase[u]);
			break;
		}
		ans+=query_tree(1,0,n-1,pbase[head[uc]],pbase[u]);
		u=head[uc];
		u=parent[u];
	}
	return ans;
}

ll up2(ll u,ll v,ll val)
{
	if(u==v) return 0;
	ll uc,vc=Cid[v];
	while(1)
	{
		uc=Cid[u];
		if(uc==vc)
		{
			if(u==v) break;

			update_tree(1,0,n-1,pbase[v]+1,pbase[u],val);
			break;
		}
		update_tree(1,0,n-1,pbase[head[uc]],pbase[u],val);
		u=head[uc];
		u=parent[u];
	}
}
ll update(ll u,ll v,ll val)
{
	ll x=lca(u,v);
	up2(u,x,val);
	up2(v,x,val);
	update_tree(1,0,n-1,pbase[x],pbase[x],val);
}

ll query(ll u,ll v)
{
	ll x=lca(u,v);
	cout<<up(u,x)+up(v,x)+query_tree(1,0,n-1,pbase[x],pbase[x])<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll a,b,wt;
	ll q;
	cin >> n>>q;
	lp(i,0,n-1)
	{
		cin >> a >> b;
		G[a].pb(mp(b,1));
		G[b].pb(mp(a,1));
	}
	depth[1]=0;
	dfs(1);
	hld(1);

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

	build(1,1,n+1);

	// a se b 1 krdo
	// fer c se d ke path mein jitne 1 hai ginn lo

	while(q--)
	{
		ll a,b,c,d;
		cin >>a >> b;
		update(a,b,1);
		cin >>c >> d;
		query(c,d);
		update(a,b,-1);
	}
	return 0;
}