#include <iostream>
#include <algorithm>
using namespace std;

int memo[3]={0,}, memo2[3]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,temp;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>temp;
        memo2[0]=max(memo[0],max(memo[1],memo[2]));
        memo2[1]=memo[0]+temp;
        memo2[2]=memo[1]+temp;
        memo[0]=memo2[0];
        memo[1]=memo2[1];
        memo[2]=memo2[2];
    }
    cout<<max(memo[0],max(memo[1],memo[2]));
    return 0;
}