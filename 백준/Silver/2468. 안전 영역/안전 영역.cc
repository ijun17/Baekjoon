#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

typedef struct{int x,y;} Point;

int board[100][100];
bool vis[100][100];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    loop(i,0,N)loop(j,0,N){
        cin>>board[i][j]; //1~100
    }
    int count=0, maxCount=0;
    loop(h,1,101){
        queue<Point> Q;
        count=0;
        fill(&vis[0][0], &vis[N-1][N], false);
        loop(i,0,N)loop(j,0,N){
            if(vis[i][j] || board[i][j]<h)continue;
            count++;
            Q.push({i,j});
            vis[i][j]=true;
            while(!Q.empty()){
                Point cur=Q.front();Q.pop();
                loop(k,0,4){
                    int nx=cur.x+dx[k];
                    int ny=cur.y+dy[k];
                    if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
                    if(vis[nx][ny] || board[nx][ny]<h)continue;
                    Q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
        }
        if(count==0)break;
        maxCount=max(count, maxCount);
    }
    cout<<maxCount;
    return 0;
}