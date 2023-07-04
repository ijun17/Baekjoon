#include <iostream>
#include <queue>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

typedef struct{int x,y;} Point;
int dist[300][300]={0,};
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, a, b, c, d;
    cin>>T;
    while(T--){
        cin>>N;
        fill(&dist[0][0], &dist[N-1][N], 0);
        cin>>a>>b>>c>>d;
        queue<Point> Q;
        Q.push({a,b});
        dist[a][b]=1;
        while(!Q.empty()){
            Point cur=Q.front(); Q.pop();
            if(cur.x==c && cur.y==d)break;
            loop(i,0,8){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
                if(dist[nx][ny]>0)continue;
                Q.push({nx,ny});
                dist[nx][ny]=dist[cur.x][cur.y]+1;
            }
        }
        cout<<dist[c][d]-1<<'\n';
    }
    return 0;
}
