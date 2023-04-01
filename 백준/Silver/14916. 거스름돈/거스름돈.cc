#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a=n/5;
    int b=n%5;
    if(b%2==1){
        if(a>0){
            a-=1;
            b+=5;
        }else {
            cout<<-1;
            return 0;
        }
    }
    cout<<a+b/2;
    return 0;
}