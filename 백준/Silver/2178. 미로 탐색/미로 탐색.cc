#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

char board[100][100];
int dist[100][100];
queue<pair<int,int>> Q;
pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
            dist[i][j]=0;
        }
    }
    dist[0][0]=1;
    Q.push({0,0});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx=cur.X+D[i].X;
            int ny=cur.Y+D[i].Y;
            if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
            if(dist[nx][ny]>0 || board[nx][ny]=='0')continue;
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        } 
    }
    cout<<dist[N-1][M-1];
    return 0;
}