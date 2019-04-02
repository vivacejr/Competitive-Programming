#include<bits/stdc++.h>
using namespace std;
struct G
{
	int a;
	int b;
	int c;
};
G ary[100000005];
int tree[100005];
long long int size[100005];

void intialize(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		tree[i]=i;
		size[i]=1;
	}
}

int root(int i)
{
	while(tree[i]!=i)
	{
		tree[i]=tree[tree[i]];
		i=tree[i];
	}
	return i;
}
int un(int i,int j)
{
	int rA=root(i);
	int rB=root(j);
	if(size[rA]>size[rB])
	{
		tree[rB]=rA;
		size[rA]+=size[rB];
	}
	else
	{
		tree[rA]=rB;
		size[rB]+=size[rA];
	}
}

bool cmp(G i,G j)
{
	return (i.c<j.c);
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int e;
		cin >> n;
		int x=0,y,cost	;
		char str[100];
		for (int i = 1; i <= n;++i)
		{	
			cin >> str;
			cin >> e ;
			while(e--)
			{
				x++;
				ary[x].a=i;
				cin>>y>>cost;
				ary[x].b=y;
				ary[x].c=cost;
				
			}
		}	
		intialize(n+1);
		sort(ary+1,ary+x+1,cmp);
		int flag=0;
		int sum=0;
		// for (int i = 1; i < x+1; ++i)
		// {
			// cout <<ary[i].a<<" "<<ary[i].b<<" "<< ary[i].c<<endl;
		// }
		for (int i = 1; i <x+1 &&flag<=n-1; ++i)
		{
			if( root(ary[i].a) != root(ary[i].b) )
				{
					un (ary[i].a,ary[i].b);
					flag ++;
					sum+=ary[i].c;
					// cout << sum<<endl;
			}
		}
		cout << sum << endl;
	}
}