#include <iostream>
using namespace std;

int stair;
int memo[3]={0};
int temp[3]={0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>stair;
        temp[0]=max(memo[1],memo[2]);
        temp[1]=memo[0]+stair;
        temp[2]=memo[1]+stair;
        memo[0]=temp[0];
        memo[1]=temp[1];
        memo[2]=temp[2];
    }
    cout<<max(memo[1],memo[2]);
    return 0;
}