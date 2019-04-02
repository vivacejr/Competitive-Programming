#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;


#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front



int main(){
	
	pbds A;
	ll n;
	cin >> n;
		ll cnt=0;
	
	while(n--)
	{
		char c;
		ll a;
		cin >> c>>a;
		if(c=='I')
		{
			A.insert(a);
		}
		else if(c=='C')
		{
			cout<<A.order_of_key(a)<<endl; 
		}
		else if(c=='K')
		{
			if(A.size()<a) cout<<"invalid"<<endl;
			else
			cout<<*A.find_by_order(a-1)<<endl; 

		}
		else if(c=='D')
		{
			A.erase(a);
		}
	}



	
	return 0;
}