#include <iostream>
#include <algorithm>
using namespace std;

int arr[100100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0; i<N; i++)cin>>arr[i];
    sort(arr, arr+N);
    
    int s=0, e=N-1;
    int mins=0, mine=N-1;
    while(s<e){
        if(abs(arr[mins]+arr[mine])>abs(arr[s]+arr[e])){
            mins=s;
            mine=e;
        }
        if(arr[s]+arr[e]<0)s++;
        else e--;
    }
    cout<<arr[mins]<<' '<<arr[mine];
    return 0;
}