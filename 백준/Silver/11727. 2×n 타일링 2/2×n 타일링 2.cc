#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
using namespace std;

int tile[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    tile[1]=1;
    tile[2]=3;
    Loop(i,3,n){
        tile[i]=(tile[i-1]+tile[i-2]*2)%10007;
    }
    cout<<tile[n];
    return 0;
}