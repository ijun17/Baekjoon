#include <iostream>
using namespace std;

void cal(char a[50][50], int y, int x){
    for(int i=y; i<y+3; i++)
        for(int j=x; j<x+3; j++)
            a[i][j]=(a[i][j]=='0'?'1':'0');
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,count=0;//세로 가로
    char A[50][50],B[50][50];
    cin>>N>>M;
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>A[i][j];
    for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>B[i][j];

    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(A[i][j]!=B[i][j]){
                cal(A,i,j);
                count++;
            }
        }
        for(int j=M-2; j<M; j++){
            if(j>=0 && A[i][j]!=B[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    for(int i=N-2; i<N; i++)
        for(int j=0; j<M; j++)
            if(i>=0 && j>=0 && A[i][j]!=B[i][j]){
                cout<<-1;
                return 0;
            }

    cout<<count;
    return 0;
}