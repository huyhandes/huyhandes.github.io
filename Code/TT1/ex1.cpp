#include<iostream>
using namespace std;

string add(string &a, string &b){
    string c = a + b;
    return c;
}

int main(){
    string a,b,c,d,*p1,*p2,*p;
    cout<<"Input string a: ";
    cin>>a;
    cout<<"\nInput string b: ";
    cin>>b;
    p1 = &a, p2= &b;
    c = add(a,b);
    d = *p1 + *p2;
    cout<<"\nThe addition of two string use references is :"<<c<<"\nThe addition of two string use pointer is :"<<d<<endl;
    return 0;
}
