#include<bits/stdc++.h>

using namespace std;

vector<vector <int> > G(10005);
bool vis[10005];

int dfs(int a,int p)
{
	vis[a]=1;
	int i;
	int flag=0;
	cout << a << endl;
	for(i=0;i<G[a].size()&&i<10;i++)
	{
		if(G[a][i]==p&&flag==0)
		{
			flag=1;
		}
		else
		{
			if(vis[G[a][i]]==1)
			{
				return 0;
			}
		}
		if(!vis[G[a][i]])
		{
			if(dfs(G[a][i],a)==0)
			{
				return 0;
			}
		}
	}
	if(i==G[a].size())
	{
		return 1;
	}


}

int main()
{
	int n;
	int e;
	int flag=0;
	cin >> n >> e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		if(a==b)
		{
			//cout << "NO" << endl;
			flag=1;
		}
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(flag==1)
	{
		cout << "NO" << endl;
		return 0;
	}
	int i=0;
	if(dfs(1,0)==0)
	{
		cout <<"NO" << endl;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cout << "NO"<<endl;
				break;
			}
		}
	}
	if(i==n+1)
	{
		cout << "YES" << endl;
	}
	//	for(i=1;i<=n;i++)
	//	{
	//		cout << vis[i] << " ";
	///	}
	//cout << endl;
	return 0;
}

