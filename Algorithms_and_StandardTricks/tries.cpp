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
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18;

struct node{
	ll ary[26];
};

node get()
{
	node a;
	lp(i,0,26)
	{
		a.ary[i]=-1;
	}
	return a;
}


vector<node> v;
ll insert(string s)
{
	ll cur=0;
	lp(i,0,sz(s))
	{
		if(v[cur].ary[s[i]-'a']==-1)
		{
			node tp=get();
			v[cur].ary[s[i]-'a']=sz(v);
			cur=sz(v);
			v.pb(tp);
		}
		else
		{
			cur=v[cur].ary[s[i]-'a'];
		}
	}
}

ll search(string s) // checks if stirng is present as the prefix of inserted string in trie or not.
{
	ll cur=0; // root
	lp(i,0,sz(s))
	{
		if(v[cur].ary[s[i]-'a']==-1)
		{
			return 0;
		}
		else
		{
			cur=v[cur].ary[s[i]-'a'];
		}		
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string s;
	cin >> s;
	ll n;
	cin >> n;
	string t[n];
	node root=get();
	v.pb(root);
	lp(i,0,n)
	{
		cin >> t[i];
		insert(t[i]);
	}

	return 0;
}