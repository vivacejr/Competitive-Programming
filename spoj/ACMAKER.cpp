#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
string final[100000];
string waste[100000];
string temp[100000];
string s[10000];
ll dp[300][300][300];
ll totalchar,totalwords;
ll func(ll i,ll k,ll p)
{
		// cout << i << " "<<k <<" "<<totalchar<<" "<<totalwords<<endl;
		ll x=final[i].size();
		ll flag=0;
		if(i==totalwords&&k==totalchar)
		{
			// cout << i<<endl;
			return 1;
		}
		else if(i>=totalwords||k>=	totalchar)
		{
			return 0;
		}
		// cout << x << endl;
		if(dp[i][k][p]==-1)
		{
			dp[i][k][p]=0;
			ll temp=k;
			for (int j = p; j<x ; ++j)
			{
				// cout << i << " "<<temp <<" "<<p<<" "<<j<<	" "<<dp[i][k][p]<<endl;
				// cout <<	 j << endl;
				if(totalchar-temp+1<=totalwords-i)
				{
					// cout << totalchar<<" "<<temp<<" "<<totalwords<<endl;
					// cout << "xxx" << endl;
					break;
				}
				if(final[0][temp]-'A'+'a'==final[i][j])
				{
					dp[i][k][p]+=func(i+1,temp+1,0);
					dp[i][k][p]+=func(i,temp,j+1);
					temp++;
				}
			}
		}
		{
			// cout << i <<" "<<k<< " "<<p<<" "<<dp[i][k][p]<<endl;
			return dp[i][k][p];
		}
}

int main()
{
	while(1)
	{
			ll n;
			cin >> n;
			if(!n) break;

			for (int i = 0; i < n; ++i)
			{
				cin >> waste[i];
			}
			waste[n]="\0";
			ll i=0;
			getchar();
			for (i = 0; i < 1000000; ++i)
			{

	   			getline(cin,s[i]);
				if(s[i]=="LAST CASE")	break;
			}
			// for (ll q = 0; q < i; ++q)
			// {
			// 	cout << s[q]<<endl;
			// }
			for (int j = 0; j <i ; ++j)
			{
				ll x=0;
				ll prev=-1;
				for (int k = 0; k <s[j].length() ; ++k)
				{
					if(s[j][k]==' ')
					{
						if(prev==k-1)
						{
							prev=k;
						}
						else
						{
							x++;
							prev=k;
						}
					}
					else
					{
						prev=-1;
						temp[x].push_back(s[j][k]);
					}
				}
				x++;

				ll cnt=0;
				
				for (int k = 0; k < x; ++k)
				{
					ll flag=0;
					for (int p = 0; p <=n ; ++p)
					{
						if(temp[k]==waste[p])
						{
							flag=1;
						}
					}
					if(!flag)
					{
						final[cnt]=temp[k];
						cnt++;
					}
				}
				totalwords=cnt;
				totalchar=final[0].length();
				
				for (int m = 0; m <= totalwords+1; ++m)
				{
					for (int n = 0; n<=totalchar+1; ++n)
					{
						for (int z = 0; z <= 150; ++z)
						{
							dp[m][n][z]=-1;
						}
					}
				}
				ll ans=func(1,0,0);
				if(!ans)
				{
					cout <<final[0]<<" is not a valid abbreviation"<<endl;
				}
				else
				{
					cout <<final[0]<<" can be formed in "<<ans<<" ways"<<endl;
				}

				for (int k = 0; k < x; ++k)
				{
					temp[k].clear();
				}
			}
			
	}
	return 0;
}