#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int N,h,w;
    unsigned long long count=0;
    cin>>N;
    stack<unsigned int> hs; //높이
    stack<unsigned int> ws; //가중치
    while(N--){
        cin>>h;
        w=1;
        while(!hs.empty() && hs.top()<=h){
            count+=ws.top();
            if(hs.top()==h)w+=ws.top();
            hs.pop();
            ws.pop();
        }
        if(!hs.empty())count++;
        hs.push(h);
        ws.push(w);
    }
    cout<<count;
    return 0;
}