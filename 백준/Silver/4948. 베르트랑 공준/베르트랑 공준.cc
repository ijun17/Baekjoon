#include <iostream>
#include <cmath>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define MAX_NUM 246913
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool eratos[MAX_NUM]={0};
    eratos[0]=eratos[1]=1;
    int l1=sqrt(MAX_NUM)+1;
    loop(i,2,l1)if(!eratos[i])for(int j=i*i; j<MAX_NUM; j+=i)eratos[j]=1;

    int n,count;
    while(true){
        cin>>n;
        if(n==0)break;
        count=0;
        for(int i=n+1; i<=n*2; i++)if(!eratos[i])count++;
        cout<<count<<'\n';
    }
    return 0;
}