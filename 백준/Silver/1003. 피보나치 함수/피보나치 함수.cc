#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int memo0[41], memo1[41];
    memo0[0]=1;
    memo0[1]=0;
    memo1[0]=0;
    memo1[1]=1;
    loop(i,2,41){
        memo0[i]=memo0[i-1]+memo0[i-2];
        memo1[i]=memo1[i-1]+memo1[i-2];
    }
    int T,num;
    cin>>T;
    loop(i,0,T){
        cin>>num;
        cout<<memo0[num]<<' '<<memo1[num]<<'\n';
    }
    return 0;
}