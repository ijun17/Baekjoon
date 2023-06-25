#include <iostream>
#include <algorithm>
using namespace std;

int memo[100001]={0,};
int maxV=0;
void setMemo(int w, int v){
    memo[w]=max(memo[w], v);
    maxV=max(maxV,v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K,W,V;
    cin>>N>>K;
    while(N--){
        cin>>W>>V;
        if(W>K || V==0)continue;
        for(int j=K; j>W; j--){
            if(memo[j-W]>0)setMemo(j,memo[j-W]+V);
        }
        setMemo(W,V);
    }
    cout<<maxV;
    return 0;
}