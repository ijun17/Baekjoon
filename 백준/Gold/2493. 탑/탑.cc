#include <iostream>
#include <stack>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,h;
    stack<int> hs; //높이
    stack<int> ps; //위치
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>h;
        while(!hs.empty() && hs.top()<h){
            hs.pop();   
            ps.pop();
        }
        if(hs.empty())cout<<"0 ";
        else cout<<ps.top()<<' ';
        hs.push(h);
        ps.push(i);
    }

    return 0;
}