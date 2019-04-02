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
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,m,d,l;
	cin << n >> m >> d >> l;
	multiset<ll> S;

	lp(i,0,n)
	{
		ll a;
		cin >> a;
		ll x=(a-l)/d;
		if(a>=l)
		{
			S.insert(-x)
		}
	}
	ll cnt=0;
	lp(i,0,m)
	{
		multiset<ll>:: iterator it,it1;
		it=S.begin();
		S.erase(it);
		p=*it;
		cnt++;
		if(cnt==n) break;
		while(1)
		{
			it=S.upperbound(p);
			if((*it)<p-1)
			{

			}
			else
			{
				cnt++;
				p=*it;
				S.erase(it);
			}
		}
	}
	return 0;
}