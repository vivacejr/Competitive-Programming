///great question

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > G(2);
int mx=0,n,m,coun=0;
vector<vector<int> > M(1005) ;
int dfs(int x,int y,int a)
{
	M[x][y]=5; ///nice trick to nt go back from where i came
	coun++;
	if(x+1<n&&M[x+1][y]==1)
	{
		dfs(x+1,y,a+1);
		if(a+1>mx)
		{
			mx=a+1;
		}

	}
	if(y+1<m&&M[x][y+1]==1)
	{
		dfs(x,y+1,a+1);
		if(a+1>mx)
		{
			mx= a+1;
		}

	}
	if(x-1>=0&&M[x-1][y]==1)
	{
		dfs(x-1,y,a+1);
		if(a+1>mx)
		{
			mx= a+1;
		}

	}
	if(y-1>=0&&M[x][y-1]==1)
	{
		dfs(x,y-1,a+1);
		if(a+1>mx)
		{
			mx= a+1;
		}
	}
	if(a>=mx)
	{
		mx=a;
		G[1].first=x;
		G[1].second=y;
	}
	M[x][y]=1; //2nd part of the nice trick

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{

		cin >> m >> n;
		mx=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char a;
				cin >>a;
				if(a=='#')
				{
					M[i].push_back(0);
				}
				else
				{
					M[i].push_back(1);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(M[i][j]==1)
				{
					G[0]=make_pair(i,j);
					break;

				}
			}
		}
		for(int i=0;i<2;i++)
		{
			int x =	G[i].first;
			int y = G[i].second;
			dfs(x,y,0);
		}
		cout <<"Maximum rope length is "<<mx<<"." << endl;
		G.clear();
		for(int i=0;i<n;i++)
		{
			M[i].clear();
		}
		G.clear();
	}
}
