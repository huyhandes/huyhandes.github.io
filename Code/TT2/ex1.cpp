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
    string key="";
    int data=0;
    node *nxt = NULL;
};

bool check(string a){
    for(int i=0;i<a.size();++i){
        int c = a[i]-'0';
        if(c<0 || c>9)return 0;
    }
    return true;
}
int inverse(string a){
    int s = 0;
    forw(i,0,a.size())
        s = s*10+int(a[i]-'0');
    return s;
}

node *head;

void addnode(string key,int data){
    node *cr;
    cr = head;
    while(cr != NULL){
        if(cr->key == key){
            cout<<"Car already added into the train\n";
            return;
        }
        cr = cr->nxt;
    }
    node *a = (node*)malloc(sizeof(node));
    a->key = key;
    a->data = data;
    a->nxt = head;
    head = a;
    cout<<"New car added to train\n";
}

void removenode(){
    if(head == NULL) {cout<<"All car doesn't contain any passenger removed successfully!";return;}
    node *current, *pre, *temp;
    current = head;
    while(head->data == 0){
        pre = head;
        head = head ->nxt;
        free(pre);
    }
    while(current != NULL){
        pre = current;
        current = current->nxt;
        while(current != NULL && current-> data == 0){
            temp = current;
            current = current -> nxt;
            free(temp);
        }
        pre->nxt = current;
    }
    cout<<"All car doesn't contain any passenger removed successfully!";
}

void prntnode(){
    int cnt=0;
    node *current, *temp;
    current = head;
    while(current != NULL){
        cnt++;
        temp = current;
        cout<<"The car "<<current->key<<" contain "<<current->data<<" passengers\n";
        current = current->nxt;
        free(temp);
    }
    cout<<"Length of train: "<<cnt<<'\n';
}

void input(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    For(i,1,n){
        cout<<"Enter name and the number of passenger of the car number "<<i<<'\n';
        string data;
        string key;
        cin>>key>>data;
        if(!check(data)){cout<<"Wrong input\n";return;}
        //cout<<data<<'\n';
        addnode(key,inverse(data));
    }
}

int main(){
    cout<<"Press 1 to add n car to database.\nPress 2 to remove all car dosen't contain any passenger.\nPress 3 to display all car and end program.\n";
    while(1){
        int choise;
        cin>>choise;
        if(choise == 1)input();
        if(choise == 2)removenode();
        if(choise == 3){prntnode();return 0;}
    }
    return 0;
}
