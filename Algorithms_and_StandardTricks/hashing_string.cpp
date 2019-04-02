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
ll mod=998244353,p=1003;
const ll N=1e5+5;
ll H[N],pre[N];
string s;
ll expo(ll b,ll e,ll m)
{
	ll a=1;
    while(e !=0 )
    {
        if((e&1) == 1) 
            a= (a*b)%m;
        b=(b*b)%m; e>>= 1;
	}
	return a%m;
}
ll query(ll l,ll r)
{
	ll m=0, d=r-l+1;
	d=expo(p,d,mod);
	if(l!=0)
	{
		m=H[l-1];
	}
	return (H[r]-(m*d)%mod+mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> s;
    ll n=s.length();
   	H[0]=s[0];
    lp(i,1,n)
    {
    	H[i]=((H[i-1]*p+s[i]))%mod;
    }
    ll q;
    cin >> q;
    while(q--)
    {
    	ll l,r;
    	cin >> l >> r;
    	cout<<query(l,r)<<endl;

    }	
	return 0;
}