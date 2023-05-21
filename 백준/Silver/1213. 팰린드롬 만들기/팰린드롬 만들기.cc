#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,temp;
    int al[26]={0},middle=-1;
    cin>>s;
    for(int i=0; i<s.length(); i++) al[s[i]-'A']++;
    for(int i=0; i<26; i++){
        if(al[i]>0){
            if(al[i]%2==0){
                temp+=string(al[i]/2, char(i+'A'));
            }else{
                if(middle>=0){ //홀수개인 알파벳이 두개이상 존재
                    cout<<"I\'m Sorry Hansoo";
                    return 0;
                } else {
                    middle=i;
                    temp+=string(al[i]/2, char(i+'A'));
                }
            }
        }
    }
    cout<<temp;
    if(middle>=0)cout<<char(middle+'A');
    for(int i=temp.length()-1; i>=0; i--)cout<<temp[i];
    return 0;
}