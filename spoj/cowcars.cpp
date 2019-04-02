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
	
multiset<ll> inc,decr;

void del(ll a)
{
	inc.erase(inc.lower_bound(a));
	decr.erase(decr.lower_bound(-a));
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
	ll n,m,d,l;
	cin >> n >> m >> d >> l;
	ll tm=0;
	lp(i,0,n)
	{
		ll a;
		cin >> a;
		if(a-l>=0)
		{
			inc.insert((a-l)/d);
			decr.insert(-(a-l)/d);
		}
		else
		{
			tm++;
		}
	}
	n-=tm;
	ll cnt=0;
	lp(i,0,m)
	{
		multiset<ll>:: iterator it;
		vll v;
		it=decr.begin();
		ll p = *it;
		del(-p);
		cnt++;
		v.pb(-p);
		// cout<<decr.size()<<" "<<-p<<endl;
		if(cnt==n)
		{
			cout<<n<<endl;
			return 0;
		}

		while(1)
		{
			it=decr.upper_bound(p);
			if(it!=decr.end())
			{
				p=*it;
				// cout<<-p<<"xx"<<endl;
				cnt++;
				if(cnt==n)
				{
					cout<<n<<endl;
					return 0;
				}
				v.pb(-p);
				del(-p);
			}
			else
			{
				break;
			}
		}
		p=-1;
		ll add=0;
		rlp(j,v.size()-1,0)
		{
			ll x=v[j];
			add+=x-p-1;
			// cout<<v[j]<<	"aaa"<<x<<" "<<p<<" "<<add<<endl;
			while(add>0)
			{
				it = inc.lower_bound(p+1);
				if(it!=inc.end()&&(*it)<=x)
				{
					cnt++;
					// cout<<*it<<endl;
					if(cnt==n)
					{
						cout<<cnt<<endl;
						return 0;
					}
					del(*it);
					add--;
				}
				else 
				{
					add++;
					break;
				}
			}
			p=x;
		}



	}
	cout<<cnt<<endl;


	return 0;
}