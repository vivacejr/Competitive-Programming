#include<bits/stdc++.h>
using namespace std;
bool vis[10005];
vector<int> dep(10005);
vector<vector<int> > G(10005);

int dfs(int a)
{
	vis[a]=1;
	int ans=0;
	int ma=0;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis[G[a][i]])
		{
			ans=1+dfs(G[a][i]);
			//	cout << a<<" " << G[a][i]<<" " << ans<<endl;
		}
		if(ans>ma)
		{
			ma=ans;;
		}
	}
	dep[a]=ma;
	return ma;
}
bool vis2[10005];
int m=0;
int dfs2(int a)
{
	int flag=0;
	vis2[a]=1;
	for(int i=0;i<G[a].size();i++)
	{
		if(!vis2[G[a][i]])
		{
			if(flag==1||dep[a]!=1+dep[G[a][i]])
			{
				if(dep[a]+1+dep[G[a][i]]>m)
				{
					m=dep[a]+1+dep[G[a][i]];
				}
			}
			if(dep[a]==1+dep[G[a][i]])
			{
				flag=1;
				if(G[a].size()==1)
				{
					if(dep[a]>m)
						m=dep[a];
				}

			}
			dfs2(G[a][i]);
		}
	}

}
int main()
{
	int nodes;
	cin >> nodes;
	for(int i=0;i<nodes-1;i++)
	{
		int a;
		int b;
		cin >> a;
		cin >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int root=1;
	dfs(root);
	dfs2(root);
	//	for(int i=1;i<=nodes;i++)
	//	{
	//		cout << dep[i] << " ";
	//	}
	//	cout << endl;
	cout << m<<endl;
}
