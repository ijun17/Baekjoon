#include <iostream>
using namespace std;
#define loop(i,s,e) for(int i=s;i<e;i++)

int arr[1024][1024];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    loop(x,0,N)loop(y,0,N){
        cin>>arr[x][y];
        if(x-1>=0)arr[x][y]+=arr[x-1][y];
        if(y-1>=0)arr[x][y]+=arr[x][y-1];
        if(x-1>=0 && y-1>=0)arr[x][y]-=arr[x-1][y-1];
    }
    int x1,y1,x2,y2;
    loop(i,0,M){
        cin>>x1>>y1>>x2>>y2;
        x1--;y1--;x2--;y2--;
        int ans=arr[x2][y2];
        if(x1-1>=0)ans-=arr[x1-1][y2];
        if(y1-1>=0)ans-=arr[x2][y1-1];
        if(x1-1>=0 && y1-1>=0)ans+=arr[x1-1][y1-1];
        cout<<ans<<'\n';
    }

    return 0;
}