// spoj problem COT using persistent seg trees

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back	
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"

const ll N=1e5+5,LOGN=20;
ll v[N],av[N],dp[N][LOGN],lvl[N],n,c;
map<ll,ll> M;
vll G[N];

struct node{
	node * left;
	node * right;	
	ll val;
};


node * root;
node * R[N];

node * init()
{
	node * temp=new node;
	temp->left = temp->right = NULL;
	temp->val = 	0;
	return temp;
}

ll jump(ll x, ll d){
	for(ll i = LOGN-1 ; i>=0 ; i--){
		if( (1<<i) <= d ){
			x = dp[x][i];
			d -= (1<<i);
		}
	}
	return x;
}

ll LCA(ll a, ll b){
	if( lvl[a] > lvl[b] )	a = jump(a, lvl[a]-lvl[b]);
	if( lvl[b] > lvl[a] )	b = jump(b, lvl[b]-lvl[a]);

	if( a == b )	return a;
	for(ll i = LOGN-1 ; i>=0 ; i--)
	{
		if( dp[a][i] != dp[b][i] )
		{
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}


node * build(ll l,ll r,ll w,node * par)
{
	// cerr <<l<<" 	"<<r<<endl;
	if(l==r)
	{
		node * temp=init();
		temp->val=par->val+1;

		return temp;
	}
	if(w>=l&&w<=r)
	{
		ll mid=(l+r)/2;
		node * temp= init();
		if(w<=mid)
		{
			temp->left=build(l,mid,w,par->left);
			temp->right=par->right;
		}
		else
		{
			temp->right=build(mid+1,r,w,par->right);
			temp->left=par->left;
		}
		temp->val=temp->right->val+temp->left->val;
		return temp;
	}
}

node *buildspecial(ll l,ll r)
{
	if(l==r)
	{
		node * temp =init();
		return temp;
	}
	ll mid=(l+r)/2;
	node * temp= init();
	temp->left=buildspecial(l,mid);
	temp->right=buildspecial(mid+1,r);
	temp->val=temp->right->val+temp->left->val;
	return temp;
}
ll dfs(ll a,ll par)
{
	// cerr<<a<<" "<<v[a]<<" "<<M[v[a]]<<endl;
	R[a]=init();
	R[a]=build(0,c-1,M[v[a]],R[par]);
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=par)
		{
			dp[x][0]=a;
			lvl[x]=lvl[a]+1;
			dfs(x,a);
		}
	}
}
ll query(node* a,node* b,node* c,node* d,ll l,ll r,ll k)
{
	if(l==r)
		return l;
	ll ct=a->left->val+b->left->val-c->left->val-d->left->val;
	ll m=(l+r)>>1;
	if(ct>=k)
		return query(a->left,b->left,c->left,d->left,l,m,k);
	return query(a->right,b->right,c->right,d->right,m+1,r,k-ct);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll m;
    cin >> n >> m;
    root = init();
    lp(i,0,n)
    {
    	cin >> v[i+1];
    	M[v[i+1]];
    }
    for(auto it= M.begin();it!=M.end();it++)
    {
    	M[it->first]=c;
    	av[c++]=it->first;
    }
    lp(i,0,n-1)
    {
    	G[i+1].pb(i+2);
    	G[i+2].pb(i+1);
    }
    root->left = init();
    root->right = init();

    dp[1][0]=0;
    lvl[1]=0;
    R[0]=buildspecial(0,c-1);
    dfs(1,0);


	lp(j,1,LOGN)
	{
		lp(i,1,n+1)
		{
			if(lvl[i]-(1<<j)>=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
			else dp[i][j]=1;
		}
	}
	while(m--)
	{
		ll u,v,k;
		cin>>u>>v>>k;
		ll t=LCA(u,v);
		cout<<av[query(R[u],R[v],R[t],R[dp[t][0]],(ll)0,c-1,k)]<<endl;
	}
	return 0;
}	