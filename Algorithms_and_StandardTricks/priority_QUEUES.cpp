#include<bits/stdc++.h>
using namespace std;
struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs; //opposite to normal comparator
    }
};

int main()
{
	priority_queue<int,vector<int>, CustomCompare > pq;
}