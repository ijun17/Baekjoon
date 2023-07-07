#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)
#define MAX 1000000000

typedef struct _Point{
    int x,y;
    bool operator<(const _Point& p)const{
        if(y<p.y)return false;
        else if(y==p.y && x<p.x)return false;
        return true;
    }
} Point;

int board[20][20];
int dist[20][20];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    Point babyShark;

    loop(j,0,N)loop(i,0,N){
        cin>>board[i][j];
        if(board[i][j]==9)babyShark={i,j};
    }

    Point cur=babyShark;
    int size=2;
    int count=0;
    int ans=0;

    while(true){
        queue<Point> Q;
        priority_queue<Point> pq;
        int minDist=MAX;
        fill(&dist[0][0], &dist[N-1][N], MAX);
        Q.push(cur);
        board[cur.x][cur.y]=0;
        dist[cur.x][cur.y]=0;
        while(!Q.empty()){
            cur=Q.front(); Q.pop();
            loop(i,0,4){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == MAX && board[nx][ny] <= size){
                    Q.push({nx,ny});
                    dist[nx][ny]=dist[cur.x][cur.y]+1;
                    if(board[nx][ny]<size && board[nx][ny]!=0){
                        if(minDist==MAX)minDist=dist[nx][ny];
                        if(minDist==dist[nx][ny])pq.push({nx,ny});
                    }
                }
            }
        }
        if(pq.empty())break;
        else{
            cur=pq.top();
            board[cur.x][cur.y]=0;
            ans+=dist[cur.x][cur.y];
            if(++count==size){
                size++;
                count=0;
            }
        }
    }

    cout<<ans;

    return 0;
}