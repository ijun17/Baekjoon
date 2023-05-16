#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++)cin>>arr[i];
    sort(arr,arr+N,greater<int>());
    //for(int i=0; i<N; i++)cout<<arr[i]<<' ';
    int curr=0,sum=0;
    //n~2까지
    while(N-curr>1){
        if(arr[curr]>1 && arr[curr+1]>1){
            sum+=arr[curr]*arr[curr+1];
            curr+=2;
        }else break;
    }
    while(curr<N && arr[curr]>0){
        sum+=arr[curr];
        curr++;
    }
    int zeroCount=0;
    while(curr<N && arr[curr]==0){
        zeroCount++;
        curr++;
    }
    int minusCurr=N-1;
    while(minusCurr-curr>0){
        sum+=arr[minusCurr]*arr[minusCurr-1];
        minusCurr-=2;
    }
    if(minusCurr==curr && zeroCount==0)sum+=arr[minusCurr];
    cout<<sum;
    return 0;
}