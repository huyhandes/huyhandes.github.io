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

long long multi(long long a,long long b){
    if(b == 0 || a == 0)return 0;
    if(b == 1) return a;
    if(a<0){
        a = -a;
        return - (a + multi(a,b-1));
    }
    if(b<0){
        b = -b;
        return - (a + multi(a,b-1));
    }
    return a + multi(a,b-1);
}

int main(){
    long long a,b;
    cout<<"Enter a and b value:\n";
    cin>>a>>b;
    cout<<multi(a,b);
    return 0;
}
