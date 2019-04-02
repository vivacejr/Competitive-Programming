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

ll phi[N],prime[N],prephi[N];

void find()
{
    lp(i,1,N)  	phi[i]=i;
	
	lp(i,2,N)
	{
		if(prime[i]==0)
		{
			lp(j,i,N)
			{
				prime[j]=1;
				phi[j]/=i;
				phi[j]*=i-1;
				j+=i-1;
			}
		}
	}

	lp(i,1,N)
	{
		prephi[i]=phi[i]+prephi[i-1];
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    find();
    while(1)
    {
    	ll n;
    	cin >> n;
    	if(n==0) break;
    	ll ans=0;	
		lp(i,1,(ll)sqrt(n)+1)
		{
			ll f=n/i;
			ll st=n/(i+1);
			ans+=((prephi[f]-prephi[st])*(i)*(i-1))/2;
			if(i!=n/i)
			{
				ll f=i;
				ll st=n/(n/i+1);	
				ans+=((prephi[f]-prephi[st])*(n/i)*(n/i-1))/2;
			}
		}
		cout<<ans<<endl;
    }

	return 0;
}