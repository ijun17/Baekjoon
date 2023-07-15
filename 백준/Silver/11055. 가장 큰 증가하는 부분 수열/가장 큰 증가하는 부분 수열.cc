#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int memo[1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>arr[i];

    int maxMemo=0;
    for(int i=0;i<N;i++){
        int maxNum=0;
        for(int j=i-1; j>=0; j--){
            if(arr[j]<arr[i] && maxNum<memo[j])maxNum=memo[j];
        }
        memo[i]=arr[i]+maxNum;
        maxMemo=max(maxMemo, memo[i]);
    }
    cout<<maxMemo;

    return 0;
}