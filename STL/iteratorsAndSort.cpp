#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define all(c) c.begin(), c.end()

int main()
{
	vector<int> v(5);
	for(vector<int>::iterator it = v.begin() ; it < v.end() ; it++)
	{
		//it-v.begin() will give you the index
		//v.begin() is the first elements iterator 
		// *(iterator) will give you the element (much like pointers no ?)
		*it=- (it - v.begin());
	}

	vector<int>::iterator it ;
	for(it = v.begin() ;it != v.end() ; it ++)
	{
		cout << *it << " | " ;
	}
	cout << endl;
	//sort
	sort(all(v));
	for(it = v.begin() ;it != v.end() ; it ++)
	{
		cout << *it << " | " ;
	}
	cout<<endl;
	sort(v.rbegin(),v.rend());
	for(it = v.begin() ;it != v.end() ; it ++)
	{
		cout << *it << " | " ;
	}
}
