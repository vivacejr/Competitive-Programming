#include<iostream>
using namespace std;
#include<queue>

int main()
{
	queue<int> myQ;
	int i;
	for(int i = 0; i < 10 ; i++)
	{
		cout << " enqueing " << i << endl ;
		//inserts an element at the end of queue
		myQ.push(i);
	}


	cout << "Size of my queue: " << myQ.size() << endl;

	cout << "The back of myQ: " << myQ.back() << endl;

	while(!myQ.empty())
	{
		cout << " dequeuing " <<myQ.front() << endl ;
		myQ.pop();
	}

	cout << "Size of my queue: " << myQ.size() << endl;

}
