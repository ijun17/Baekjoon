#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum=0;
    cin>>n;
    int A[n],B[n];
    loop(i,0,n)cin>>A[i];
    loop(i,0,n)cin>>B[i];
    sort(A,A+n);
    sort(B,B+n);
    loop(i,0,n)sum+=A[i]*B[n-1-i];
    cout<<sum;
    return 0;
}