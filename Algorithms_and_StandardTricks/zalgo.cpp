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
ll z[N];
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	string s;
	cin >> s;
	zalgo(s);
	lp(i,0,s.length())
	{
		cout<<z[i]<<" ";
	}
	cout<<endl;

	return 0;
}