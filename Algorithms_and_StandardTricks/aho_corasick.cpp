//SPOJ SUB_PROB
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

const ll N=1e6+5,inf=1e9,k=65;
ll vis[N];
struct node{
	ll nxt[k],go[k];
	ll p,link,nxtleaf;
	// ll pch;
	char pch;
	ll leaf;
};
 
node init()
{
	node tp;
	lp(i,0,k)
	{
		tp.nxt[i]=-1;
		tp.go[i]=-1;
	}
	// map<char,ll> nxt;
	// map<char,ll> go;
	tp.nxtleaf=0;
	tp.link=-1;
	tp.leaf=0;
	return tp;
}

vector<node> v;

ll conv(ll a)
{
	if(a>='a'&&a<='z')a=a-'a';
	else if(a>='0'&&a<='9')a=a-'0'+26;
	else a=a-'A'+36;
	return a;
}
void insert(string s)
{
	ll cur=0;
	lp(i,0,s.size())
	{
		char a=s[i];
		a=conv(a);
		// if((v[cur].nxt).count(a)==0)
		if(v[cur].nxt[a]==-1)
		{
			node tp = init();
			tp.p=cur;
			tp.pch=a;
			v.pb(tp);
			v[cur].nxt[a]=v.size()-1;
		
		}
		cur=v[cur].nxt[a];
	}	
	v[cur].leaf=1;
}

ll go(ll cur, ll c);

ll get_link(ll cur)
{
	if(v[cur].link==-1)
	{
		if(cur==0 || v[cur].p==0 )
		{
			v[cur].link = 0;
			v[cur].nxtleaf = 0;
		}
		else
		{
			v[cur].link =  go(get_link(v[cur].p),v[cur].pch);
		}
 
		if(v[v[cur].link].leaf==1)
			v[cur].nxtleaf=v[cur].link;
		else
			v[cur].nxtleaf=v[v[cur].link].nxtleaf;
	}
	
	return v[cur].link;
}
 
ll go(ll cur, ll c)
{
	// if((v[cur].go).count(c)==0)
	if(v[cur].go[c]==-1)
	{
		if(v[cur].nxt[c]!=-1)
		{
			v[cur].go[c]=v[cur].nxt[c];
		}
		else
		{
			v[cur].go[c] = cur == 0 ? 0 : go(get_link(cur), c);
		}
	}
	return v[cur].go[c];
}
   
ll bfs()
{
	ll cur=0;
	queue<ll> q;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		get_link(cur);
		lp(i,0,k)
		{
			if(v[cur].nxt[i]>0)
			{
				q.push(v[cur].nxt[i]);
			}	
		}
	}
	return 0;
}
ll chk(ll cur)
{
	while(cur!=0)
	{
		if(vis[cur]!=-1)return 0;
		vis[cur]=1;
		if(v[cur].leaf==1)
		{
			v[cur].leaf = 2;
		}
		cur=v[cur].nxtleaf;
	}	
}
 
ll solve(string s)
{
	ll cur=0;
	lp(i,0,s.size())
	{
		ll a=s[i];
		a=conv(a);
		cur=v[cur].nxt[a];
	}	
	return v[cur].leaf==2;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string p;
	cin >> p;
	ll n;
	cin >> n;
	string s[n];
	node root =init();
	v.pb(root);
	lp(i,0,n)
	{
		cin >> s[i];
		insert(s[i]);
	}
	memset(vis,-1,sizeof(vis));
	bfs();
	ll cur=0;
	lp(i,0,p.size())
	{
		cur=go(cur,conv(p[i]));
		chk(cur);
	}
	lp(i,0,n)
	{
		if(solve(s[i])==1)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;	
} 