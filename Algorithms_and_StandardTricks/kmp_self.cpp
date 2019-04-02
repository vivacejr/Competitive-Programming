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

string s1,s2;
ll l1,l2;
ll lps[100005];
ll cnt=0;

void F()
{
	ll i=0,j=0;
	while(i<l1)
	{
		if(s1[i]==s2[j])
		{
			i++;
			j++;
		}
		if(j==l2)
		{
			cout<<i-l2<<endl;
			cnt++;
			j=lps[j-1];
		}
		else if(i!=l1&&s1[i]!=s2[j])
		{
			if(j)j=lps[j-1];
			else i++;
		}
	}
}

void H()
{
	ll i=1,len=0;
	lps[0]=0;
	while(i<l2)
	{
		if(s2[i]==s2[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len) len=lps[len-1];
			else i++;
		}
	}	
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
    cin >> s1 >> s2;
    l1=s1.length();
    l2=s2.length();

    H();
    F();
    cout<<"Total = "<<cnt<<endl;

	return 0;
}