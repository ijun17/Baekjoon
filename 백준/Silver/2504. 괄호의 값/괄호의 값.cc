#include <iostream>
#include <stack>
using namespace std;
#define SML -1
#define BIG -2

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    stack<int> st;
    int sum;
    cin>>s;
    for(int i=0,l=s.length(); i<l; i++){
        sum=0;
        switch(s[i]){
        case '(':st.push(SML);break;
        case '[':st.push(BIG);break;
        case ')':
            while(!st.empty()&&st.top()>0){
                sum+=st.top();
                st.pop();
            }
            if(st.empty() || st.top()!=SML){
                cout<<0;
                return 0;
            }
            st.top()=(sum==0 ? 2 : sum*2);
            break; 
        case ']':
            while(!st.empty()&&st.top()>0){
                sum+=st.top();
                st.pop();
            }
            if(st.empty() || st.top()!=BIG){
                cout<<0;
                return 0;
            }
            st.top()=(sum==0 ? 3 : sum*3);
            break; 
        }
    }
    sum=0;
    while(!st.empty()&&st.top()>0){
        sum+=st.top();
        st.pop();
    }
    if(st.size()>0)cout<<0;
    else cout<<sum;
    return 0;
}