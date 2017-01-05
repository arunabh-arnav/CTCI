/*
@author Arunabh Arnav
CTCI Moderate question 2
Word frequencies: Find the frequency of a given word in a book. What if the program needs to be run multiple times?
4:24pm
*/

/*Examples
Book: (assuming book is represented as a vector of strings
"I go there ofter"
"let's go party"
"I like going out"
Word:
go; I
Answer:
2; 2
*/

/*Questions
Case sensitive? Y
whether to only include whole words? N
How is the book represented to us? Vector of strings
*/

/*Constraints
How many numbers in the array?: Assuming a vector so it does not matter
Method returns count
*/

/*BST and idea generation
[option 1] Scan left to right for whole word match in all lines of the book. O(n), O(1)
[option 2] (applicable if we only need to work with whole words) read words from book and place them in a hash table (unordered_map). Then read from it. O(n)[O(1)] O(n)
we can use advanced string matching algorithms from CLRS to improve the running time.
*/

/*Shortcut cases
~None
*/

/*Potential errors
delimiting words using spaces (which can be multiple) and newlines
*/

/*Base cases
Empty book: Answer = 0
Not found: Answer = 0
*/

/* Coding structure
function to create hash table ~~ input: book, output: hashtable - (whether to make it global or not)
function to return count of a word in every line of book ~~ input: word,line of book, output: count
function to return count using hash table ~~ input: word, output: count
function to loop through each line of the book and summaratively return the count ~~ input book, word, output:count
main function to input the book and the word
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
#include<string>
using namespace std;

/*
Function to create a hash table of words out of a book
@param book in vector of strings form
@return void, it sets a global hash table
*/

/*Risky conditions
whether the hash count while uninitialized is 0 or not
*/
unordered_map<string,int> wordsInBook; //global variable, we assume that the initial count is 0

void hashTheBook(vector<string> book){
    int n = book.size();
    string word;
    for(int i=0;i<n;i++){
//        cout<<"ola";
        stringstream ss(book[i]);
        while(getline(ss,word,' ')){
//            cout<<word<<".";
            wordsInBook[word]++;
        }
    }
    unordered_map<string,int>::iterator mi;
    for(mi=wordsInBook.begin();mi!=wordsInBook.end();mi++){
        cout<<mi->first<<" "<<mi->second<<endl;
    }
}

/*
Function to return the count of a word in a sentence
@param sentence
@param word
@return count of the word in the sentence
*/
int wordCount(string sentence,string word){
    stringstream ss(sentence);
    string temp;
    int count=0;
    while(getline(ss,temp,' ')){
        if(temp==word){
            count++;
        }
    }
    return count;
}

/*
Function to return the count of a given word in the hash table of the book
@param required word
@return count
*/
int getHashCount(string word){
    return wordsInBook[word];
}

/*
Function to loop through each line of the book and summaratively return the count
@param vector of strings (book)
@param given word
@return count
*/

int getTotalCount(vector<string> book,string word){
    int count=0;
    int n = book.size();
    for(int i=0;i<n;i++){
        count+=wordCount(book[i],word);
    }
    return count;
}

/*
Main function
Input the book and get the counts using both the methods and print both of them
*/

int main(){
    cout<<"Enter the lines of the book. When completed please press * \n";
    vector<string> book; string temp,nline,word;
    stringstream ss;
    getline(cin,temp,'*');
    ss.str(temp);
    while(getline(ss,nline)){
        book.push_back(nline);
    }
    for(int i=0;i<book.size();i++){
        cout<<book[i]<<endl;
    }
//Getting the count by option 1
    char c = 'n';
    hashTheBook(book);
    do{
    cout<<"Enter the word you want the count of ";
    cin>>word;
    int opt1Count = 0;
    opt1Count = getTotalCount(book,word);
//Getting the count by option 2
    int opt2Count = 0;
    opt2Count = getHashCount(word);
//Printing both counts
    cout<<"The count by option 1 is: "<<opt1Count<<"\nThe count by option 2 is: "<<opt2Count<<endl;
    cout<<"continue? (y/n): ";
    cin>>c;
    }while(c=='Y' ||c=='y');
    return 0;
}



