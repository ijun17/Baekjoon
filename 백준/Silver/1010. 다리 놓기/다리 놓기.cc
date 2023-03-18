#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

unsigned long long comb(int n, int r){
    unsigned long long a=1;
    unsigned long long b=1;
    if(r<n-r){
        loop(i,n-r+1,n+1)a*=i;
        loop(i,1,r+1)b*=i;
    }else{
        loop(i,r+1,n+1)a*=i;
        loop(i,1,n-r+1)b*=i;
    }
return a/b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,N,M;
    cin>>T;
    while((T--)>0){
        cin>>N>>M;
        //서로다른 M개 중의 N개를 뽑는 경우
        cout<<comb(M,N)<<'\n';
    }
    return 0;
}