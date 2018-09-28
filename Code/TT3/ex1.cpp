#include<bits/stdc++.h>
using namespace std;

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define fi first
#define se second
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Ford(i,a,b) for(int i=a;i>=b;--i)
#define forw(i,a,b) for(int i=a;i<b;++i)
#define forwd(i,a,b) for(int i=a;i>b;--i)

stack<char> a;
string s;

void input(){
    getline(cin,s);
}

void process(){
    forw(i,0,s.size())
        a.push(s[i]);
}

void output(){
    while(!a.empty()){
        cout<<a.top();
        a.pop();
    }
    cout<<'\n';
}

int main(){
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    input();
    process();
    output();
    return 0;
}
