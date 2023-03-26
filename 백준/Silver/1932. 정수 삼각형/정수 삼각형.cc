#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int maxSum=0;
    int **tri;
    int n;
    cin>>n;
    tri = new int*[n];
    loop(i,0,n){
        tri[i]=new int[n];
        loop(j,0,i+1){
            cin>>tri[i][j];
            if(i>0){
                if(j==0)tri[i][j]+=tri[i-1][j];
                else if(i==j)tri[i][j]+=tri[i-1][j-1];
                else tri[i][j]+=(tri[i-1][j]>tri[i-1][j-1]?tri[i-1][j]:tri[i-1][j-1]);
            }
        }
    }
    for(int i=0,y=n-1;i<n;i++)if(maxSum<tri[y][i])maxSum=tri[y][i];
    cout << maxSum;

    for(int i=0; i<n; i++)delete[] tri[i];
    delete[] tri;
    return 0;
}