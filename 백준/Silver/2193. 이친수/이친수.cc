#include <iostream>
using namespace std;

long long memo[2]={0,1};//0으로 끝나는거 / 1로 끝나는거
long long temp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=1; i<N; i++){
        temp=memo[0];
        memo[0]+=memo[1];
        memo[1]=temp;
    }
    cout<<memo[0]+memo[1];
    return 0;
}