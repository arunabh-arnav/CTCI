/*
Smallest difference: Given two arrays of integers, find the pair of numbers,
one from each array that has the smallest (non-negative) difference.
Input: two integer arrays
Output: The smallest difference
*/

/*Examples and assumptions
Assuming that we need to return the absolute value of the smallest possible difference
and there is no order between the two arrays
1,4,2,6,7,8 + 3,1,5,1,6,3 --> 0 (1,1)
1,1,4,3 + 7,7,85,6,7 --> 2 (4,7)
*/

/*Pre-constraints
Sizes of the two arrays must be known
*/

/*BST and idea generation
Simple O(n*m) time solution: brute force, find min
Sorting does not help because of possible interleaving// 1 6 11 16  + 4 9 14 19 X
Sorting does help.
Sorted solution: sort the two arrays and then keep two pointers in each sorted array
Next, compare one element on the Left with one element on the Right, next move the pointer on the Right if
the next element on the Right gives a smaller difference. Note this difference and keep moving forward until no such
next element exists in the Right. at this point move to the next element in the Left array and repeat the procedure
process ends in the Right array when the last element has been reached OR the next element gives a larger difference
process ends in the Left arrat when the last element has been reached. return the minimum value obtained
*/

/*Shortcut cases
*/

/*Potential errors
Base cases of being at the end of the Right/Left arrays
Initial value for min
*/

/*Base cases and remaining constraints
Both arrays empty --> invalid
One array empty --> invalid
no movement when at the last element or we'd get an exception
input is an integer
*/

/*Code structure
function to calculate the minima
main function
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int minDifference(vector<int> Left,vector<int> Right){
    int min;
    int lsize = Left.size();
    int rsize = Right.size();
    sort(Left.begin(),Left.end());
    sort(Right.begin(),Right.end());
    for(int i=0;i<lsize;i++)
        cout<<Left[i]<<" ";
    cout<<"\n";
    for(int i=0;i<rsize;i++)
        cout<<Right[i]<<" ";
    cout<<"\n";
    min = abs(Left[0]-Right[0]);
    int j=0;
    for(int i=0;i<lsize;i++){
        for(;j<rsize-1;j++){
            if(abs(Left[i]-Right[j])<=min) // 1 6 11 16  + 4 9 11 19
                min = abs(Left[i]-Right[j]);
            if(abs(Left[i]-Right[j+1])<=abs(Left[i]-Right[j]))// if difference increases, j++, else i++
                {
                    if(abs(Left[i]-Right[j+1])<=min)min=abs(Left[i]-Right[j+1]);
                }
            else
                break;
        }
    }
    return min;
}

int main(){
    int lsize,rsize,temp;
    vector<int> Left;vector<int> Right;
    cout<<"Enter size of Left array and enter those many numbers: ";
    cin>>lsize;
    for(int i=0;i<lsize;i++){
        cin>>temp;
        Left.push_back(temp);
    }
    cout<<"Enter size of Right array and enter those many numbers: ";
    cin>>rsize;
    for(int i=0;i<rsize;i++){
        cin>>temp;
        Right.push_back(temp);
    }
    cout<<"The minimum difference found between the elements of the two arrays is: "<<minDifference(Left,Right);
    return 0;
}
