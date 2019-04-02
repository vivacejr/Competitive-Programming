#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> p;
	p.push(10);
	p.push(5);
	p.push(7);
	priority_queue<int> temp=p;
	while(!temp.empty())
	{
		cout << temp.top()<<endl;
		temp.pop();
	}
}