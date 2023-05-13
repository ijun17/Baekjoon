#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    int count=1;
    char temp=s[0];
    for(int i=0,l=s.length(); i<l; i++){
        if(temp!=s[i]){
            count++;
            temp=s[i];
        }
    }
    cout<<count/2;
    return 0;
}