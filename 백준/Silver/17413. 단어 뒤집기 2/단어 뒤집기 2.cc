#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> st;
    string s;
    getline(cin,s);
    bool tag=false;
    for(int i=0,l=s.length(); i<l; i++){
        if(tag==true){
            cout<<s[i];
            if(s[i]=='>')tag=false;
        }else{
            if(s[i]==' ' || s[i]=='<'){
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                cout<<s[i];
                if(s[i]=='<')tag=true;
            }else{
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}