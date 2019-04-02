#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<ll> >G(10000);
bool vis[1000];
stack<ll> S;


int dfs(ll a)
{
	vis[a]=1;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i]])
		{
			dfs(G[a][i]);
		}
	}
	S.push(a);

}

int main()
{
	ll n;
	cin >> n;
	ll e;
	cin >> e;
	for (int i = 0; i < e; ++i)
	{
		ll a,b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}
	cout << endl;
}
