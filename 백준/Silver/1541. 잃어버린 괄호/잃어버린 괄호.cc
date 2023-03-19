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
    int temp;
    bool minusFlag=false;
    char sign;
    int sum=0;
    loop(i,0,text.length()){
        if(text[i]=='+'||text[i]=='-'){
            sum+=stoi(num)*(minusFlag ? -1 : 1);
            if(text[i]=='-')minusFlag=true;
            num="";
        }else{
            num+=text[i];
            if(i==text.length()-1)sum+=stoi(num)*(minusFlag ? -1 : 1);
        }
    }
    cout<<sum;

    return 0;
}