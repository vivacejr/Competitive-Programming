// https://www.codechef.com/APRIL19A/problems/XORMIN
// author - vivacejr

#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>

#define all(X) X.begin(),X.end()
#define endl "\n"

const ll N=2e5+5;
ll st[N],ed[N];
vll G[N];
vll tour;
ll tme=0,cur=0;
ll dfs(ll a,ll p)
{
	tour.pb(a);
	st[a]=tme++;
	lp(i,0,G[a].size())
		if(G[a][i]!=p)
			dfs(G[a][i],a);
	ed[a]=tme-1;
}
struct trie{
	ll last[2];
	ll nxt[2];
};

trie Node[N*21];
ll getNode()
{
	trie temp;
	temp.last[0]=-1;
	temp.last[1]=-1;
	temp.nxt[0]=-1;
	temp.nxt[1]=-1;
	Node[cur]=temp;
	cur++;
	return (cur-1);
}
ll root[N];

ll insert(ll nd,ll par,vll s,ll id)
{
	lp(i,0,20)
	{
		if(Node[nd].nxt[s[i]]==-1)
		{
			ll z=getNode();
			Node[nd].nxt[s[i]]=z;
			Node[nd].last[s[i]]=id;
			if(par!=-1)
			{
				Node[nd].nxt[1-s[i]]=Node[par].nxt[1-s[i]];
				Node[nd].last[1-s[i]]=Node[par].last[1-s[i]];
			}
		}
		nd=Node[nd].nxt[s[i]];
		if(par!=-1)
			par=Node[par].nxt[s[i]];
	}
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,q;
		cin >> n >> q;
		ll ary[n];
		lp(i,0,n)
			cin >> ary[i];
		lp(i,0,n-1)
		{
			ll a,b;
			cin >> a >> b;
			G[a].pb(b);
			G[b].pb(a);
		}
		dfs(1,0);
		map<ll,ll> M;
		ll mc=0;
		vll tp;
		lp(i,0,n)tp.pb(ary[i]);
		sort(all(tp));
		lp(i,0,n)
		{
			if(M.count(tp[i])==0)M[tp[i]]=mc++;
		}
		lp(i,0,n)tp[i]=M[ary[i]];
		cout<<endl;
		vpll freq[mc+1];
		ll sorted[mc+1];
		memset(sorted,0,sizeof(sorted));
		vll sparse[mc+1][20];
		lp(i,0,n)
		{
			vll s;
			freq[tp[tour[i]-1]].pb(mp(i,tour[i]-1));
		}
		lp(i,0,n)
		{
			if(sorted[tp[i]]==0)
			{
				sorted[tp[i]]=1;
				ll sz=freq[tp[i]].size();
				lp(j,0,sz)
				{
					sparse[tp[i]][0].pb(freq[tp[i]][j].ss);
				}
				lp(j,1,20)
				{
					if((1<<j)>sz)break;
					ll flag=0;
					lp(k,0,sz)
					{
						if(k+(1<<(j-1))>=sz)
						{
							break;
						}
						if(sparse[tp[i]][j-1][k] < sparse[tp[i]][j-1][k+(1<<(j-1))])
						{
							sparse[tp[i]][j].pb(sparse[tp[i]][j-1][k]);
						}
						else
						{
							sparse[tp[i]][j].pb(sparse[tp[i]][j-1][k+(1<<(j-1))]);
						}
					}
				}
			}
		}
		lp(i,0,n)
		{
			root[i]=getNode();
			vll s;
			rlp(j,19,0)
			{
				if((ary[tour[i]-1]&(1<<j))==(1<<j))
				{
					s.pb(1);
				}
				else
				{
					s.pb(0);
				}
			}
			if(i>0)
				insert(root[i],root[i-1],s,i);
			else
				insert(root[i],-1,s,i);
		}
		ll p1=0,p2=0;
		while(q--)
		{
			ll val,k;
			cin >> val >> k;
			val^=p1;
			k^=p2;
			vll s;
			ll x=0;
			ll cur2 = root[ed[val]];
			lp(i,0,20)
			{
				ll d=0;
				if( (k&(1<<(19-i))) == (1<<(19-i))	)
					d=1;
				if(Node[cur2].nxt[1-d]!=-1&&Node[cur2].last[1-d]>=st[val])
				{
					x+=(1<<(19-i));
					cur2=Node[cur2].nxt[1-d];
				}
				else
				{
					cur2=Node[cur2].nxt[d];
				}
			}
			x=x^k;
			ll y=M[x];
			ll l=lower_bound(all(freq[y]),mp(st[val],(ll)-1))-freq[y].begin();
			ll r=upper_bound(all(freq[y]),mp(ed[val],N*100))-freq[y].begin();
			r--;
			ll len=log2(r-l+1);
			ll ans=1e8;
			if(sparse[y][len][l] <= sparse[y][len][r-(1<<len)+1])
			{
				ans=sparse[y][len][l];
			}
			else
			{
				ans=sparse[y][len][r-(1<<len)+1];	
			}
 			cout<<ans+1<<" "<<(x^k)<<endl;
			p1=ans+1;
			p2=x^k;
		}
		cur=0;
		tme=0;
		lp(i,0,n+1)
		{
			root[i]=-1;
			G[i].clear();
		}
		tour.clear();
	}
	return 0;
}