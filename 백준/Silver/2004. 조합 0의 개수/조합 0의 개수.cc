#include <iostream>
#include <cmath>
using namespace std;

int numCntInFac(int a, int facNum){
    int count=0;
    if(facNum<2)return 0;
    int size=log(facNum)/log(a)+1;
    int arr[size]={0}; //a의 i 제곱수 중 a2의 개수
    int arr2[size]={1}; //a의 i 제곱
    for(int i=1; i<size; i++){
        arr[i]=arr[i-1]*a+1;
        arr2[i]=arr2[i-1]*a;
    }
    for(int i=size-1; i>=0; i--){
        if(facNum>=arr2[i]){
            count+=arr[i]*(facNum/arr2[i]);
            facNum-=arr2[i]*(facNum/arr2[i]);
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    int count2=numCntInFac(2,N)-numCntInFac(2,M)-numCntInFac(2,N-M);
    int count5=numCntInFac(5,N)-numCntInFac(5,M)-numCntInFac(5,N-M);
    cout<<(count2>count5 ? count5 : count2);
    //cout<<getNumCountInFac(5,N);
    
    //for(int i=0; i<126; i+=5)cout<<getNumCountInFac(5,i)<<'\n';
    //cout<<getNumCountInFac(5,50)<<'\n';
    return 0;
}