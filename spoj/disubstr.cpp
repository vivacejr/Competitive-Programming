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

set<string> A;
vector<vector<ll> >V(26);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
    	ll ans=0;
    	string s;
    	cin >>s;
    	ll len=s.length();
    	lp(i,0,len)
    	{
			V[s[i]-'A'].pb(i);
    	}
    	lp(i,0,26)
    	{
    		lp(j,0,V[i].size())
    		{
    			string t;
    			lp(k,V[i][j],len)
    			{
    				t+=s[k];
    				A.insert(t);
    			}
    		}
    		ans+=A.size();
    		A.clear();
    	}
    	lp(i,0,26)V[i].clear();	
    	cout<<ans<<endl;
    }
	return 0;
}