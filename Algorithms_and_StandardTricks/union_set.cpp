#include<bits/stdc++.h>
using namespace std;
int Sum[1000];
int root(int ary[],int i)
{
	while(ary[i]!=i)
	{
		ary[i]=ary[ary[i]];
		i=ary[i];//**************************************
	}
	return i;
}

int union(int Ary[],int a,int b)
{
	int rA=root(Ary,a);
	int rB=root(Ary,b);
	if(Sum[rA]>Sum[rB])
	{
		Ary[rB]=rA;
		Sum[rA]+=Sum[rB];
	}
	else
	{
		Ary[rA]=rB;
		Sum[rB]+=Sum[rA];
	}
}
bool find(int a,int b)
{
	return root(a)==root(b) ? true : false;
}

int main()
{
		int n=10;
		for(int i=0;i<n;i++)
		{
			Ary[i]=i;
			Sum[i]=1;
		}

}