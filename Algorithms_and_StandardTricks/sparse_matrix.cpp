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
const ll N=3e3+5,mod=998244353;
typedef vector<pair<pll,ll> > spm;
ll n,r,k;

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

spm mul(spm a,spm b)
{
	spm result;
	// b=transpose(b);
	ll M[n+1][n+1];

	memset(M,0,sizeof(M));
	lp(i,0,a.size())
	{
		lp(j,0,b.size())
		{
			if(a[i].F.S==b[j].F.F)
			{
				M[a[i].F.F][b[j].F.S]+=a[i].S*b[j].S;
				M[a[i].F.F][b[j].F.S]%=mod;
			}
		}
	}
	lp(i,1,n+1)
	{
		lp(j,1,n+1)
		{
			if(M[i][j]>0)
			{
				result.pb(mp(mp(i,j),M[i][j]));
			}
		}
	}
	return result;
}

spm pow(spm a,ll k)
{
	if(k==1)return a;
	if(k%2)
	{
		return mul(a,pow(a,k-1));
	}
	spm ret = pow(a,k/2);
	return mul(ret,ret);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	spm sp;
	lp(i,0,n-1)
	{
		ll a,b;
		cin >>a >> b;
		sp.pb(mp(mp(a,b),(ll)1));
		sp.pb(mp(mp(b,a),(ll)1));
	}
	sort(sp.begin(),sp.end());
	cin >> r >> k;
	sp = pow(sp,k);
	ll ans[n+1];
	memset(ans,0,sizeof(ans));
	lp(i,0,sp.size())
	{
		if(sp[i].F.S==r)
		{
			ans[sp[i].F.F]=sp[i].S;
		}
	}
	lp(i,1,n+1)
	{
		cout<<ans[i]%mod<<" ";
	}
	cout<<endl;
	return 0;
}