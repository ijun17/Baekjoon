#include <iostream>
using namespace std;

int K, n, sum=0, stack[100000], top=-1;

void push(int num){stack[++top]=num;}
int pop(){return stack[top--];}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    while(K-->0){
        cin>>n;
        if(n==0)pop();
        else push(n);
    }
    for(int i=0; i<=top; i++)sum+=stack[i];
    cout<<sum;
    return 0;
}