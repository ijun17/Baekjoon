#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool vis[1001];
stack<int> dfs;
queue<int> bfs;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,V;
    cin>>N>>M>>V;
    for(int i=0; i<M; i++){
        int n1, n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for(int i=0; i<=N; i++)sort(graph[i].begin(), graph[i].end());

    //DFS
    dfs.push(V);
    fill(vis, vis+1001, false);
    while(!dfs.empty()){
        int cur=dfs.top(); dfs.pop();
        if(vis[cur])continue;
        vis[cur]=true;
        cout<<cur<<' ';
        for(int i=graph[cur].size()-1; i>=0; i--){
            int node=graph[cur][i];
            if(vis[node])continue;
            dfs.push(node);
            //vis[node]=true;
        }
    }
    cout<<'\n';
    //BFS
    bfs.push(V);
    fill(vis, vis+1001, false);
    vis[V]=true;
    while(!bfs.empty()){
        int cur=bfs.front(); bfs.pop();
        cout<<cur<<' ';
        for(int node : graph[cur]){
            if(vis[node])continue;
            bfs.push(node);
            vis[node]=true;
        }
    }

    return 0;
}