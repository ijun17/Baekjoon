#include <iostream>
using namespace std;

int dat[2000010],head=0,tail=0;

int empty(){return head==tail;}
void push(int data){dat[tail++]=data;}
int pop(){if(empty())return -1;else return dat[head++];}
int size(){return tail-head;}
int front(){if(empty())return -1;else return dat[head];}
int back(){if(empty())return -1;else return dat[tail-1];}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, temp;
    string s;
    cin>>N;
    while(N--){
        cin>>s;
        switch (s[1])
        {
        case 'u': //push
            cin>>temp;
            push(temp);
            break;
        case 'o': //pop
            cout<<pop()<<'\n';
            break;
        case 'i': //size
            cout<<size()<<'\n';
            break;
        case 'a': //back
            cout<<back()<<'\n';
            break;
        case 'r': //front
            cout<<front()<<'\n';
            break;
        case 'm'://empty
            cout<<empty()<<'\n';
            break;
        default:
            break;
        }
    }
    return 0;
}
