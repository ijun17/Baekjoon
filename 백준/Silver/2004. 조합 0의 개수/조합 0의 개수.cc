#include <iostream>
#include <cmath>
using namespace std;

int numCntInFac(int num, int fac){
    int count=0;
    if(fac<2 || num<2)return 0;
    int size=log(fac)/log(num)+1;
    int arr[size]={0}; //(a^i)! 중 a의 개수
    int arr2[size]={1}; //a^i
    for(int i=1; i<size; i++){
        arr[i]=arr[i-1]*num+1;
        arr2[i]=arr2[i-1]*num;
    }
    for(int i=size-1; i>=0; i--){
        if(fac>=arr2[i]){
            count+=arr[i]*(fac/arr2[i]);
            fac-=arr2[i]*(fac/arr2[i]);
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
    return 0;
}