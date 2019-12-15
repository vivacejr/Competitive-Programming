#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int ,string> M;
	M[1] = "Dobi ";
	M[2] = "harry ";
	M[3] = "albus ";
	M[4] = "emma ";
	M[5] = "snape ";
	M[6] = "lord ";

	cout << M[3] << endl;

	M[4]= "dumbledor";
	cout << M[4] << endl;

	map<string,int> M2;
	M2["Jon"] = 51;
	M2["Snow"] = 52;
	M2["Rob"] = 23;
	M2["Stark"] = 34;

	cout<<M2["Stark"]<<endl;

	return 0;
}
