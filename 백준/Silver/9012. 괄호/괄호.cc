#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    while(N--){
        int count=0;
        string s;
        cin>>s;
        for(int i=0,l=s.length(); i<l; i++){
            if(s[i]=='(')count++;
            else if(count>0)count--;
            else {
                count=1;
                break;
            }
        }
        if(count==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}