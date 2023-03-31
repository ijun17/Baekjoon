#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w,h,x,y,t;
    int dirX=1, dirY=1;
    cin>>w>>h>>x>>y>>t;
    x=w-abs((x+t)%(w*2)-w);
    y=h-abs((y+t)%(h*2)-h);
    cout<<x<<' '<<y;
    return 0;
}