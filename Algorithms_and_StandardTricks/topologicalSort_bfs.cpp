#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<vector<ll> >G(10000);
bool vis[1000];
stack<ll> S;
queue<ll> Q;
ll indeg[1000];

ll bfs()
{
	while(!Q.empty())
	{
		ll temp=Q.front();
		cout << temp<<" ";
		Q.pop();
		for (int i = 0; i < G[temp].size(); ++i)
		{
			if(!vis[G[temp][i]])
			{
				indeg[G[temp][i]]--;
				// cout <<G[temp][i]<< endl;
				if(!indeg[G[temp][i]])
				{
					Q.push(G[temp][i]);
					vis[G[temp][i]]=1;
				}
			}
		}
	}
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
		indeg[b]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if(indeg[i]==0)
		{
			Q.push(i);
			vis[i]=1;
		}
	}
	bfs();
	cout << endl;
}
