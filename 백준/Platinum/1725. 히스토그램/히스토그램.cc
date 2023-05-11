#include <iostream>
#include <stack>
#define ull unsigned long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);    
    ull N;
    cin>>N;
    ull h;
    ull maxArea=0, area;
    stack<ull> hs;
    stack<ull> is;
    ull pos;
    for(ull i=0; i<N; i++){
        cin>>h;
        pos=i;
        while(!hs.empty() && hs.top()>h){
            pos=is.top();
            area=hs.top()*(i-pos);
            maxArea=(maxArea>area ? maxArea : area);
            hs.pop();
            is.pop();
        }
        if(h>0 && !(!hs.empty() && hs.top()==h)){
            hs.push(h);
            is.push(pos);
        }
    }
    while(!hs.empty()){
        area=hs.top()*(N-is.top());
        maxArea=(maxArea>area ? maxArea : area);
        hs.pop();
        is.pop();
    }
    cout<<maxArea<<'\n';
    
    return 0;
}