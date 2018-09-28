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
    string name;
    node *nxt = NULL,*prev = NULL;
};
node *head, *tail;
void _push(string name){
    node *tmp = (node*)malloc(sizeof(node));
    if(head == NULL){
        tmp->name = name;
        tmp->nxt = tail;
        tmp->prev = head;
        head = tmp;
        tail = tmp;
        return;
    }
    tmp->name = name;
    tail->nxt = tmp;
    tmp->prev = tail;
    tail = tmp;
}

void _pop(){
    node *tmp = (node*)malloc(sizeof(node));
    if(head == NULL)return;
    tmp = head;
    head = head->nxt;
    free(tmp);
}

string _front(){
    if(head == NULL)return "No one in the queue\n";
    return head->name;
}

void prt(){
    while(head != NULL){
        cout<<head->name<<'\n';
        head = head->nxt;
    }
}

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
            _push(name);
        }
        if(choise == 2){
            //prt();
            cout<<_front()<<" entered the train\n";
            _pop();
        }
        if(choise == 3)return 0;
    }
    return 0;
}
