#include<bits/stdc++.h>
using namespace std;

int numberOfDivisors[1000010];
vector<int> divv[1000010];


int main()
{
	for (int i = 1; i <n; ++i)
	{
		for (int j = i; j <n ; j+=i)
		{
			numberOfDivisors[j]++;			
			divv[j].push_back(i);
		}
	}	
}