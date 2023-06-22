#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#define X first
#define Y second 
using namespace std;
#define loop(i,a,b) for(int i=a; i<b; i++)

char board[8][8];
pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}};
int N,M;

int BFS(queue<pair<int,int>> Q){
    bool vis[8][8]={false,};
    int countMove=0;
    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        loop(i,0,4){
            int nx=cur.X+D[i].X;
            int ny=cur.Y+D[i].Y;
            if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
            if(vis[nx][ny] || board[nx][ny]!='0')continue;
            Q.push({nx,ny});
            vis[nx][ny]=true;
            countMove++;
        }
    }
    return countMove;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q; //바이러스 큐
    vector<pair<int,int>> V; //빈공간 리스트
    cin>>N>>M;
    loop(i,0,N)loop(j,0,M){
        cin>>board[i][j];
        switch(board[i][j]){
            case '0': V.push_back({i,j}); break; //빈공간
            case '2': Q.push({i,j}); break;//바이러스
        }
    }

    const int size=V.size();
    int max_area=0;
    loop(i,0,size-2)loop(j,i+1,size-1)loop(k,j+1,size){
        board[V[i].X][V[i].Y]='1';
        board[V[j].X][V[j].Y]='1';
        board[V[k].X][V[k].Y]='1';
        max_area=max(size-BFS(Q)-3,max_area);
        board[V[i].X][V[i].Y]='0';
        board[V[j].X][V[j].Y]='0';
        board[V[k].X][V[k].Y]='0';
    }
    cout<<max_area;
    return 0;
}