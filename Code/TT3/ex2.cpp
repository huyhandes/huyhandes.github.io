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
queue<string> q;
string name;
int main(){
    cout<<"Press 1 to add people to queue.\nPress 2 to get 1 people enter.\nPress 3 to end program.\n";
    while(1){
        cout<<"Enter your choise\n";
        int choise;
        cin>>choise;
        if(choise == 1){
            cout<<"Enter name of next person\n";
            cin>>name;
            //getline(cin,name);
            q.push(name);
        }
        if(choise == 2){
            cout<<q.front()<<"entered the train\n";
            q.pop();
        }
        if(choise == 3)return 0;
    }
    return 0;
}
