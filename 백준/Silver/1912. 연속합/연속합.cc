#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tmp,sum=0,maxSum=-2000;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        sum+=tmp;
        if(maxSum<sum)maxSum=sum;
        if(sum<0)sum=0;
    }
    cout<<maxSum;
    return 0;
}