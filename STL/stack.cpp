#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<int> myStack;
	//put an element on the top of the stack
	myStack.push(5);
	myStack.push(3);
	myStack.push(2);

	cout << "number of ints on the stack " << myStack.size() << "\n";

	while(!myStack.empty())
	{
		cout << "popping " << myStack.top()<< endl;
		//remove the topmost stack element
		myStack.pop();
	}

	cout << "number of ints on the stack " << myStack.size() << "\n";

}


