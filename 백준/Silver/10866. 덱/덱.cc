#include <iostream>
using namespace std;

int dat[22000],head=11000,tail=11000;

int empty(){return head==tail;}
void push_back(int data){dat[tail++]=data;}
void push_front(int data){dat[--head]=data;}
int pop_back(){if(empty())return -1;else return dat[--tail];}
int pop_front(){if(empty())return -1;else return dat[head++];}
int size(){return tail-head;}
int front(){if(empty())return -1;else return dat[head];}
int back(){if(empty())return -1;else return dat[tail-1];}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,temp;
    string s;
    cin>>N;
    while(N--){
        cin>>s;
        switch (s[1])
        {
        case 'u'://push
            cin>>temp;
            if(s[5]=='b')push_back(temp);
            else push_front(temp);
            break;
        case 'o'://pop
            if(s[4]=='b')cout<<pop_back()<<'\n';
            else cout<<pop_front()<<'\n';
            break;
        case 'i'://size
            cout<<size()<<'\n';
            break;
        case 'm'://empty
            cout<<empty()<<'\n';
            break;
        case 'r'://front
            cout<<front()<<'\n';
            break;
        case 'a'://back
            cout<<back()<<'\n';
            break;
        default:
            break;
        }
    }
    return 0;
}