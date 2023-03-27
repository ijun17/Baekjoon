#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,N;
    cin>>T;
    long long num[11]={0,};
    num[1]=1;
    num[2]=2;
    num[3]=4;
    loop(i,4,11)num[i]=num[i-1]+num[i-2]+num[i-3];
    loop(i,0,T){
        cin>>N;
        cout<<num[N]<<'\n';
    }
    return 0;
}