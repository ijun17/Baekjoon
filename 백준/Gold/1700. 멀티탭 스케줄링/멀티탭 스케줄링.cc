#include <iostream>
#include <algorithm>
using namespace std;

int find(int* arr, int N, int num){
    int idx=-1;
    for(int i=0; i<N; i++)
        if(arr[i]==num)return i; 
        else if(arr[i]==-1)idx=i;
    return idx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K,n[100],k[100],ans=0;
    cin>>N>>K;
    fill(n,n+N,-1);
    for(int i=0; i<K; i++)cin>>k[i];
    for(int i=0; i<K; i++){
        int idx=find(n,N,k[i]);
        if(idx==-1){//콘센트 꽉참
            ans++;
            int maxID, maxTime=0;
            for(int j=0; j<N; j++){
                int time=1000;
                for(int a=i+1; a<K; a++){
                    if(n[j]==k[a]){
                        time=a;
                        break;
                    }
                }
                if(time>maxTime){
                    maxTime=time;
                    maxID=j;
                }
                if(time==1000)break;
            }
            idx=maxID;
        }
        n[idx]=k[i];
    }
    cout<<ans;

    return 0;
}