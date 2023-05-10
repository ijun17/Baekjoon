#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,count=0;
    cin>>N;

    while(N--){
        string s;
        stack<char> st;
        cin>>s;
        for(int i=0, l=s.length(); i<l; i++){
            if(st.empty() || st.top()!=s[i])st.push(s[i]);
            else st.pop();
        }
        if(st.empty())count++;
    }
    cout<<count;
    return 0;
}