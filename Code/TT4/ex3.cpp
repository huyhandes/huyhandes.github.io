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

const char name[4]={'x','A','B','C'};

struct Stack{
    vector<string> disk_name;
};

Stack s[4];

void _push(string disk,int i){
    s[i].disk_name.push_back(disk);
}
void _pop(int i){
    s[i].disk_name.pop_back();
}

string _top(int i){
    return s[i].disk_name[s[i].disk_name.size()-1];
}

void printStack(int i){
    cout<<"Print from top to bottom of the tower "<<name[i]<<":\n";
    Ford(x,s[i].disk_name.size()-1,0)cout<<s[i].disk_name[x]<<'\n';
    cout<<"---------------------------------------------------\n";
}

void movedisk(int n,int a,int b){// Move n disk from column a to column b
    if(n==1){
        string S = _top(a);
        _push(S,b);
        _pop(a);
        cout<<"Move "<<_top(b)<<" from "<<name[a]<<" to "<<name[b]<<'\n';
        For(i,1,3)printStack(i);
        cout<<"*************************************************\n\n\n";
        return;
    }
    movedisk(n-1,a,6-a-b);
    movedisk(1,a,b);
    movedisk(n-1,6-a-b,b);
}

string toString(int a){
    string s="";
    while(a){
        s += char('0'+(a%10));
        a/=10;
    }
    return s;
}

int main(){
    int n,a,b;
    cout<<"Enter the number of disk:"; cin>>n;
    cout<<"Enter the starting column:"; cin>>a;
    cout<<"Enter the ending column:"; cin>>b;
    Ford(i,n,1){
        string s = "disk"+toString(i);
        _push(s,a);
    }
    cout<<"Note: the number of disk is the size of disk\n";
    printStack(a);
    movedisk(n,a,b);
    return 0;
}
