/*
Intersection: given two straight line segments, find their point of intersection.
Input: four points
Output: one point
@author Arunabh Arnav
7:16pm
*/

/*BST
express lines in ax+by=c format and use the determinant form to solve the equation
next, check if the intersection point lies within both lines
*/

/*Potential errors
forgetting to check if lines are parallel
*/

/*Code structure
function to check whether the point lies within a given line
function to generate the point of intersection
function to generate coefficients
function to check parallel lines
pair<double,double>
main to call f2 and then f1
*/

#include<iostream>
#include<utility>
#include<stdlib.h>
using namespace std;

typedef pair<double,double> point;
double a1,a2,b1,b2,c1,c2;

bool isPartOfSegment(const point& x1,const point& x2,const point& x){
    double _x1,_x2,_y1,_y2;
    _x1 = x1.first - x.first;
    _x2 = x2.first - x.first;
    _y1 = x1.second - x.second;
    _y2 = x2.second - x.second;
    _x1/=abs(_x1);
    _x2/=abs(_x2);
    _y1/=abs(_y1);
    _y2/=abs(_y2);
    if(_x1*_x2<=0 && _y1*_y2<=0){
        return true;
    }
    return false;
}

void setFirstCoefficients(const point& p1,const point& p2){
    a1 = 1;
    b1 = -1*(p1.first - p2.first)/(p1.second - p2.second);
    c1 = p1.first - p1.second*(p1.first - p2.first)/(p1.second - p2.second);
}

void setSecondCoefficients(const point& p1,const point& p2){
    a2 = 1;
    b2 = -1*(p1.first - p2.first)/(p1.second - p2.second);
    c2 = p1.first - p1.second*(p1.first - p2.first)/(p1.second - p2.second);
}

bool areParallel(){
    return (a1*b2 - a2*b1 == 0);
}

point getIntersectionPoint(){
    point p;
    p.first = (c1*b2 - b1*c2)/(a1*b2-b1*a2);
    p.second = (a1*c2 - a2*c1)/(a1*b2-b1*a2);
    return p;
}

int main(){
    point p1,p2,p3,p4,p;
    cout<<"Enter the two points in x y x y format for Line 1: ";
    cin>>p1.first>>p1.second>>p2.first>>p2.second;
    cout<<"Enter the two points in x y x y format for Line 2: ";
    cin>>p3.first>>p3.second>>p4.first>>p4.second;
    setFirstCoefficients(p1,p2);
    setSecondCoefficients(p3,p4);
    cout<<"a1 = "<<a1<<" b1 = "<<b1<<" c1 = "<<c1<<endl;
    cout<<"a2 = "<<a2<<" b2 = "<<b2<<" c2 = "<<c2<<endl;
    if(areParallel()){
        cout<<"Lines are parallel\n";
    }else{
        p=getIntersectionPoint();
        if(isPartOfSegment(p1,p2,p) && isPartOfSegment(p3,p4,p)){
            cout<<"X="<<p.first<<" Y="<<p.second;
        }else{
            cout<<"Intersection point does not lie in the given line segments";
        }
    }
    return 0;
}
