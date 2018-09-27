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
    int key=-1,data=0;
    node *nxt = NULL;
};

node *head;

void addnode(int key,int data){
    node *nw = (node*)malloc(sizeof(node));
    if(head == NULL){
        cout<<"New term added\n";
        nw->key = key;
        nw->data = data;
        nw->nxt = head;
        head = nw;
        return;
    }
    if(head->key >key){
        cout<<"New term added\n";
        nw->key = key;
        nw->data = data;
        nw->nxt = head;
        head = nw;
    }
    else{
        node *cr, *pre;
        cr = head;
        pre = cr;
        while(cr != NULL && cr -> key < key){
            pre = cr;
            cr = cr->nxt;
        }
        if(cr == NULL){
            cout<<"New term added\n";
            nw->key = key;
            nw->data = data;
            nw->nxt = NULL;
            pre->nxt = nw;
            return;
        }
        if(cr->key > key){
            cout<<"New term added\n";
            nw->key = key;
            nw->data = data;
            nw->nxt = cr;
            pre->nxt = nw;
            return;
        }
        if(cr->key == key){
            cout<<"Index number found, coefficient added\n";
            cr->data += data;
        }
    }
}
void removenode(int key){
    if(head == NULL){
        cout<<"Index number dosen't exist\n";
        return;
    }
    node *cr, *pre;
    cr = head;
    pre = cr;
    while(cr != NULL && cr->key < key){
        pre = cr;
        cr = cr->nxt;
    }
    if(cr == NULL || cr->key != key){
        cout<<"Index number dosen't exist\n";
        return;
    }
    if(cr->key == key){
        cout<<"Index number has been removed from database!\n";
        pre->nxt = cr->nxt;
        free(cr);
    }
}

long long calculate(long long x){
    if(head == NULL)return 0;
    long long sum =0, xx=1ll;
    int cnt=0;
    node *cr;
    cr = head;
    while(cr != NULL){
        while(cnt < cr->key){
            cnt++;
            xx*=(1ll*x);
        }
        sum += (1ll*(cr->data))*xx;
        cr = cr->nxt;
    }
    return sum;
}

void display(){
    if(head == NULL){
        cout<<"No funtion\n";
        return;
    }
    node *cr;
    cr = head;
    while(cr != NULL){
        if(cr->nxt != NULL) cout<<cr->data<<"x^"<<cr->key<<" + ";
        else cout<<cr->data<<"x^"<<cr->key<<"\n";
        cr = cr->nxt;
    }
}

void freemem(){
    node *cr;
    while(head != NULL){
        cr = head;
        head = head->nxt;
        free(cr);
    }
    exit(0);
}

void input(){
    cout<<"Press 1 to add index number and coefficient to databse.\nPress 2 to remove a index number from database.\nPress 3 to show the polynomial function.\nPress 4 to compute the function.\nPress 5 to end program.\n";
    while(1){
        int choise;
        cin>>choise;
        if(choise == 1){
            int key,data;
            cout<<"Enter value of index number:";
            cin>>key;
            cout<<"Enter value of data:";
            cin>>data;
            addnode(key,data);
        }
        if(choise == 2){
            int key;
            cout<<"Enter value of index number:";
            cin>>key;
            removenode(key);
        }
        if(choise == 3)display();
        if(choise == 4){
            int x;
            cout<<"Enter the value of x:";
            cin>>x;
            cout<<"Result of the polynomial fuction: "<<calculate(x)<<'\n';
        }
        if(choise == 5)freemem();
    }
}

int main(){
    input();
    return 0;
}
