#include <iostream>
#define loop(i,n) for(int i=0; i<n; i++)
using namespace std;



int main(){
    int M,N;
    cin>>M>>N;
    int sum=0;
    int min=0;
    int temp;
    bool decimals[N+1]={0,};
    decimals[0]=1;
    decimals[1]=1;
    for(int i=2; i<N; i++ ){
        if(decimals[i]==0)for(int j=2; j<N; j++){
            temp=i*j;
            if(temp<=N){
                decimals[temp]=1;
            }else break;
        }   
    }

    for(int i=M; i<=N; i++){
        if(decimals[i]==0){
            sum+=i;
            if(min==0)min=i;
        }
    }
    if(min==0)cout<<-1;
    else cout<<sum<<'\n'<<min;
    return 0;
}