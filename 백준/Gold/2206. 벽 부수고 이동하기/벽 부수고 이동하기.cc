#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define X first
#define Y second
#define loop2(i,j,N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)

char board[1000][1000];
int dist1[1000][1000]={0}; //0,0에서 N,M까지
int dist2[1000][1000]={0}; //N,M에서 0,0까지
pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}};
int N,M;

bool isMovable(int x, int y){
    return (x>=0 && x<N && y>=0 &&y<M && board[x][y]=='0');
}

void bfs(int x, int y, int dist[1000][1000]){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    dist[x][y]=1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx=cur.X+D[i].X;
            int ny=cur.Y+D[i].Y;
            if(isMovable(nx, ny) && dist[nx][ny]==0){
                Q.push({nx,ny});
                dist[nx][ny]=dist[cur.X][cur.Y]+1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M;
    loop2(i, j, N, M)cin>>board[i][j];
    bfs(0,0,dist1);
    bfs(N-1,M-1,dist2);

    const int MAX_D=1000*501;
    int minD=MAX_D;
    loop2(i, j, N, M)if(board[i][j]=='1'){
        int minD1=MAX_D;
        int minD2=MAX_D;
        for(int k=0; k<4; k++){
            int x=i+D[k].X;
            int y=j+D[k].Y;
            if(!isMovable(x, y))continue;
            if(dist1[x][y]>0 && minD1>dist1[x][y])minD1=dist1[x][y];
            if(dist2[x][y]>0 && minD2>dist2[x][y])minD2=dist2[x][y];
        }
        if(minD1!=MAX_D && minD2!=MAX_D && minD>minD1+minD2+1)minD=minD1+minD2+1;
    }
    if(minD==MAX_D && dist1[N-1][M-1]==0)cout<<-1;
    else if(dist1[N-1][M-1]==0) cout<<minD;
    else cout<<min(dist1[N-1][M-1], minD);

    return 0;
}