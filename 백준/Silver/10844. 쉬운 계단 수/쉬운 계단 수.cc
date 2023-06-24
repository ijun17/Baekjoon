#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long 
#define LIM 1000000000

ll memo[100][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    fill(memo[0],memo[0]+10,1);
    memo[0][0]=0;

    for(int i=1; i<N; i++){
        for(int j=1; j<9; j++){
            memo[i][j]=(memo[i-1][j-1]+memo[i-1][j+1])%LIM;
        }
        memo[i][0]=memo[i-1][1]%LIM;
        memo[i][9]=memo[i-1][8]%LIM;
    }
    ll sum=0;
    for(int i=0; i<10; i++){
        sum+=memo[N-1][i];
    }
    cout<<sum%LIM;
    return 0;
}