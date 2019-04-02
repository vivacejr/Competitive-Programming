#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll>
#define pll pair<ll,ll> 

ll expo(ll base, ll exponent, ll mod) { ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) 
            ans = (ans*base)%mod ;
        base = (base*base)%mod; exponent>>= 1;
    }return ans%mod;}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	return 0;
}