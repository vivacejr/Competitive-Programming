#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > G(2005);
bool vis[2005];
vector<int> gen(2005);
int flag=0;
int dfs(int a,int b)
{
	vis[a]=1;
	gen[a]=b;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i]])
		{
			dfs(G[a][i],1-b);	
		}
		else
		{
			if(gen[a]==gen[G[a][i]])
			{
				flag=1;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	int temp=t;
	while(t--)
	{
		int n,e;
		flag=0;
		cin >> n >>e;
		while(e--)
		{
			int a,b;
			cin >> a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				dfs(i,1);
			}
		}
		if(flag)
		{
			cout <<"Scenario #"<<temp-t<<":\nSuspicious bugs found!"<<endl;
		}
		else
		{
			cout <<"Scenario #"<<temp-t<<":\nNo suspicious bugs found!" << endl;
		}
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			vis[i]=0;
		}
	}
}
