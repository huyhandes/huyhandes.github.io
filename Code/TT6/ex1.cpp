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
    int _max, _maxleft;
};
int n;

node *p;

void init(int _size){
    p = (node*)malloc(_size*sizeof(node));
}

node calculate(int _size,int pos){
    if(pos>=_size) return p[pos];
    node left = calculate(_size,2*pos);
    node right = calculate(_size,2*pos+1);
    p[pos]._max = max(left._max , right._max);
    p[pos]._maxleft = left._max;
    return p[pos];
}

void NLR(int pos,int _size){
    cout<<p[pos]._maxleft<<' ';
    if(pos>=_size)return;
    NLR(2*pos,_size);
    NLR(2*pos+1,_size);
}

void LNR(int pos,int _size){
    if(pos>=_size){
        cout<<p[pos]._maxleft<<' ';
        return;
    }
    LNR(2*pos,_size);
    cout<<p[pos]._maxleft<<' ';
    LNR(2*pos+1,_size);
}

void LRN(int pos,int _size){
    if(pos>=_size){
        cout<<p[pos]._maxleft<<' ';
        return;
    }
    LRN(2*pos,_size);
    LRN(2*pos+1,_size);
    cout<<p[pos]._maxleft<<' ';
}

int main(){
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cout<<"Enter the quantity of element in array: ";
    cin>>n;
    int _size = (1<<int(ceil(log2(n)))),x;
    init(2*_size);
    forw(i,_size,_size+n){
        cout<<"Enter the element number"<<i-_size+1<<": ";
        cin>>x;
        p[i]._max = p[i]._maxleft = x;
    }
    forw(i,_size+n,2*_size){
        p[i]=p[_size+n-1];
    }
    calculate(_size,1);
    cout<<"The NLR order:";
    NLR(1,_size);
    cout<<"\nThe LNR order:";
    LNR(1,_size);
    cout<<"\nThe LRN order:";
    LRN(1,_size);
    free(p);
    return 0;
}
