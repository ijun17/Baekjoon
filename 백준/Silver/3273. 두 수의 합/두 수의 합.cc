#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x,cnt=0;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)cin>>A[i];
    cin>>x;
    bool arr[2000001]={0};
    for(int i=0; i<n; i++){
        if(x>A[i] && arr[x-A[i]])cnt++;
        arr[A[i]]=true;
    }
    cout<<cnt;
    
    return 0;
}