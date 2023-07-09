#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i=1; i<=N; i++){
        cin>>arr[i];
        for(int j=1,l=i/2; j<=l; j++){
            arr[i]=max(arr[i],arr[j]+arr[i-j]);
        }
    }

    cout<<arr[N];

    return 0;
}