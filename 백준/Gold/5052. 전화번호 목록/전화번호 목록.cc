#include <iostream>
#include <algorithm>
using namespace std;

string arr[10000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        for(int i=0; i<N; i++)cin>>arr[i];
        sort(arr, arr+N);
        int i=0;
        for(; i<N-1; i++){
            if(arr[i].length()<arr[i+1].length()){
                int j=0,l=arr[i].length();
                for(; j<l; j++)
                    if(arr[i][j]!=arr[i+1][j])break;
                if(j==l)break;
            }
        }
        if(i==N-1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}