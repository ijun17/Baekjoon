#include <iostream>
using namespace std;

long long memo[1001]={0};//1~1000

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,A,mx,result=0;
    cin>>N;
    while(N--){
        cin>>A;
        mx=0;
        for(int i=1; i<A; i++){
            if(mx<memo[i])mx=memo[i];
        }
        memo[A]=mx+1;
        if(result<memo[A])result=memo[A];
    }
    cout<<result;
    return 0;
}