#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

char chess[50][50];

int getMinPaintCount(int sn, int sm){
    int count=0;
    loop(i,sn,sn+8)loop(j,sm,sm+8)if(chess[i][j]==((i+j)%2==0?'W':'B'))count++;
    return min(count,64-count);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    loop(i,0,N)loop(j,0,M)cin>>chess[i][j];
    int minCount=64;
    loop(i,0,N-7)loop(j,0,M-7)minCount=min(minCount,getMinPaintCount(i,j));
    cout<<minCount;
    return 0;
}