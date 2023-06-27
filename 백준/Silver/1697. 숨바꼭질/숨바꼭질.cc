#include <iostream>
#include <queue>
using namespace std;

int N, K, dist[100001]={0,};
queue<int> Q;

void setDist(int pos, int d){
    Q.push(pos);
    dist[pos]=d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    
    setDist(N,1);
    while(!Q.empty()){
        int cur=Q.front(); Q.pop();
        if(cur>0 && dist[cur-1]==0)setDist(cur-1,dist[cur]+1);
        if(cur<100000 && dist[cur+1]==0)setDist(cur+1,dist[cur]+1);
        if(2*cur<=100000 && dist[2*cur]==0)setDist(2*cur,dist[cur]+1);
    }
    cout<<dist[K]-1;
    return 0;
}