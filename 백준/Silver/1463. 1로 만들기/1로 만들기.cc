#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    N++;
    int minCount;
    int* memo = new int[N];
    memo[2]=1;
    memo[3]=1;
    loop(i,4,N){
        minCount=10000000;
        if(i%3==0)minCount=min(minCount,memo[i/3]);
        if(i%2==0)minCount=min(minCount,memo[i/2]);
        minCount=min(minCount,memo[i-1]);
        memo[i]=minCount+1;
    }
    cout<<memo[N-1];
    delete[] memo;
    return 0;
}