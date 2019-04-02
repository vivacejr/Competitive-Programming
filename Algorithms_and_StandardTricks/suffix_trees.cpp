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
const ll N=1e5+5,inf=1e12;
char s[N];
map<ll,ll> to[N];
ll len[N],lpos[N],link[N];
ll node,pos,sz=1,n;

void go_edge()
{
	while(pos > len[to[node][s[n-pos]]])
	{

	}
}

ll add_letter(ll c)
{	
	s[n++]=c;
	pos++;
	ll last = 0;
	while(pos>0)
	{
		goedge();
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string s;
    cin >> s;
    lp(i,0,s.legth())
    {
    	add_letter(s[i]);
    }
	return 0;
}