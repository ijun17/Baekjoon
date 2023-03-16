#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,N;
    cin>>T;
    long long padovan[100]={1,1,1,2,2};
    loop(i,5,100)padovan[i]=padovan[i-1]+padovan[i-5];
    loop(i,0,T){
        cin>>N;
        cout<<padovan[N-1]<<'\n';
    }
    return 0;
}