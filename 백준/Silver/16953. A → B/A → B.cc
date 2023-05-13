#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B,count=0;
    cin>>A>>B;
    while(A<B){
        if(B%2==0)B/=2;
        else if(B%10==1)B/=10;
        else break;
        count++;
    }
    if(A==B)cout<<count+1;
    else cout<<-1;

    return 0;
}