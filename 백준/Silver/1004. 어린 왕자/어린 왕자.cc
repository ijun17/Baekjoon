#include <iostream>
#include <algorithm>
#include <cmath>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
using namespace std;

float getDistance(int x1,int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,x1,y1,x2,y2,n,cx,cy,r,count=0;
    cin>>T;
    while(T-->0){
        count=0;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        loop(i,0,n){
            cin>>cx>>cy>>r;
            if((getDistance(x1,y1,cx,cy)<r)^(getDistance(x2,y2,cx,cy)<r))count++;
        }
        cout<<count<<'\n';
    }
    return 0;
}