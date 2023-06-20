#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int tomatos[1000][1000];
queue<pair<int,int>> Q;
pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}};
int count=0;
int day=1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>M>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>tomatos[i][j];
            if(tomatos[i][j]==1)Q.push({i,j});
            else if(tomatos[i][j]==0)count++;
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx=cur.X+D[i].X;
            int ny=cur.Y+D[i].Y;
            if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
            if(tomatos[nx][ny]!=0)continue;
            Q.push({nx,ny});
            tomatos[nx][ny]=tomatos[cur.X][cur.Y]+1;
            if(tomatos[nx][ny]>day)day=tomatos[nx][ny];//날짜 갱신
            count--; //토마토 개수 갱신
        }
    }

    if(count>0)cout<<-1;
    else cout<<day-1;

    return 0;
}