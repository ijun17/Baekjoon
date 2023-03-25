#include <iostream>
#include <cmath>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned short x;
    cin>>x;
    int count=0;
    for(int i=0; i<8; i++){
        if(x&1==1)count++;
        x=x>>1;
    }
    cout<<count;
    return 0;
}