/*
Number max: Find the maximum of two numbers without using any comparison operator
@author Arunabh Arnav
4:30pm
*/

/*Pre-examples and assumptions
 2 6
-2 2
 7 9
*/

/*Pre-constraints
*/

/*BST and Idea generation
2+6=8/2=4
c = abs(4-a (or b))
ans = c+4
*/

/*Shortcut cases
*/

/*Base cases and other constraints
*/

/*Code structure
*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){
    cout<<"Hi, Enter two numbers: \n";
    int m,n;
    float x,y,ans;
    cin>>m>>n;
    x=(m+n)/2.0;
    y=abs(x-m);
    ans=x+y;
    cout<<"The greater of the two numbers is: "<<ans;
    return 0;
}

/*Functional testing and risky cases
*/

/*Unit testing
4,5
x=4.5
y=.5
ans =4.5+0.5=4
*/
