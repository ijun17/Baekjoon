#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,N,l;
    cin>>M>>N;
    bool decimals[N+1]={0,};
    decimals[0]=1;
    decimals[1]=1;
    for(int i=2, l1=ceil(sqrt(N))+1; i<l1; i++){
        if(!decimals[i])for(int j=i*i, l2=N+1; j<l2; j+=i)decimals[j]=1;
    }

    for(int i=M, l=N+1; i<l; i++){
        if(!decimals[i])cout<<i<<'\n';
    }
    return 0;
}