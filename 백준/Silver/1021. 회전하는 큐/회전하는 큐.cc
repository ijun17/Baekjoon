#include <iostream>
using namespace std;

const int MX=10000;

int dat[MX*2+1],head=MX,tail=MX,count2=0;

int empty(){return head==tail;}
void push_back(int data){dat[tail++]=data;}
void push_front(int data){dat[--head]=data;}
int pop_back(){if(empty())return -1;else return dat[--tail];}
int pop_front(){if(empty())return -1;else return dat[head++];}//1번 연산
int size(){return tail-head;}
int front(){if(empty())return -1;else return dat[head];}
int back(){if(empty())return -1;else return dat[tail-1];}

void second(){push_back(pop_front()); count2++;}
void third(){push_front(pop_back()); count2++;}
int search(int num){for(int i=head;i<tail;i++)if(dat[i]==num)return i-head; return -1;}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,temp,id;
    cin>>N>>M;
    for(int i=1; i<=N; i++)push_back(i);
    while(M--){
        cin>>temp;
        id=search(temp);
        if(id*2<size())while(id--)second();
        else while(id++<size())third();
        pop_front();
    }
    cout<<count2;
    return 0;
}