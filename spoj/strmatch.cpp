#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll> 
ll mod=1000000007;
ll x=mod+2;
// ll y=mod;

ll expo(ll base, ll exponent, ll mod) {
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&(1LL)) == 1) {
            ans = (ans*base)%mod ;
        }
        base = (base*base)%mod;
        exponent>>= 1;
    }
    return ans;
}
char s[100005];
ll ash[10000];

ll getLR(ll l,ll r)
{	
	ll ans=(ash[r]-ash[l-1]+mod)%mod;
	ll temp=expo(x,mod-l,mod);
	ans*=temp;
	ans%=mod;
	return ans;
}
vector<ll> sto;
// map<ll,ll> M;

int main()
{
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
	ll n,q;
	scanf("%lld%lld",&n,&q);
	scanf("%s",s);
	ash[0]=0;
	ash[1]=s[0];
	ll temp=x;
	// ll temp2=y;
	lp(i,2,n+1)
	{
		ash[i]=(ash[i-1]+(temp*s[i-1])%mod)%mod;
		temp*=x;
		temp%=mod;
	}

	ll qhash[10000];
	ll num=0;
	lp(i,1,n+1)
	{
		lp(j,i,n+1)
		{
			ll x=getLR(i,j);
			sto.pb(x);
		}
	}
	sort(sto.begin(),sto.end());

	while(q--)
	{
		// cerr<<q<<endl;

		char qs[1000000];
		scanf("%s",qs);
		// cin >> qs;
		qhash[0]=0;
		qhash[1]=qs[0];

		ll len=strlen(qs);
		 temp=x;
		lp(i,2,len+1)
		{
			qhash[i]=(qhash[i-1]+(temp*qs[i-1])%mod)%mod;
			temp*=x;
			temp%=mod;
		}
		ll a,b;
		a=(lower_bound(sto.begin(),sto.end(),qhash[len]))-sto.begin();
		b=(upper_bound(sto.begin(),sto.end(),qhash[len]))-sto.begin();
		cout<<b-a<<endl;
	}
	return 0;
}