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

stack<int>q;
int bot;

int main(){
    srand(time(NULL));
    int rd = rand() % 9 +1;
    q.push(rd);
    while(q.top() > 7){
        cout<<"You can't win this time.\nRestart the game.\n";
        q.top() = rand() %9 +1;
    }
    bot = q.top();
    while(1){
        int rd = rand() %9 +1;
        q.push(rd);
        cout<<"Enter guess number";
        int g; cin>>g;
        if(bot < g && g < q.top()){
            cout<<"You win the game!\n";
            return 0;
        }
        q.pop();
    }
    return 0;
}
