#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define X first
#define Y second

char board[25][25];
bool vis[25][25]={false,};
pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}};
int N;

int bfs(int x, int y){
    if(vis[x][y] || board[x][y]=='0')return 0;
    queue<pair<int,int>> Q;
    int count=0;
    Q.push({x,y});
    vis[x][y]=true;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        count++;
        for(int i=0; i<4; i++){
            int nx=cur.X+D[i].X;
            int ny=cur.Y+D[i].Y;
            if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
            if(vis[nx][ny] || board[nx][ny]=='0')continue;
            Q.push({nx,ny});
            vis[nx][ny]=true;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    
    vector<int> V;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int count=bfs(i,j);
            if(count>0)V.push_back(count);
        }
    }
    sort(V.begin(), V.end());
    cout<<V.size()<<'\n';
    for(int i=0,l=V.size(); i<l;i++)cout<<V[i]<<'\n';
    return 0;
}