#include <iostream>
#include <stack>
using namespace std;

int arr[1000010];
int NGE[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    stack<int> st;
    cin>>N;
    for(int i=0;i<N; i++)cin>>arr[i];
    for(int i=N-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i])st.pop();
        if(st.empty())NGE[i]=-1;
        else NGE[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<N; i++)cout<<NGE[i]<<' ';
    return 0;
}