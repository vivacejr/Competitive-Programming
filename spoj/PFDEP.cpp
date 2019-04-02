#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs;
    }
};

vector<vector<ll> >G(10000);
bool vis[100005];
stack<ll> S;
priority_queue<ll,vector<ll>, CustomCompare > Q;
ll indeg[100005];
ll outdeg[100005];
ll must[100005]; 

ll bfs()
{
	while(!Q.empty())
	{
		ll temp=Q.top();
		cout << temp<<" ";
		Q.pop();
		for (int i = 0; i < G[temp].size(); ++i)
		{
			if(!vis[G[temp][i]]&&must[G[temp][i]])
			{
				indeg[G[temp][i]]--;
				if(!indeg[G[temp][i]])
				{
					Q.push(G[temp][i]);
					vis[G[temp][i]]=1;
				}
			}
		}
	}
}


int dfs(ll a)
{
	vis[a]=1;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i]])
		{
			dfs(G[a][i]);
		}
		if(must[G[a][i]]==1)
		{
			must[a]=1;
		}
	}
}


int main()
{
	ll t;
	cin >> t;
	while(t--)
	{	
		ll n;
		cin >> n;
		ll m;
		cin >> m;	
		for (int i = 1; i <= n; ++i)
		{
			ll k ;
			cin	>> k;
			cout << k << endl;
			for (int j = 0; j < k; ++j)
			{
				ll b;
				cin >> b;
				G[b].push_back(i);
				indeg[i]++;
				outdeg[b]++;
			}
		}
		cout << n << m << endl;
		for (int i = 0; i < m; ++i)
		{
			ll x;
			cin >> x;
			must[x]=1;
		}



		for (int i = 0; i <=n; ++i)
		{
			if(!vis[i]&&indeg[i]==0)
			{
				dfs(i);
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if(!vis[i]&&indeg[i]==0&&must[i])
			{
				Q.push(i);
				vis[i]=1;
			}
		}
		bfs();
		cout << endl;
	}
}
