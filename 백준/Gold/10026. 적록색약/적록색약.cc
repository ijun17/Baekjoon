#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

char board[100][100];
char board_RG[100][100];
bool vis[100][100]={false,};
bool vis_RG[100][100]={false,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N;

void BFS(char board[100][100], bool vis[100][100], int x, int y){
    queue<pair<int,int>> Q;
    char color=board[x][y];
    if(vis[x][y])return;
    Q.push({x,y});
    vis[x][y]=true;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0 || nx>=N || ny<0 ||ny>=N)continue;
            if(vis[nx][ny] || board[nx][ny] != color)continue;
            Q.push({nx,ny});
            vis[nx][ny]=true;
        }
    }
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
            board_RG[i][j]=(board[i][j]=='R' ? 'G' : board[i][j]);
        }
    }

    int count=0;
    int count_RG=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!vis[i][j]){
                count++;
                BFS(board, vis, i, j);
            }
            if(!vis_RG[i][j]){
                count_RG++;
                BFS(board_RG, vis_RG, i, j);
            }
        }
    }
    cout<<count<<'\n'<<count_RG;


    return 0;
}