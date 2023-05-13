#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,arr[100010];
    cin>>T;
    while(T--){
        int N,temp,count=0;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>temp;
            cin>>arr[temp];//서류성적으로 정렬
        }
        temp=2000000;
        for(int i=1; i<=N; i++){
            if(arr[i]<temp){
                count++;
                temp=arr[i];
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}