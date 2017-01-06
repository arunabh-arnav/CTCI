/*
Given any integer, print an english phrase that describes the integer)"Ex: One thousand,two-hundred thirty four
*/

/*Pre-examples and assumptions
1 = one
11 = elevem
21 = twenty one
111 = one hundred eleven
121 = one hundred twenty one
1121 = one thousand twenty one
-1212 = minus one thousand two hundred twelve
*/

/*Pre-constraints
max should be limited to 9999, use int type
take special care of numbers below twenty
*/

/*BST and idea generation
first mod by 100:
case 1: remainder is <20 (use array)
case 2: remainder is >=20 (mod by 10  and div by 10 anad get those two values and preappend)
next keep modding by 10 and add to hundred, thousand prefixes...
*/

/*Shortcut cases
n<20
*/

/*Base cases and remaining constraints
n<0
do not forget to add the word zero
100 should not be, one hundred zero
junk numbers
*/

/*Code structure
function to return a string for tens and units place combined. tens and unit
function to return a string for hundreds place with checks
function to return a string for thousands place with checks
main: if the number is 0 then simply print zero and return. add a check that cin>> takes only a number
global vector to store the values of 0-19, 20,30,
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

string numbers[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
                "fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


string tensAndUnits(int num){
    if(num<=0)
        return "";
    string temp;
    if(num<=20){
        temp=numbers[num];
        return temp;
    }
    int tens = num/10;//23=2
    int units = num%10;//23=3
    temp=numbers[18+tens];
    if(units!=0){
        temp+=" "+numbers[units];
    }
    return temp;
}

string hundreds(int num){
    return numbers[num]+" hundred ";
}

string thousands(int num){
    string temp;
    if(num<=20){
        temp=numbers[num]+" thousand ";
        return temp;
    }
    int tens = num/10;//23=2
    int units = num%10;//23=3
    temp=numbers[18+tens];
    if(units!=0){
        temp+=" "+numbers[units];
    }
    return temp+" thousand ";
}

int main(){
    cout<<"Enter any number between -99999 to +99999: \n";
    long n;
    cin>>n;
    if(cin.fail()){
        cout<<"Not a number!";
        return -1;
    }
    if(n>99999 || n<-99999){
        cout<<"Number out of range!";
        return -1;
    }
    if(n==0){
        cout<<"Zero";
        return 0;
    }
    bool sign=false;
    if(n<0) sign=true;
    n=abs(n);// 1123
    int tens = n%100;//23
    n/=100;//11
    int hundred = n%10;//1
    n/=10;//1
    int thousand = n%100;//1
    string ans = tensAndUnits(tens);
    if(hundred>0) ans=hundreds(hundred)+""+ans;
    if(thousand>0) ans=thousands(thousand)+ans;
    if(sign) ans="minus "+ans;
    cout<<"The number in english is: "<<ans;
    return 0;
}



/*Functional testing and risky conditions
*/

/*Unit testing
*/
