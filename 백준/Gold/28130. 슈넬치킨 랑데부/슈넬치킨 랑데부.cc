#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

typedef struct{int x,y;} Point;

char board[1000][1000];
int dist[1000][1000]={0,};
int dx[4]={1,0,-1,0}; 
int dy[4]={0,1,0,-1};
Point B;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    queue<Point> Q;
    loop(i,0,N)loop(j,0,M){
        cin>>board[i][j];
        if(board[i][j]=='A'){
            Q.push({i,j});
            dist[i][j]=0;
        }else if(board[i][j]=='B'){
            B={i,j};
            board[i][j]='.';
        }
    }
    while(!Q.empty()){
        Point cur=Q.front(); Q.pop();
        loop(i,0,4){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<0 || nx>=N || ny<0 ||ny>=M)continue;
            if(dist[nx][ny]>0 || board[nx][ny]!='.')continue;
            Q.push({nx,ny});
            dist[nx][ny]=dist[cur.x][cur.y]+1;
        }
    }

    Point cur=B;
    int time=1000000000,temp;
    for(int i=0,l=N*2+M*2-4; i<l; i++){
        temp=dist[cur.x][cur.y];
        if(temp>0){
            if(i==temp%l)time=min(time,temp);
            else if(temp<i && (i-temp)%2==0)time=min(time,i);
        }

        if(cur.y==0 && cur.x-1>=0 )cur.x--;
        else if(cur.x==N-1 && cur.y-1>=0 )cur.y--;
        else if(cur.y==M-1 && cur.x+1<N)cur.x++;
        else if(cur.x==0 && cur.y+1<M)cur.y++;
    }
    if(time==1000000000)cout<<-1;
    else cout<<time;

    return 0;
}