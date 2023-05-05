#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> li;
    list<char>::iterator it;
    int n;
    string text;
    cin>>n;
    while(n-->0){
        cin>>text;
        it=li.end();
        for(int i=0,l=text.length(); i<l; i++){
            switch (text[i]){
            case '<'://화살표
                if(li.size()>0 && it!=li.begin())it--;
                break;
            case '>'://화살표
                if(li.size()>0 && it!=li.end())it++;
                break;
            case '-'://백스페이스
                if(it!=li.begin())it=li.erase(--it);
                break;
            default: //숫자, 대문자, 소문자 입력
                li.insert(it, text[i]);
                break;
            }
        }
        for(it=li.begin(); it!=li.end(); it++)cout<<*it;
        cout<<'\n';
        li.clear();
    }
    return 0;
}