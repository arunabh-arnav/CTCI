/*
Factorial Zeros: Compute the number of trailing zeros in a given number
Input: a positive integer
Output: the number of zeros in its factorial
@author Arunabh Arnav
1:29am
*/

/*Examples and assumptions
4! = 24  -> 0
5! = 120 -> 1
10! = 10*9! -> 2
15! = 15*14! -> 3
20! = 19!*20 -> 4
25! = 24!*5*5 --> 6
*/

/*Pre-constraints
~None
*/

/*BST and idea generation
FInd the number of 5's powers in a number.
Check the highest power of 5 lesser/equal to N
number of zeros = N/5+N/25+N/125+....
*/

/*Shortcut cases
~None
*/

/*Potential errors
~None
*/

/*Base cases and remaining constraints
number cannot be negative
*/

/*Code structure
Main program: until the pow(5,i) ceases to be greater than N, keep adding it to the sum
*/
#include<iostream>
#include<math.h>
using namespace std;

int main(){
int n,count=0;
cout<<"Enter the number\n";
cin>>n;
int i=1;
while(pow(5,i)<=n){
    count+=n/pow(5,i);
    i++;
}
return count;
}


/*Functional testing and risky conditions
*/

/*Unit testing
n=0 --> 0
n=26 --> 6
*/
