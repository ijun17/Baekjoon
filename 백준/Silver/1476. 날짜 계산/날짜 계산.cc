#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int E,S,M,Y;
    cin>>E>>S>>M;
    int sTemp=0;//Y=sTemp*28+S
    while(true){
        if((28*sTemp+S-E)%15==0&&(28*sTemp+S-M)%19==0){
            Y=sTemp*28+S;
            break;
        }
        sTemp++;
    }
    cout<<Y;
    return 0;
}