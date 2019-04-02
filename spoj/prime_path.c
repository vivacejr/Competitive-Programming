#include<bits/stdc++.h>
using namespace std;
bool prime[10000];
//memset(prime,true,sizeof(prime));
bool vis[10000];

int level[10000];
int seive(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<=n;j+=i)
			{
				prime[j]=0;
			}	
		}
	}
}

int bfs(int a,int b)
{
	vis[a]=1;
	level[a]=0;
	queue<int> q;
	q.push(a);
	while(!q.empty())
	{
		int x=q.front();
		//		cout << x << endl;
		q.pop();
		//cout << x << " " ;
		//unit
		//	vis[x]=1;
		for(int i=0;i<=9;i++)
		{
			int c=(x-x%10)+i;
			if((vis[c]==0)&&prime[c]==1)
			{
				if(c==b)
				{
					return level[x]+1;
				}
				vis[c]=1;
				q.push(c);
				level[c]=level[x]+1;
			}			
		}
		//tens
		for(int i=0;i<=9;i++)
		{
			int c=(x-((x%100)/10)*10) + i*10 ;
			if((vis[c]==0)&&prime[c]==1)
			{
				if(c==b)
				{
					return level[x]+1;
				}
				q.push(c);
				vis[c]=1;
				level[c]=level[x]+1;	
			}	
		}
		//hundreds
		for(int i=0;i<=9;i++)
		{
			int c=(x-((x%1000)/100)*100) + i*100;
			if((vis[c]==0)&&prime[c]==1)
			{
				if(c==b)
				{
					return level[x]+1;
				}
				vis[c]=1;
				q.push(c);
				level[c]=level[x]+1;
			}
		}
		//thousands
		for(int i=1;i<=9;i++)
		{
			int c=(x%1000)+i*1000;
			if((vis[c]==0)&&prime[c]==1)
			{
				if(c==b)
				{
					return level[x]+1;
				}
				vis[c]=1;
				q.push(c);
				level[c]=level[x]+1;
			}
		}

	}
	return -1;
}


int main()
{
	for(int i=0;i<sizeof(prime);i++)
	{
		prime[i]=1;
	}
	int n=9999;
	seive(n);
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		if(a==b)
		{
			cout << "0" << endl;
			continue;
		}
		int ans=bfs(a,b);
		if(ans>=0)
			cout << ans << endl;
		else
		{
			cout << "Impossible" << endl;
		}
		for(int i=0;i<9999;i++)
		{
			vis[i]=0;
		}
	}
}
