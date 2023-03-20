#include <iostream>
#define swap(a, b) {int tmp=a; a=b; b=tmp;}
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a==b)cout<<0<<'\n';
    else cout<<b-a-1<<'\n';
    for(int i=a+1; i<b; i++){
        cout<<i<<' ';
    }
    return 0;
}