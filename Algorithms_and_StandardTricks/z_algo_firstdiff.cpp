//finding first point of difference bw two strings
//z-algo
//beautiful trick

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
const ll N=2e5+5;

ll z[N];
ll x=0;
void zalgo(string s)
{
	ll l=-1,r=-1,n=s.length();
	lp(i,1,n)
	{
		if(r<i)
		{
			l=r=i;
			while(r<n && s[r-l] == s[r])r++;
			r--; 
			z[i]=r-l+1;
		}
		else
		{
			ll k=i-l;
			if(z[k]<r-i+1)	z[i]=z[k];
			else
			{
				l = i;
				while(r<n && s[r-l]==s[r]) r++;
				r--;
				z[i]=r-i+1;
			}
		}
	}
	lp(i,x+1,n)
	{
		cout<<i<<" "<<z[i]<<endl;
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	string s,s1;
	cin >> s >> s1;
	x=s1.length();
	zalgo(s1+"@"+s);
	return 0;
}