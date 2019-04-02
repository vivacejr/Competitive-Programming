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


vector<vll> G(N);
vector<vll> CH(N);

vector<set<ll> > black(N);
ll n,q,col[N],parent[N];
ll SC[N],Cid[N],Cpos[N],head[N],size[N];

ll chk()
{
	lp(i,1,n+1)
	{
		cout<<SC[i]<<" ";
	}
	cout<<endl;

	lp(i,1,n+1)
	{
		cout<<Cid[i]<<" ";
	}
	cout<<endl;	

	lp(i,1,n+1)
	{
		cout<<Cpos[i]<<" ";
	}
	cout<<endl;

}



ll dfs(ll a,ll par)
{
	ll sum=1,mx=-1,id=-1;
	parent[a]=par;
	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=par)
		{
			ll temp=dfs(x,a);
			if(temp>mx)
			{
				id=x;
				mx=temp;
			}
			sum+=temp;
		}
	}
	SC[a]=id;
	return sum;
}

ll cur=0,pos=0;
ll hld(ll a,ll par)
{
	// cerr<<a<<" "<<par<<endl;
	if(head[cur]==0) head[cur]=a;
	Cpos[a]=size[cur]++;
	Cid[a]=cur;
	CH[cur].pb(a);
	if(SC[a]>0)
	hld(SC[a],a);

	lp(i,0,G[a].size())
	{
		ll x=G[a][i];
		if(x!=par&&x!=SC[a]) 
		{
			cur++;
			hld(x,a);
		}
	}
}	

ll update(ll a)
{
	if(col[a]==0)
	{
		col[a]=1;
		black[Cid[a]].insert(Cpos[a]);
	}
	else
	{
		col[a]=0;
		black[Cid[a]].erase(Cpos[a]);
	}
}
set<ll>::iterator it;
ll up(ll u)
{
	ll uc,vc=0;
	ll ans=-1;
	while(1)
	{
		uc=Cid[u];
		// cerr<<uc<<endl;
		if(uc==vc)
		{
			if(u==1) 
			{
				if(col[1]==1)return 1;
				else return -1;
			}
			if(black[uc].size()==0) return ans;

			ll x=*(black[uc].lower_bound(0));
			
			if(x>Cpos[u]) return ans;
			else ans=CH[uc][x];

			return ans;
		}
		if(black[uc].size()>0)
		{
			ll x=*(black[uc].lower_bound(0));

			if(x>Cpos[u]) break;
			else ans=CH[uc][x];
		}
		u=head[uc];
		u=parent[u];
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

	cin >> n>>q;
	lp(i,0,n-1)
	{
		ll a,b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1,-1);
	hld(1,-1);

	while(q--)
	{
		ll type,a;
		cin >> type>>a;

		if(type==0) update(a);
		else 
		{
			cout<<up(a)<<endl;
		}
	}




	return 0;
}