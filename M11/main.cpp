/*
Diving Board:
Input: the number of planks to be used. two types of planks, length=1,length=2
Output: All possible lengths formable by laying tha planks side by side
@author Arunabh Arnav
5:17pm
*/

/*Pre-examples and assumptions
1, 2
k=3
111
112
122
222
11
1
22
2
12
*/

/*Pre-constraints
*/

/*BST and idea generation
Basically we need to have combinations, of the small and big numbers we have exhausted all.
We can do this recursively.
if k=3
X----Y----Z

>> Option 1
in the Z step, we have two options, either take 1 and 2.
in the Y step, we can add both 1 and 2 to both the sums previously obtained. 11=2, 21=3, 12=3, 22
in the X step, we can again add both 1 and 2 to the sums previously obtained

--problem, we may get repetitions which are never good for business.

How to avoid duplicates? memoization, probably?
Take an hastable.
in the Z step we have two options, wither 1 or 2, these 1's and 2's become the sum
int the Y step, we need to find  method to know before hand that after having 21, there is no need to put 12 in there
    for that, 12.3, 13.2, 31.2 - there is no such way, you're gonna have ot look at the sum.
    so, we simply do not add the set if they give the same sum
in the step X we repeat the step.
*/

/*Shortcut cases
*/

/*Base cases and remaining constraints
Base cases: k=1
the case of full big and full small planks
*/

/*Code structure
function to input k and output the vector
main: input k and print the vector out
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,int> sums;

void getAllLengths(int k, int sum, int big, int small,vector<int>& repeats){
    if(repeats[k]==sum){
        return;
    }
    if(k==0){// Z
        sums[sum]=1;
        return;
    }
    getAllLengths(k-1,sum+small,big,small,repeats);
    getAllLengths(k-1,sum+big,big,small,repeats);
    repeats[k]=sum;
}

int main(){
    int big,small;
    cout<<"Enter big and small: ";
    cin>>big>>small;
    cout<<"Enter k ";
    int k;
    cin>>k;
    vector<int> repeats(k+1,-1);
    getAllLengths(k,0,big,small,repeats);
    unordered_map<int,int>::iterator mi;
    for(mi=sums.begin();mi!=sums.end();mi++){
        cout<<mi->first<<" ";
    }
    return 0;
}
/*Problems

How to find the last sums? so that we can add precisely to them? we can probably add them to to a struct as last or something
How to recurse and whoch information should be relevant to each tree of recursion
What to, and in what way to return the values?

*/


/*Mistakes made
recursion depth off by 1. i have one extra addition, in my version,, k=3 will work as k=4
How to recurse and whoch information should be relevant to each tree of recursion? passing the last sum in variables
What to, and in what way to return the values? 1. pass the hashmap as return type, or parentheses or global variables.
O(n) time estimation?
Forgot to add the return statement at the end of recursive base case

*/
