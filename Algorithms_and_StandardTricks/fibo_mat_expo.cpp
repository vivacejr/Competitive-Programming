#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll mat[100][100];
ll temp[100][100];
ll ans[100][100];
ll mat_sq(ll n)
{
	ll t2[n][n];
	lp(i,0,n)
	{
		lp(j,0,n)
		{
			t2[i][j]=0;
			lp(k,0,n)
			{
				t2[i][j]+=temp[i][k]*temp[k][j];
			}
		}
	}
	lp(i,0,n)
	{
		lp(j,0,n)
		{
			temp[i][j]=t2[i][j];
		}
	}
}

ll mat_mul(ll n)
{
	ll t2[n][n];
	lp(i,0,n)
	{
		lp(j,0,n)
		{
			t2[i][j]=0;
			lp(k,0,n)
			{
				t2[i][j]+=ans[i][k]*temp[k][j];
			}
		}
	}
	lp(i,0,n)
	{
		lp(j,0,n)
		{
			ans[i][j]=t2[i][j];
		}
	}

}

ll matexp(ll n,ll x)
{
	while(x>0)
	{
		if(x&1==1)
		{
			mat_mul(n);
			
		}
		mat_sq(n);

		x=x>>1;
	}
}

int main()
{
	ll q;
	cin >> q;
	ll n=2;
	
	temp[0][0]=mat[0][0]=0;
	temp[1][0]=temp[1][1]=temp[0][1]=mat[1][0]=mat[1][1]=mat[0][1]=1;
	ans[0][0]=1;
	ans[1][1]=1;
	ans[0][1]=0;
	ans[1][0]=0;
	matexp(n,q-1);

	cout<<ans[0][1]+ans[1][1]<<endl;

	return 0;
}