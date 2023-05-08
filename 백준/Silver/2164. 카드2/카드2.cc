#include <iostream>
using namespace std;

int dat[1100000],head=0,tail=0;

int empty(){return head==tail;}
void push(int data){dat[tail++]=data;}
int pop(){if(empty())return -1;else return dat[head++];}
int size(){return tail-head;}
int front(){if(empty())return -1;else return dat[head];}
int back(){if(empty())return -1;else return dat[tail-1];}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=1; i<=N; i++)push(i);
    while(true){
        if(size()==1)break;
        pop();
        if(size()==1)break;
        push(pop());
    }
    cout<<pop();
    return 0;
}