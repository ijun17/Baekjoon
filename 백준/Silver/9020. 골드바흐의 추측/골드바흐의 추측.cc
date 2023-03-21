#include <iostream>
#include <cmath>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define MAX 10000
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool eratos[MAX]={0};
    eratos[0]=1;
    eratos[1]=1;
    for(int i=2,l=sqrt(MAX)+1; i<l; i++){
        if(!eratos[i])for(int j=i*i; j<MAX; j+=i){
            eratos[j]=1;
        }
    }

    int T,n;
    cin>>T;
    while(T-->0){
        cin>>n;
        for(int i=n/2; i>=2; i--){
            if(!eratos[i]&&!eratos[n-i]){
                cout<<i<<' '<<n-i<<'\n';
                break;
            }
        }
    }
    return 0;
}