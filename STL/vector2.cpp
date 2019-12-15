#include<iostream>
using namespace std;
#include<vector>

int main()
{
	vector<int> v1;
	vector<int> v2=v1;
	vector<int> v3(v2); //all 3 are same now

	// to declare a vector with fixed size 
	vector<int> Data(1000);				 // all 1000 intialized to zero
	vector<string> names(20, "Unknown"); 		 // all 20 have the word Unknown at the beginning

	//2-D
	vector < vector<int> > Matrix;
	int n,m;
	vector < vector<int> > M2(n ,vector<int>(m,-1)); //multi dimensional array of size n*m filled with -1 all over

}
