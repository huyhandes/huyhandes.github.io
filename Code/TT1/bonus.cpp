#include<bits/stdc++.h>
using namespace std;
char change(int x){
    if(x==10)return 'X';
    return char('0'+x);
}
int main(){
    string s;
    int sum = 0;
    cout<<"Enter the book code: ";
    cin>>s;
    for(int i=0,j=1;i<s.size();i++){
        int c = s[i]-'0';
        if(c>=0 && c<10&& j<10){
                sum += c*j;
                j++;
        }
    }
    int x = sum%11;
    cout<<change(x)<<'\n';
    return 0;
}
