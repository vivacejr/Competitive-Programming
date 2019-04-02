#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int MAXN=111111;
std::vector<int> vtr[MAXN];
int anc[MAXN][20],lvl[MAXN],val[MAXN],rm[MAXN],sz=0;
map<int,int> M;
struct node
{
		int cnt;
		node* left;
		node* right;
		node(int cnt,node* left,node* right):
			cnt(cnt),left(left),right(right){}

		node* insert(int l,int r,int x);
};
node* root[MAXN];
node* ini= new node(0,NULL,NULL);

node* node::insert(int l,int r,int x)
{
	if(x>=l && x<r)
	{
		if(l+1==r)
		{
			return new node(this->cnt+1,ini,ini);
		}
		int m=(l+r)>>1;
		return new node(this->cnt+1,this->left->insert(l,m,x),this->right->insert(m,r,x));
	}
	return this;
}

void dfs(int x,int p)
{
	anc[x][0]=p;
	lvl[x]=lvl[p]+1;
	if(p)
		root[x]=root[p]->insert(0,sz,M[val[x]]);
	else
		root[x]=ini->insert(0,sz,M[val[x]]);
	for(int i=0;i<vtr[x].size();i++)
	{
		int u=vtr[x][i];
		if(u!=p)
			dfs(u,x);
	}
}
void pre(int n)
{
	int i,j;
	for(j=1;j<20;j++)
		for(i=1;i<=n;i++)
		{
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
}
int lca(int p,int q)
{
	int i;
	if(lvl[q]>lvl[p])
	{
		return lca(q,p);
	}
	for(i=19;i>=0;i--)
	{
		if(lvl[p] - (1<<i)>=lvl[q])
		{
			cout<<lvl[p]-(1<<i)<<" "<<lvl[q]<<" "<<i<<endl;
			p=anc[p][i];
		}
	}
	cout<<p<<endl;
	if(p==q)
		return p;
	for(i=19;i>=0;i--)
	{
		int x=anc[p][i];
		int y=anc[q][i];
		if(x!=y && x!=0 && y!=0)
		{
			p=x;
			q=y;
		}
	}
	return anc[p][0];
}
int query(node* a,node* b,node* c,node* d,int l,int r,int k)
{
	if(l+1==r)
		return l;
	int ct=a->left->cnt+b->left->cnt-c->left->cnt-d->left->cnt;
	int m=(l+r)>>1;
	if(ct>=k)
		return query(a->left,b->left,c->left,d->left,l,m,k);
	return query(a->right,b->right,c->right,d->right,m,r,k-ct);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,i,u,v,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>val[i];
		M[val[i]];
	}
	for( map <int, int > :: iterator it = M.begin(); it != M.end(); it++ )	
	{
		M[it->ff]=sz;
		rm[sz]=it->ff;
		sz++;
	}
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		vtr[u].pb(v);
		vtr[v].pb(u);
	}
	ini->left=ini->right=ini;
	dfs(1,0);
	pre(n);
	while(m--)
	{
		cin>>u>>v>>k;
		int t=lca(u,v);
		// int t=1;
		if(t!=1)
			cout<<rm[query(root[u],root[v],root[t],root[anc[t][0]],0,sz,k)]<<"\n";
		else
			cout<<rm[query(root[u],root[v],root[t],ini,0,sz,k)]<<"\n";
	}
	return 0;
}