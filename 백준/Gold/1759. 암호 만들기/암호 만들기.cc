#include <iostream>
#include <algorithm>
#define loop(i,n) for(int i=0; i<n; i++)
using namespace std;

bool isVowel(char c){return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');}

void printPassword(string text, int pwLength, int num=-1, string pw="", int vowelCount=0){
    if(pw.length()==pwLength-1){
        for(int i=num+1,l=text.length(); i<l; i++)
            if(vowelCount+isVowel(text[i])>0&&pwLength-vowelCount-isVowel(text[i])>1)cout<<pw<<text[i]<<'\n';
    }else{
        for(int i=num+1,l=text.length()+(pwLength-pw.length()); i<l; i++)
            printPassword(text, pwLength, i, pw+text[i], vowelCount+isVowel(text[i]));
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