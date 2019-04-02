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
const ll N=1e6+5;


bool prime[N];
ll ans[N];
ll res[N];

ll find()
{		
	lp(i,2,N-1)
	{
		if(prime[i]==0)
		{
			lp(j,i,N-1)
			{
				ans[j]*=(i-1);
				ans[j]/=i;
				prime[j]=1;
				j+=i-1;
			}
		}
	}
	lp(i,1,N-1)
	{
		lp(j,i,N-1)
		{
			res[j]+=(i*ans[i]);
			j+=i-1;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	lp(i,0,N)
	{
		ans[i]=i;
	}
	find();
	ll t;
	cin>> t;
	while(t--)
	{
		ll n;
		cin >> n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		ll sum=res[n]+1;
		sum*=n;
		sum/=2;
		cout<<sum<<endl;

	}    
	return 0;
}