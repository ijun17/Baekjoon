#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,R,G,B,sumR=0,sumG=0,sumB=0;
    cin>>N;
    cin>>sumR>>sumG>>sumB;
    loop(i,1,N){
        cin>>R>>G>>B;
        R+=min(sumG,sumB);
        G+=min(sumR,sumB);
        B+=min(sumR,sumG);
        sumR=R;
        sumG=G;
        sumB=B;
    }
    cout<<min(min(sumR,sumG),sumB);

    return 0;
}