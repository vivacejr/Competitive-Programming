#include<iostream>
using namespace std;
#include<vector>


void Print(vector<int> b)
{
	int i;
	for(int i = 0; i < b.size(); i++)
	{
		cout <<i<<"th: "<< b[i]<<endl;
	}
	cout << endl ;
}

int main()
{
	int i;
	//declares a vector of size 7 with type double
	vector<double> rainfall(7);
	
	//declare a vector of size 3 with type int
	vector<int> V(3);

	V[0] = 10;
	V[1] = 22;
	V[2] = 5;

	V[4]=9; 	//this doesnt work..  use resize for this to be done
	V.push_back(7); // this does

	cout << V.front() << endl;
	cout << V.back() << endl ;
	cout << V.at(2) << endl;

	Print(V);

	V.resize(20);
	for( i = 0 ; i < 20 ; i++)
	{
		V[i]=i*i;
	}

	V.resize(25);

	for( i = 0 ; i < 5 ; i++)
	{
		V.push_back(i+1); //writes elements to the index { 25 to 29 }
	}
	V[0]=100;
	//insert and erase??
	Print(V);

	V.resize(24);
	Print(V);

	V.clear(); //erases the container ( nots sets the elements to 0 but completely erases the container)
	cout << "After clearing \n";
	Print(V);


	return 0;
}
