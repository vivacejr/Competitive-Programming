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
const ll N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
      ll b=5;
      ll *a=&b;
      cout<<*a<<" "<<b<<endl;      
      *a=4;
      cout<<*a<<" "<<b<<endl;      
    return 0;
}