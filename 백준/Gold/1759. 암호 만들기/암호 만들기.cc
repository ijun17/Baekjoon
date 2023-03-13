#include <iostream>
#include <algorithm>
#define loop(i,n) for(int i=0; i<n; i++)
using namespace std;

bool isVowel(char c){return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');}

void printPassword(string text, int pwLength, string pw="", int lastIndex=-1, int vowelCount=0){
    if(pw.length()==pwLength){
        if(vowelCount>0 && pwLength-vowelCount>1)cout<<pw<<'\n';
    }else{
        for(int i=lastIndex+1,l=text.length()-(pwLength-pw.length())+1; i<l; i++)
            printPassword(text, pwLength, pw+text[i], i, vowelCount+isVowel(text[i]));
    }
}

int main(){
    int L,C;
    cin>>L>>C;
    string text;
    char temp;
    loop(i,C){
        cin>>temp;
        text+=temp;
    }
    sort(text.begin(), text.end());
    printPassword(text, L);
    return 0;
}