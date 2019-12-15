#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;


const ll N=1e5+5,inf=1e18;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	set<ll> s;
	s.insert(40);	    
	s.insert(20);	    
	s.insert(10);
	s.insert(30);
	s.insert(40);	    
	s.insert(20);	    
	s.insert(10);
	s.insert(30);
	for(auto& it : s)
	{
		cout<<it<<endl;
	}	    

	set<pair<ll,ll> > s2;
	s2.insert(make_pair(1,12));
	s2.insert(make_pair(2,3));
	s2.insert(make_pair(1,11));
	s2.insert(make_pair(2,11));
	s2.insert(make_pair(1,12));
	s2.insert(make_pair(2,3));
	s2.insert(make_pair(1,11));
	s2.insert(make_pair(2,11));
	for(auto& it : s2)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}


	// to remove an element from set
	s.erase(40);
	s2.erase(make_pair(1,12));

	//to find an element in a set
	if(s.find(40)!=s.end())
	{
		cout<<"40 is  present"<<endl;
	}
	else
	{
		cout<<"40 is not present"<<endl;
	}
	if(s.find(30)!=s.end())
	{
		cout<<"30 is present"<<endl;
	}
	else
	{
		cout<<"30 is not present"<<endl;
	}

	// a set keeps only 1 occurence of each element
	// to keep multiple occurences we use multi set
	multiset<ll> ms;
	ms.insert(40);	    
	ms.insert(20);	    
	ms.insert(10);
	ms.insert(30);
	ms.insert(40);	    
	ms.insert(20);	    
	ms.insert(10);
	ms.insert(30);
	for(auto& it : ms)
	{
		cout<<it<<endl;
	}	    
	multiset<pair<ll,ll> > ms2;
	ms2.insert(make_pair(1,12));
	ms2.insert(make_pair(2,3));
	ms2.insert(make_pair(1,11));
	ms2.insert(make_pair(2,11));
	ms2.insert(make_pair(1,12));
	ms2.insert(make_pair(2,3));
	ms2.insert(make_pair(1,11));
	ms2.insert(make_pair(2,11));
	for(auto& it : ms2)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	//if you erase using ms.erase(40) all occurences of 40 will be removed
	// use ms.erase(ms.find(40)) instead 
	// set.find() returns the iterator of that element and erase removes the element that iterator points to
	return 0;
}