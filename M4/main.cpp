/*
Tic-tac-win: Figure out who won a game of tic-tac-toe
Input: a 2-d array or vector
Output: X wins, O wins, draw or invalid
@author Arunabh Arnav
10:15pm
*/

/*Examples & assumptions
input could be in array/vector of characters or 1s and 0s.
output bool
XXX
OXO
XOO
X wins
XXO
OOO
XXX
invalid
*/

/*Pre-constraints
The size of 2-d array must be 3x3 or result in an error
Character inputs of 'X' or 'O'. anything else must result in error
Can there be both wins. declare invalid tic tac toe game.
*/

/*BST and idea generation
two kinds of movements: sequential or specific.
check all grids horizontally first, vertically next and diagonally last. Return the output based on results.
*/

/*Shortcut cases
~None
*/

/*Potential errors
Ensuring that the game is valid.
*/

/*Base case and remaining constraints
Can the grid be incomplete?:Yes. allow blank spaces.
*/

/*Coding structure
function to perform all scans
function to validate the grid
main: input a 2-d array.
*/


#include<iostream>
#include<stdlib.h>
using namespace std;
const int m=3,n=3;

void scanGrid(char grid[][3]){
    int xCount=0,oCount=0;
//  Horizontal scan
    for(int i=0;i<3;i++){
        if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]){
            if(grid[i][0]=='X')
                xCount++;
            else if(grid[i][0]=='O')
                oCount++;
        }
    }
//  Vertical scan
    for(int i=0;i<3;i++){
        if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]){
            if(grid[0][i]=='X')
                xCount++;
            else if(grid[0][i]=='O')
                oCount++;
        }
    }
//  Diagonal scan
    if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]){
        if(grid[0][0]=='X')
            xCount++;
        else if(grid[0][0]=='O')
            oCount++;
    }
    if(grid[2][0]==grid[1][1] && grid[1][1]==grid[0][2]){
        if(grid[1][1]=='X')
            xCount++;
        else if(grid[1][1]=='O')
            oCount++;
    }
//  Results
    if(xCount>0 && oCount>0)
        cout<<"Invalid game";
    else if(xCount>0)
        cout<<"X wins";
    else if(oCount>0)
        cout<<"O wins";
    else
        cout<<"Game drawn";
}

bool checkGameValidity(char grid[][3]){
    int xCount=0,oCount=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(grid[i][j]=='X')
                xCount++;
            else if(grid[i][j]=='O')
                oCount++;
            else if(grid[i][j]=='_');
            else return false;
        }
    cout<<"X's="<<xCount<<" O's="<<oCount<<endl;
    if(abs(xCount-oCount)<=1)
        return true;
    else return false;
}

int main(){
    cout<<"Enter a 3x3 array of X's and O's or _ for blank\n";
    char grid[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    if(checkGameValidity(grid))
        scanGrid(grid);
    else
        cout<<"Invalid game";
    return 0;
}


/*Functional testing
risky variables
risky conditoins
*/
