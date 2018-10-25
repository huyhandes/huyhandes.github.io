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

bool comp(bool x,int a,int b){
    if(x)
        return a<=b;
    else
        return a>b;
}

void bubblesort(int s[],int n,bool x){
    int l=1,r=n;
    bool repeat = true;
    while(l<r && repeat){
        repeat = false;
        forw(i,l,r)
            if(comp(x,s[i],s[i+1])){
                swap(s[i],s[i+1]);
                repeat = true;
            }
        r--;
        forwd(i,r,l)
            if(comp(!x,s[i],s[i-1])){
                swap(s[i],s[i-1]);
                repeat = true;
            }
        l++;
    }
}

int main(){
    int n;
    cout<<"Enter the quantity of array:";
    cin>>n;
    int a[n+1];
    For(i,1,n){
        cout<<"Enter the value of element number "<<i<<'\n';
        cin>>a[i];
    }
    cout<<"Choose the order of sorted array. Press < or > to choose.\n";
    char c;
    cin>>c;
    bool x = int(c - '<')/2;
    bubblesort(a,n,x);
    For(i,1,n)
        cout<<a[i]<<' ';
    cout<<"\nIn the best case, complexity is O(n).\nIn the worst case, complexity is O(n*(n-1)/2) = O(n^2).\nThe average conplexity is (O(n)+O(n^2))/2 = O(n^2)\n";
    return 0;
}
