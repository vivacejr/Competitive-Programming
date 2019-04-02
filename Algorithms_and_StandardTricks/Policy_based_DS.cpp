#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front



int main(){
	
	pbds A;
	
    //Add elements in any random order
    A.insert(11);
	A.insert(1);
    A.insert(5);
	A.insert(3);
	A.insert(7);
	A.insert(9);
	A.insert(3);
	
	//Total contents
	cout << "1, 3, 5, 7, 9, 11" << endl;
	
	
	//K-th smallest
	int k = 3;
	cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
	
	k = 5;
	cout << k << "th smallest: " << *A.find_by_order(k-1) << endl;
	
	
	//NO OF ELEMENTS < X
	int X = 9;
	
	cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
	
	//DELETE Elements
    cout << "Deleted 3" << endl;
    A.erase(3);
    
    //Total contents
	cout << "1, 5, 7, 9, 11" << endl;
	
    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
    
    //NEXT BIGGER/SMALLER ELEMENT than X
    X = 8;
    
    cout << "Next greater element than " << X << " is " << *A.upper_bound(X) << endl;
    cout<<A.size()<<endl;
	
	return 0;
}