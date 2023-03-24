#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long S;
    cin>>S;
    cout<<floor((sqrt(1+8*S)-1)/2)<<'\n';
    return 0;
}