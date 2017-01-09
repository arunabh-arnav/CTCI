/*
Living People:
Input: List of people with their birth and death years
Output: The year where maximum number of people were alive
@author Arunabh Arnav
3:21pm
*/

/*Pre-examples and assumptions
Datastructure:  array of struct
Examples:
A0 1900 1908
A1 1905 1906
A2 1990 2000
A3 1905 1908
A5 1903 1919
A6 1921 1947
Answer = 1905-1908 = 1905

Assumption if there are more than one year with the same number of people, output the first one in ascending order
*/

/*Pre-constraints
All years must lie withitn 1900-2000 period only
A person with 1908-1909 will be included in both 1908 and 1909 because he was alive in both of these years. (Inclusive)
*/

/*BST and idea generation
>> Brute force
for each row in the structure, taking index as the start and end year, increment the count of an array or hashmap that holds all the years
In the end, return the one with max count. O(n*k) where k is the average longevity, Space coplexity: O(100)
>> instead of adding one in all numbers in the range just increment the start and end should have the same effect, as we have to return a single year.
this should not affect thre result in any manner. But for this, we need to sort the intervals based on birth year. Then, if the previous death date is >=
the birth year, add 1 to the + previous count on the birth year and so on. Time O(nlgn) Space (O(n))
**************************
  **********
    ***************
              ********
                 **************


*/

/*Shortcut cases
*/

/*Base cases and remaining constraints
>> one input: return the birth year
>> no intersections: return the minimum one
>> verify that the years lie between 1900 and 2000
>> No need to store any names
*/

/*Code structure
struct b,d
global array 0-100
function to set the array up
function to determine the max of the array
main
*/

#include<iostream>
#include<vector>
using namespace std;

struct times{
    int b;
    int d;
    };
vector<int> century(101,0); //initializing one hundred elements with zeros

void storePopulationData(vector<times>& census){
    int n= census.size();
    for(int i=0;i<n;i++){
        for(int j=census[i].b;j<=census[i].d;j++){
            century[j%1900]++;
        }
    }
}

int getBestYear(){
    int max=0,year;
    for(int i=0;i<=100;i++){
        if(century[i]>max){
            max=century[i];
            year=i;
        }
    }
    return 1900+year;
}

int main(){
    int n;
    vector<times> census;
    cout<<"How the nuber of people followed by their birth and death years: ";
    cin>>n;
    for(int i=0;i<n;i++){
        times pers;
        cin>>pers.b>>pers.d;
        census.push_back(pers);
    }
    storePopulationData(census);
    cout<<"The year "<<getBestYear()<<" had the most number of people alive.";
    return 0;
}
/*Functional testing and risky conditions
--> Less than equal to condition in the array handling and storage
--> vectors between 0 and 100 must be initialzed and stored with zeros
*/

/*Unit testing
*/
