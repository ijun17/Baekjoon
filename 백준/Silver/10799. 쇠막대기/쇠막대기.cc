#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count=0;

    string s;
    stack<char> st;
    cin >> s;
    bool laser=false;
    for (int i = 0, l = s.length(); i < l; i++)
    {
        if (s[i] == '('){
            st.push(s[i]);
            laser=false;
        } else {
            st.pop();
            if(!laser){
                count+=st.size();
                laser=true;
            } else count++;
            
        }
    }
    cout<<count;

    return 0;
}