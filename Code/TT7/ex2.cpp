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

double weight[7][7];
bool check[7];
int inx[7];

struct node{
    int data;
    node *nxt;
};

node *head;

void add_node(int x){
    node *a = (node*)malloc(sizeof(node));
    a->data = x;
    a->nxt = head;
    head = a;
}
int top(){
    if(head == NULL)return -1;
    node *tmp = head;
    head = head->nxt;
    int x = tmp->data;
    free(tmp);
    return x;
}

void add(int st,int en,double val){
    weight[st][en] = weight[en][st]=val;
}

void initEdge(char s,char d,double val){
    int st = int(s-'a');
    int en = int(d-'a');
    add(st,en,val);
}

void initGraph(){
    initEdge('a','b',4);
    initEdge('a','c',8);
    initEdge('b','c',9);
    initEdge('b','d',8);
    initEdge('b','e',10);
    initEdge('c','d',2);
    initEdge('c','f',1);
    initEdge('d','e',7);
    initEdge('d','f',9);
    initEdge('e','f',5);
    initEdge('e','g',6);
    initEdge('f','g',2);
}
void display(){
    cout<<"Adjacency matrix\n-------------------------------\n";
    For(i,0,6){
        For(j,0,6)cout<<weight[i][j]<<' ';
        cout<<'\n';
    }
    cout<<"-----------------------------------\n";
}
void printStack(){
    int x = top();
    while(x!=-1){
        cout<<x<<' ';
        x = top();
    }
}
void dfs(int cnt,double sum,int v){
    if(cnt == 7){
        cout<<"Random visites: \n";
        printStack();
        cout<<"\nSum of weight on random path: "<<sum<<'\n';
        exit(0);
    }
    For(i,0,6)
        if(weight[v][i]>0 && check[i]==false){
            check[i]=true;
            sum+=weight[v][i];
            add_node(i);
            dfs(cnt+1,sum,i);
            check[i]=false;
            sum-=weight[v][i];
            top();
        }
}
/*
    I choose array-base because I can quickly access to the edge's weight.
*/


int main(){
    srand(time(0));
    memset(check,false,sizeof(check));
    memset(weight,0,sizeof(weight));
    initGraph();
    display();
    int x = rand()%7;
    check[x]=true;
    add_node(x);
    dfs(1,0,x);
    return 0;
}

