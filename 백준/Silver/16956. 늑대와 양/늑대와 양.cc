#include <iostream>
#include <queue>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

typedef struct{int x,y;} Point;

char board[500][500];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int R,C;
queue<Point> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    loop(i,0,R)loop(j,0,C){
        cin>>board[i][j];
        if(board[i][j]=='.')board[i][j]='D';
        else if(board[i][j]=='W')Q.push({i,j});
    }
    while(!Q.empty()){
        Point cur=Q.front(); Q.pop();
        loop(i,0,4){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<0 || nx>=R || ny<0 || ny>=C)continue;
            if(board[nx][ny]=='S'){
                cout<<0;
                return 0;
            }
        }
    }
    cout<<1<<'\n';
    loop(i,0,R){
        loop(j,0,C){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    return 0;
}