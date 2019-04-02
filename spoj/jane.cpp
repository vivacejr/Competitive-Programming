#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll> 
ll expo(ll base, ll exponent, ll mod) {
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = (ans*base)%mod ;
        }
        base = (base*base)%mod;
        exponent>>= 1;
    }
    return ans%mod;
}
queue<pair<ll,ll> >  Q;
set<pair<ll,ll> >S;
ll ary[100005];
ll n,d;
set<pair<ll,ll> > A;
ll chk(ll a,ll b)
{
	if(a>b) swap(a,b);
	if(S.find(mp(a,b))==S.end())
	{
		S.insert(mp(a,b));
		if(abs(ary[b]-ary[a])<=d)
		{
			// cout<<a<<"--"<<b<<endl;
			if(a!=b) A.insert(mp(a,b));
			Q.push(mp(a,b));
		}
	}
}
ll bfs()
{
	while(!Q.empty())
	{
		pair<ll,ll> x=Q.front();
		ll x1=x.first;
		ll x2=x.second;
		Q.pop();
		
		if(x1>0&&x2<n-1)	chk(x1-1,x2+1);
		
		if(x1<n-1&&x2>0 ) chk(x1+1,x2-1);

		if(x1<n-1&&x2<n-1)	chk(x1+1,x2+1);

		if(x1>0&&x2>0) chk(x1-1,x2-1);

	}
}

int main()
{
    scanf("%lld%lld",&n,&d);
    
    lp(i,0,n)
    {
    	scanf("%lld",&ary[i]);

    	if(i!=0&&abs(ary[i]-ary[i-1])<=d)
    	{
    	 	Q.push(mp(i-1,i));
    	 	S.insert(mp(i-1,i));
    	 	A.insert(mp(i-1,i));
		}
		Q.push(mp(i,i));
		S.insert(mp(i,i));
	}
	bfs();
	set<pair<ll,ll> >:: iterator it;
	for(it=A.begin();it!=A.end();it++)
	{
		pair<ll,ll> x=*it;
		printf("%lld %lld\n",x.first+1,x.second+1);
	}

	return 0;
}