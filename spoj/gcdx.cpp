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
const ll N=1e6+5;

bool prime[N];
ll phi[N],ans[N],fin[N];

ll seive()
{
	lp(i,2,N)
	{
		if(prime[i]==0)
		{
			lp(j,i,N)
			{
				prime[j]=1;		
				phi[j]*=(i-1);
				phi[j]/=i;
				j+=i-1;
			}
		}
	}
	lp(i,1,N)
	{
		lp(j,i,N)
		{
			ans[j]+=phi[j/i]*(i);
			j+=i-1;
		}
	}
}	

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    lp(i,0,N)
    {
    	phi[i]=i;
    }

    seive();
    fin[1]=0;
    fin[2]=1;
    lp(i,3,N)
    {
    	fin[i]=fin[i-1]+ans[i]-i;
    }
    while(1)
    {
    	ll n;
    	cin >> n;
    	if(n==0)
    	{
    		break;
    	}
    	cout<<fin[n]<<endl;
    }
	return 0;
}