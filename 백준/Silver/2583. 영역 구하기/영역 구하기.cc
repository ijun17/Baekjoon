#include <iostream>
#include <queue>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

typedef struct{int x,y;} Point;
bool board[100][100]={0,};
bool vis[100][100]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,N,K;
    cin>>M>>N>>K;
    while(K--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        loop(i,b,d)loop(j,a,c)board[i][j]=true;
    }
    priority_queue<int> pq;
    loop(i,0,M)loop(j,0,N){
        if(vis[i][j] || board[i][j])continue;
        int size=0;
        queue<Point> Q;
        Q.push({i,j});
        vis[i][j]=true;
        while(!Q.empty()){
            Point cur=Q.front(); Q.pop();
            size++;
            loop(k,0,4){
                int nx=cur.x+dx[k];
                int ny=cur.y+dy[k];
                if(nx<0 || nx>=M || ny<0 || ny>=N)continue;
                if(vis[nx][ny] || board[nx][ny])continue;
                Q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
        pq.push(-size);
    }
    cout<<pq.size()<<'\n';
    while(!pq.empty()){
        cout<<-pq.top()<<' ';
        pq.pop();
    }
    return 0;
}
