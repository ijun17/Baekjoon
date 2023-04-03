#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int tiles[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    tiles[0]=0;
    tiles[1]=1;
    tiles[2]=2;
    loop(i,3,n+1)tiles[i]=(tiles[i-1]+tiles[i-2])%10007;
    cout<<tiles[n];
    return 0;
}