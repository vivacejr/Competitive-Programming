#include<bits/stdc++.h>
using namespace std;

vector<vector <int> > M(200);
//vector<pair<int,int> >G(40000);
int D[200][200];
char str[200];
int n,m;
int bfs(int x,int y)
{
	queue<int > q;
	q.push(x);
	q.push(y);
	D[x][y]=0;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		int j=q.front();
		q.pop();
		int dist=D[i][j]+1;
		//left
		if(j-1>=0 && dist < D[i][j-1])
		{
			q.push(i);
			q.push(j-1);
			D[i][j-1]=dist;
		}
		//right
		if(j+1<m && dist < D[i][j+1])
		{
			q.push(i);
			q.push(j+1);
			D[i][j+1]= dist;
		}

		//up
		if(i-1>=0 && dist < D[i-1][j])
		{
			q.push(i-1);
			q.push(j);
			D[i-1][j]= dist;
		}

		//down
		if(i+1<n && dist < D[i+1][j])
		{
			q.push(i+1);
			q.push(j);
			D[i+1][j]= dist;
		}

	}
}

int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		vector<pair<int,int> > G;
		cin >> n >> m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char a;
				cin >> a;
				D[i][j]=500;
				if(a=='1')
				{
					D[i][j]=-1;

					G.push_back(make_pair(i,j));	//try without make pair also
				}
			}
		}
		for(int i=0;i<G.size();i++)
		{
			bfs(G[i].first,G[i].second);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout << D[i][j]<<" ";
			}
			cout << endl;

		}
	}
}
