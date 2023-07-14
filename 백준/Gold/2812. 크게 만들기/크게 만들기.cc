#include <iostream>
using namespace std;
#define loop(i,s,e) for(int i=s; i<e; i++)

char st[500000];
int cnt=0;
int top(){return st[cnt-1];}
int size(){return cnt;}
void pop(){cnt--;}
void push(char c){st[cnt++]=c;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;

    char temp;
    loop(i,0,N){
        cin>>temp;
        while(K>0 && size()>0 && top()<temp){
            pop();
            K--;
        }
        push(temp);
    }
    for(int i=0,l=size()-K; i<l; i++)cout<<st[i];
    return 0;
}