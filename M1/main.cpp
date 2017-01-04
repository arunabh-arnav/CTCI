/*
*Number swapper
*Write a function to swap a number in place
*/

// 142, 12  => 12, 142;
// 142+12 = 154, 142-12=130
// 2 no swapping, 4,5 swap, 1 0 swap.
// x = 142, y = 12;
// x = x+y = 154, y = 12
// y = x-y = 142
// x = 154
// x = x-y = 12

#include<iostream>
using namespace std;

void swap(int &x, int &y){
	x = x+y;
	y = x-y;
	x = x-y;
}

int main(int argv, char** args){
	int x,y;
	cin>>x>>y;
	swap(x,y);
	cout<<endl<<"x="<<x<<" y="<<y;
	return 0;
}

// Examples: -21 46
// x = -21+46 = 25
// y = 25-46 = -21
// x = 25--21 = 46
