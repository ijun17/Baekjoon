#include <iostream>
#include <string>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string text;
    cin>>text;
    string num="";
    int sign=1;
    int sum=0;
    loop(i,0,text.length()){
        if(text[i]=='+'||text[i]=='-'){
            sum+=stoi(num)*sign;
            //마이너스 기호 뒤에 모든 수들이 마이너스면 최소값
            if(text[i]=='-')sign=-1;
            num="";
        }else{
            num+=text[i];
        }
    }
    sum+=stoi(num)*sign;;
    cout<<sum;
    return 0;
}