#include <iostream>
#include <cmath>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    long long x,y,distance,maxVel,accDistance,accTime,umt,umd;
    cin>>T;
    while(T-->0){
        cin>>x>>y;
        distance=y-x;
        maxVel=sqrt(distance); //가속 또는 감속하는 시간
        accDistance=maxVel*maxVel;//가속 또는 감속하는 거리
        accTime=2*maxVel-1;
        umt=(distance-accDistance)/maxVel;
        if((distance-accDistance)%maxVel>0)umt++;
        cout<<accTime+umt<<'\n';
    }   
    return 0;
}