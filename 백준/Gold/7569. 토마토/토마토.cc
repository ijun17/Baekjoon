#include <iostream>
#include <queue>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++) 

typedef struct{
    int x;
    int y;
    int z;
} Point;

short board[100][100][100];
int dist[100][100][100]={0,};
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int M,N,H;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>H;
    queue<Point> Q;
    int count0=0;
    loop(k,0,H)loop(j,0,N)loop(i,0,M){
        cin>>board[i][j][k];
        if(board[i][j][k]==1){
            Q.push({i,j,k});
            dist[i][j][k]=1;
        }else if(board[i][j][k]==0)count0++;
    }
    int day=1;
    while(!Q.empty()){
        Point cur=Q.front(); Q.pop();
        loop(i,0,6){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            int nz=cur.z+dz[i];
            if(nx<0 || nx>= M || ny<0 || ny>=N || nz<0 || nz>=H)continue;
            if(dist[nx][ny][nz]>0 || board[nx][ny][nz]!=0)continue;
            Q.push({nx,ny,nz});
            dist[nx][ny][nz]=dist[cur.x][cur.y][cur.z]+1;
            day=dist[nx][ny][nz];
            count0--;
        }
    }
    if(count0==0)cout<<day-1;
    else cout<<-1;
    return 0;
}