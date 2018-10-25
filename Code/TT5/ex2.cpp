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
    int data;
    node *nxt =  NULL;
};


struct queueNode{
    node *head = NULL;
    queueNode *next = NULL;
};

queueNode *Lhead,*Ltail;

queueNode* init(int data){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = data;
    queueNode *newhead = (queueNode*)malloc(sizeof(queueNode));
    newhead->head = tmp;
    return newhead;
}

void push(queueNode *newhead){
    if(Lhead == NULL){
        Lhead = Ltail = newhead;
        return;
    }
    Ltail->next = newhead;
    Ltail = newhead;
}

queueNode* combine(queueNode *head1,queueNode *head2){
    queueNode *newhead =(queueNode*)malloc(sizeof(queueNode));
    node *h1 = head1->head, *h2 = head2->head, *cr;
    if(h1 == NULL){
        newhead->head = h2;
        return newhead;
    }
    if(h2 == NULL){
        newhead->head = h1;
        return newhead;
    }
    if(h1->data > h2->data){
        newhead->head = h2;
        h2 = h2->nxt;
    }
    else{
        newhead->head = h1;
        h1 = h1->nxt;
    }
    cr = newhead->head;
    while(h1 != NULL || h2 != NULL){
        if(h1 == NULL){
            cr->nxt = h2;
            cr = h2;
            h2 = h2->nxt;
            return newhead;
        }
        if(h2 == NULL){
            cr->nxt = h1;
            cr = h1;
            h1 = h1->nxt;
            return newhead;
        }
        if(h1->data > h2->data){
            cr->nxt = h2;
            cr = h2;
            h2 = h2->nxt;
        }
        else{
            cr->nxt = h1;
            cr = h1;
            h1 = h1->nxt;
        }
    }
    return newhead;
}

void mergesort(){
    if(Lhead == NULL){
        cout<<"No element to sort\n";
        return;
    }
    while(Lhead->next != NULL){
        queueNode *head1,*head2;
        head1 =  Lhead;
        Lhead = Lhead->next;
        head2 = Lhead;
        Lhead = Lhead->next;
        queueNode *newhead = combine(head1,head2);
        push(newhead);
    }
}

void printList(){
    node *cr,*prev;
    cr = Lhead->head;
    while(cr!=NULL){
        cout<<cr->data<<' ';
        prev = cr;
        cr = cr->nxt;
        free(prev);
    }
}
void reverseprintList(int n){
    node *cr,*prev;
    cr = Lhead->head;
    int *p = (int*)malloc(n*sizeof(int));
    int i=0;
    while(cr != NULL){
        p[i] = cr->data;
        prev = cr;
        cr = cr->nxt;
        free(prev);
        i++;
    }
    Ford(i,n-1,0)cout<<p[i]<<' ';
    cout<<'\n';
    free(p);
}

int main(){
    int n;
    cout<<"Enter quantity of array:";
    cin>>n;
    For(i,1,n){
        cout<<"\nEnter the value of element number "<<i<<' ';
        int x;
        cin>>x;
        push(init(x));
    }
    mergesort();
    char c;
    cout<<"Press < or > to choose the order.\n";
    cin>>c;
    bool x = int(c-'<')/2;
    if(x) reverseprintList(n);
    else printList();
    return 0;
}
