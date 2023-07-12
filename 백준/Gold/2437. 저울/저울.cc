#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i=0; i<N; i++)cin>>arr[i];
    sort(arr,arr+N);

    int sum=0,ans;
    for(int i=0; i<N; i++){
        if(sum+1<arr[i])break;
        sum+=arr[i];
    }
    ans=sum+1;
    cout<<ans;
    return 0;
}