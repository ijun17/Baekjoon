#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

typedef struct{int x,y;} Point;

char board[50][50];
bool vis[50][50];
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int W,H,count=0;
        cin>>W>>H;
        if(W==0 && H==0)break;
        fill(&vis[0][0], &vis[W-1][H], false);
        loop(j,0,H)loop(i,0,W)cin>>board[i][j];
        loop(i,0,W)loop(j,0,H){
            if(vis[i][j] || board[i][j]=='0') continue;
            count++;
            queue<Point> Q;
            Q.push({i,j});
            vis[i][j]=true;
            while(!Q.empty()){
                Point cur=Q.front(); Q.pop();
                loop(k,0,8){
                    int nx=cur.x+dx[k];
                    int ny=cur.y+dy[k];
                    if(nx<0 || nx>=W || ny<0 || ny>=H)continue;
                    if(vis[nx][ny] || board[nx][ny]=='0')continue;
                    Q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}