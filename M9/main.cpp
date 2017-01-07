/*
Operations: Write methods to multiply, subtract and divide operations using only add operator. Assume that results are only integers.
@author Arunabh Arnav
6:18pm
*/

/*Pre-examples and assumptions
-3*4 = -12
-3/-3=1
12-(-9)=21
*/

/*Pre-constraints
*/

/*BST and idea generation
multiplication
x=-3, y=4
take absolute value
(loop y times, add x to itself : make sure that y is the positive term, if both are negative take abs of both and continue)
division
same preparation (abs)
next subtract x from y until result is less than equal to zero increment Quotient by oneusing subtraction function of this program]
subtraction
using multiply function developed in the program, in x-y, multiply y by -1 and add x and -y
*/

/*Shortcut cases
*/

/*Base cases and remaining constraints
*/

/*Code structure
function to multiply: records the sign and places the positive term on the iteration
function to subtract:
function to divide:
main
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int multiply(int x,int y){
    if(x<=0 && y<=0 || x>=0 && y>=0){ //both numbers have the same sign
        x=abs(x);
        y=abs(y);
    }
    else{
        if(x<y){
            int temp=x;
            x=y;
            y=temp;
         }
    }
    //Guaranteed that x is positive
    int ans=0;
    for(int i=0;i<x;i++){
        ans+=y;
    }
    return ans;
}

int subtract(int x, int y){
    return x+multiply(-1,y);
}

int divide(int x,int y){
    bool sign=false;
    if(x<=0 && y<=0 || x>=0 && y>=0){ //both numbers have the same sign
        x=abs(x);
        y=abs(y);
    }
    else{
        sign=true;
        x=abs(x);
        y=abs(y);
    }
    //Guaranteed that x is positive
    int ans=0;
    while(subtract(x,y)>=0){//--------5/3
        x=subtract(x,y);
        ans++;
    }
    if(sign) ans=multiply(-1,ans);
    return ans;
}

int main(){
    int x,y;char c;
    do{
        cout<<"Enter two numbers: \n";
        cin>>x>>y;
        cout<<"Difference is: "<<subtract(x,y);
        cout<<"\nProduct is: "<<multiply(x,y);
        cout<<"\nQuotient is: "<<divide(x,y);
        cout<<"\nContinue? (y/n): ";
        cin>>c;
    }while(c=='y');
    return 0;
}

/*Functional testing and risky conditions
*/

/*Unit testing
*/
