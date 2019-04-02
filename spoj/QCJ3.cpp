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
		ll n;
		cin >> n;
		ll ans=0;
		lp(i,1,n+1)
		{
			ll a;
			cin >> a;
			if(a%2)
			{
				ans^=i;
			}
		}
		if(ans==0) cout<<"Hanks Wins"<<endl;
		else cout<<"Tom Wins"<<endl;
	}
	return 0;
}