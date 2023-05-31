#include <iostream>
using namespace std;

//14501

int memo[15]={0};//1일에서 최대 15일

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,T,P,maxP,result=0;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>T>>P;
        maxP=0;
        for(int j=0; j<i; j++)if(maxP<memo[j])maxP=memo[j];
        int endT=i+T-1;
        if(endT<N && memo[endT]<maxP+P){
            memo[endT]=maxP+P;
            if(memo[endT]>result)result=memo[endT];
        }
    }
    cout<<result;

    return 0;
}