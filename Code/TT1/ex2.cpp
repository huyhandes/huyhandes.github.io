#include<bits/stdc++.h>
using namespace std;

int sum_up(vector<int> a){
    int sum=0;
    for(int i=0;i<a.size();++i)
        sum+=a[i];
    return sum;
}

int main(){
    vector<int> a;
    int n,*p,sum1,sum2=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    p = (int *) malloc(n * sizeof(int));
    a.resize(n+1);
    for(int i=0;i<n;++i){
        cout<<"\nEnter the " <<i+1<< " element: ";
        int x;
        cin>>x;
        a[i]=p[i]=x;
    }
    sum1 = sum_up(a);
    for(int i=0;i<n;++i)
        sum2+= p[i];
    cout<<"\nThe sum use references: "<<sum1<<"\nThe sum use references: "<<sum2<<'\n';
    return 0;
}
