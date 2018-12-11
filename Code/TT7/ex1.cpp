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
    int vertex;
    double weight;
    node *nxt = NULL;
};
bool check[7];
int inx[7];
node *Stack;
node *head[7];

void add(int st,int en,double val){
    node *a = (node*)malloc(sizeof(node));
    a->vertex = en;
    a->weight = val;
    a->nxt = head[st];
    head[st] = a;
}

void Sadd(node *a){
    a->nxt = Stack;
    Stack = a;
}
void fr(){
    node *cr = Stack;
    Stack = Stack->nxt;
}

void initEdge(char s,char d,double val){
    int st = int(s-'a');
    int en = int(d-'a');
    add(st,en,val);
    add(en,st,val);
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
    forw(i,0,7){
        cout<<"Started vertex: "<<char('a'+i)<<":\n";
        node *cr = head[i];
        while(cr!=NULL){
            cout<<"Adjacent vertex: "<<char('a'+cr->vertex)<<" and weight of edge is: "<<cr->weight<<'\n';
            cr = cr->nxt;
        }
        cout<<"***********************************\n";
    }
}
void printStack(){
    int i=0;
    while(Stack != NULL){
        inx[i++]=Stack->vertex;
        Stack = Stack->nxt;
    }
    Ford(i,6,0)cout<<char('a'+inx[i])<<' ';
}
void dfs(int cnt,double sum){
    if(cnt == 7){
        cout<<"Random visites: \n";
        printStack();
        cout<<"\nSum of weight on random path: "<<sum<<'\n';
        exit(0);
    }
    node *cr = Stack;
    check[cr->vertex] = true;
    node *st = head[cr->vertex];
    while(st!=NULL){
        int nxtvertex = st->vertex;
        if(!check[nxtvertex]){
            Sadd(st);
            sum+=st->weight;
            dfs(cnt+1,sum);
            sum-=st->weight;
            break;
        }
        else
            st = st->nxt;
    }
    fr();
    check[cr->vertex] = false;
}
/*
    I choose linked-list because it can save the memory.
    If I perfrom this maxtrix in array-base it will help me quicker to access the weight of edge between 2 vertices, but it take a lot of memmories.
*/


int main(){
    srand(time(0));
    memset(check,false,sizeof(check));
    initGraph();
    display();
    int x = rand()%7;
    node *a = (node*)malloc(sizeof(node));
    a->vertex = x;
    Sadd(a);
    dfs(1,0);
    return 0;
}
