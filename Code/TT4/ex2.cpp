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
    int data=0;
    node *nxt = NULL;
};

node *head;

void addnode(int data){
    node *nw = (node*)malloc(sizeof(node));
    nw->data = data;
    nw->nxt = head;
    head = nw;
}
void removenode(int data){
    if(head == NULL)return;
    if(head->data == data){
        node *tmp = (node*)malloc(sizeof(node));
        tmp = head;
        head = head->nxt;
        free(tmp);
        return;
    }
    node *cr, *pre;
    cr = head;
    pre = cr;
    while(cr != NULL && cr->data != data){
        pre = cr;
        cr = cr->nxt;
    }
    if(cr == NULL) return;
    if(cr->data == data){
        pre->nxt = cr->nxt;
        free(cr);
    }
}

long long calculate(node *cr){
    if(cr == NULL) return 0;
    return cr->data + calculate(cr->nxt);
}

void freemem(){
    node *tmp = (node*)malloc(sizeof(node));
    while(head != NULL){
        tmp = head;
        head = head->nxt;
        free(tmp);
    }
    exit(0);
}

int main(){
    cout<<"Press 1 to add data to linked list.\nPress 2 to remove a node have input data.\nPress 3 to calculate sum of all element in linked list.\nPress 4 to exit program.\n";
    while(1){
        int choise;
        cin>>choise;
        if(choise == 1){
            int data;
            cin>>data;
            addnode(data);
        }
        if(choise == 2){
            int data;
            cin>>data;
            removenode(data);
        }
        if(choise == 3){
            cout<<"The sum of all element in linked list is:"<<calculate(head)<<'\n';
        }
        if(choise == 4)freemem();
    }
    return 0;
}
