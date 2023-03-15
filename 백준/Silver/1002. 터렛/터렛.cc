#include <iostream>
#include <cmath>
#define loop(i,n) for(int i=0; i<n; i++)
using namespace std;

int getContact(double maxL, double L1, double L2){
    //최대값 세변 최대값구하긴
    double temp;
    if(maxL<L1){temp=maxL;maxL=L1;L1=temp;}
    if(maxL<L2){temp=maxL;maxL=L2;L2=temp;}

    if(maxL>L1+L2)return 0;
    else if(maxL==L1+L2)return 1;
    else return 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x1,y1,r1,x2,y2,r2;
    double distance;
    cin>>n;
    loop(i,n){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        distance=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        if(distance==0&&r1==r2){
            if(r1>0)cout<<-1<<'\n';
            else cout<<1<<'\n';
        }else cout<<getContact(distance, r1, r2)<<'\n';
    }
    return 0;
}