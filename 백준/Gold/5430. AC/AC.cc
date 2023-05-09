#include <iostream>
using namespace std;

const int MX=1000000;

int dat[MX*2+1],head=MX,tail=MX;



int empty(){return head==tail;}
void push_back(int data){dat[tail++]=data;}
void push_front(int data){dat[--head]=data;}
int pop_back(){if(empty())return -1;else return dat[--tail];}
int pop_front(){if(empty())return -1;else return dat[head++];}//1번 연산
int size(){return tail-head;}
int front(){if(empty())return -1;else return dat[head];}
int back(){if(empty())return -1;else return dat[tail-1];}

bool reverse2=false;
void R(){reverse2=!reverse2;}
int D(){if(empty())return 0;if(reverse2)pop_back();else pop_front();return 1;}
void reset(){head=MX;tail=MX;reverse2=false;}
void printDQ(){
    cout<<'[';
    if(reverse2)for(int i=tail-1; i>=head; i--){
        cout<<dat[i];
        if(i>head)cout<<',';
    }else for(int i=head; i<tail; i++){
        cout<<dat[i];
        if(i<tail-1)cout<<',';
    }
    cout<<"]\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,N,temp;
    bool err=false;
    string s;
    char c; //temp
    cin>>T;
    while(T--){
        cin>>s>>N;
        cin>>c;
        for(int i=0; i<N; i++){
            cin>>temp;
            push_back(temp);
            if(i<N-1)cin>>c;
        }
        cin>>c;
        for(int i=0,l=s.length(); i<l; i++){
            if(s[i]=='R')R();
            else if(!D()){err=true;break;}
        }
        if(err)cout<<"error\n";
        else printDQ();
        reset();
        err=false;
    }   
    return 0;
}