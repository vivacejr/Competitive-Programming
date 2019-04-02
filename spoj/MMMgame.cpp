#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll cnt=0;
		ll n;
		cin >> n;
		ll ans=0;
		lp(i,0,n)
		{
			ll a;
			cin >> a;
			if(a==1) cnt++;
			ans^=a;
		}
		if(cnt==n)
		{
			if(n%2==0) cout<<"John"<<endl;
			else cout<<"Brother"<<endl;
		}
		else
		{
			if(ans==0)
			{
				cout<<"Brother"<<endl;
			}
			else cout<<"John"<<endl;
		}
	}
	return 0;
}