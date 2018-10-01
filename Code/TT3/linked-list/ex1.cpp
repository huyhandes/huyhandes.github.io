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
    char chr;
    node *nxt = NULL,*prev = NULL;
};
node *head, *tail;
int __size = 0;
void _push(char chr){
    node *tmp = (node*)malloc(sizeof(node));
    if(head == NULL){
        tmp->chr = chr;
        tmp->nxt = tail;
        tmp->prev = head;
        head = tmp;
        tail = tmp;
        __size++;
        return;
    }
    tmp->chr = chr;
    tail->nxt = tmp;
    tmp->prev = tail;
    tail = tmp;
    __size++;
}

void _pop(){
    node *tmp = (node*)malloc(sizeof(node));
    if(tail == NULL)return;
    tmp = tail;
    tail = tail->prev;
    free(tmp);
    __size--;
}

bool isEmpty(){
    if (head == NULL)return 1;
    return 0;
}

char _top(){
    return tail->chr;
}

int _size(){
    return __size;
}

int main(){
    string s;
    getline(cin,s);
    forw(i,0,s.size())
        _push(s[i]);
    while(__size){
        cout<<_top();
        _pop();
    }
    return 0;
}
