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

struct node{
    int key;
    node *nxt = NULL,*prev = NULL;
};
node *head, *tail;

void _push(int key){
    node *tmp = (node*)malloc(sizeof(node));
    if(head == NULL){
        tmp->key = key;
        tmp->nxt = tail;
        tmp->prev = head;
        head = tmp;
        tail = tmp;
        return;
    }
    tmp->key = key;
    tail->nxt = tmp;
    tmp->prev = tail;
    tail = tmp;
}

void _pop(){
    node *tmp = (node*)malloc(sizeof(node));
    if(tail == NULL)return;
    tmp = tail;
    tail = tail->prev;
    free(tmp);
}

bool isEmpty(){
    if (head== NULL)return 1;
    return 0;
}

int _front(){
    return head->key;
}
int _back(){
    return tail->key;
}

int main(){
    srand(time(NULL));
    int rd = rand() % 9 +1;
    _push(rd);
    while(_front() > 7){
        cout<<"You can't win this game. Game has been restart.\n";
        head->key = rand()%9 +1;
    }
    while(1){
        int rd = rand() %9 +1;
        while(rd == _front()) rd = rand() %9 +1;
        _push(rd);
        cout<<"Enter guess number";
        int g; cin>>g;
        if(_front() < g && g < _back()){
            cout<<"You win the game!\n";
            return 0;
        }
        cout<<_front()<<' '<<_back()<<'\n';
        _pop();
    }
    return 0;
}
