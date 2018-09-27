#include<bits/stdc++.h>
using namespace std;

typedef struct Point{
    int x,y;
} point;

double _distance(point a, point b){
    point c;
    c.x= a.x -b.x;
    c.y= a.y -b.y;
    return sqrt(c.x*c.x + c.y*c.y);
}

int main(){
    point a,b;
    cout<<"Enter the value of first point :";
    cin>>a.x>>a.y;
    cout<<"Enter the value of second point :";
    cin>>b.x>>b.y;
    cout<<_distance(a,b);
    return 0;
}
