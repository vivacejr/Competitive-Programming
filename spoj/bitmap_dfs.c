#include<bits/stdc++.h>
using namespace std;

//int D[205][205];
vector<vector<int> > D(205);
//vector<vector <int> > G(205);
int n,m;
bool vis[200][200];

int dfs(int x,int y,int a)
{
	vis[x][y]=1;
	D[x][y]=a+1;
	//	cout << x << " " << y<<endl;
	//	cout << a << endl;
	if(x+1<n&&D[x+1][y]>D[x][y]+1)
	{
		dfs(x+1,y,a+1);
	}
	if(y+1<m&&D[x][y+1]>D[x][y]+1)
	{
		dfs(x,y+1,a+1);
	}
	if(x-1>=0&&D[x-1][y]>D[x][y]+1)
	{
		dfs(x-1,y,a+1);
	}
	if(y-1>=0&&D[x][y-1]>D[x][y]+1)
	{
		dfs(x,y-1,a+1);
	}
	if(x+1<n&&vis[x+1][y]==0)
	{
		dfs(x+1,y,D[x+1][y]-1);
	}
	if(y+1<m&&vis[x][y+1]==0)
	{
		dfs(x,y+1,D[x][y+1]-1);
	}
	if(x-1>=0&&vis[x-1][y]==0)
	{
		dfs(x-1,y,D[x-1][y]-1);
	}
	if(y-1>=0&&vis[x][y-1]==0)
	{
		dfs(x,y-1,D[x][y-1]-1);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		vector<vector <int> >G(200);
		cin >> n >> m;
		int p,q;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				vis[i][j]=0;
			}
		}
		char str[200];
		for(int i=0;i<n;i++)
		{
			cin >> str;
			for(int j=0;j<m;j++)
			{
				G[i].push_back(48-str[j]);
				D[i].push_back(500);
				//D[i][j]=500;
				if(str[j]=='1')
				{
					D[i][j]=0;
					p=i;
					q=j;
				}
			}
		}
		dfs(p,q,-1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout << D[i][j] << " " ;
			}
			cout << endl;
		}
		cout << endl;
		for(int i=0;i<n;i++)
		{
			D[i].clear();
		}
	}
}
