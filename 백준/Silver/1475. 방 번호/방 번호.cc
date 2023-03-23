#include <iostream>
#include <cmath>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string num;
    cin>>num;
    int plastic[9]={0,};
    int max=0;
    loop(i,0,num.length()){
        if(num[i]=='9')plastic[6]++;
        else plastic[(int)num[i]-(int)'0']++;
    }
    plastic[6]=ceil((float)plastic[6]/2);
    loop(i,0,9)if(max<plastic[i])max=plastic[i];

    cout<<max;
    return 0;
}