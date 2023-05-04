#include <iostream>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
#define MAX 10100
using namespace std;

//1406

int stack[MAX];
int topID=-1;

int size(){return topID+1;}
int empty(){return topID==-1;}
void push(int num){if(size()<MAX)stack[++topID]=num;}
int pop(){if(empty())return -1; else return stack[topID--];}
int top(){if(empty())return -1; else return stack[topID];}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n,temp;
    cin>>n;
    
    while(n-->0){
        cin>>s;
        switch(s[0]){
            case 'p':
                if(s.length()==4){cin>>temp;push(temp);} //push
                else cout<<pop()<<'\n'; //pop
                break;
            case 't'://top
                cout<<top()<<'\n';
                break;
            case 'e'://empty
                cout<<empty()<<'\n';
                break;
            case 's'://size
                cout<<size()<<'\n';
                break;
            default : break;
        }
    }
    return 0;
}