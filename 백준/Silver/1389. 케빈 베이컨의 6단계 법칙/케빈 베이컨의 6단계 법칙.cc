#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000

vector<int> user[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,a,b;
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        user[a].push_back(b);
        user[b].push_back(a);
    }
    int min_user,min_count=INF,bacon_count;
    for(int i=1; i<=N; i++){
        bacon_count=0;
        int dist[101];
        fill(dist,dist+101,INF);
        queue<int> Q;
        Q.push(i);
        dist[i]=0;
        while(!Q.empty()){
            int cur=Q.front(); Q.pop();
            for(int j=0,l=user[cur].size();j<l; j++){
                int nxt=user[cur][j];
                if(dist[nxt]==INF){
                    Q.push(nxt);
                    dist[nxt]=dist[cur]+1;
                    bacon_count+=dist[nxt];
                }
            }
        }
        if(min_count>bacon_count){
            min_user=i;
            min_count=bacon_count;
        }
    }
    cout<<min_user;
    return 0;
}