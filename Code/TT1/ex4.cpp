#include<bits/stdc++.h>
using namespace std;

typedef struct Point{
    int x,y;
} point;
bool check(point a,point b){
    point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return abs(c.x * c.y );
}
long long area(point &a,point &b){
    point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    if(!check(a,b)){
        cout<<"Can't make a rectangle. Please enter the value again.\nEnter the value of first point :";
        cin>>a.x>>a.y;
        cout<<"Enter the value of second point :";
        cin>>b.x>>b.y;
        return area(a,b);
    }
    return abs((1ll*c.x)* c.y);
}
bool check_point(point &a,point &b,point c){
    if(a.x>b.x)swap(a.x,b.x);
    if(a.y>b.y)swap(a.y,b.y);
    if(a.x<=c.x && c.x<=b.x && a.y<=c.y && c.y<=b.y) return true;
    return false;
}
int main(){
    point a,b,c;
    long long S;
    cout<<"Enter the value of first point :";
    cin>>a.x>>a.y;
    cout<<"Enter the value of second point :";
    cin>>b.x>>b.y;
    S= area(a,b);
    cout<<"The area of rectangel is: "<<S<<'\n';
    cout<<"Enter the value of third point :";
    cin>>c.x>>c.y;
    cout<<"The answer for third point is: "<<check_point(a,b,c)<<'\n';
    return 0;
}
