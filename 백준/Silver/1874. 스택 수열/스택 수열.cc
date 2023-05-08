#include <iostream>
using namespace std;

int n, a,stack[100010], top=-1, resultIndex=0;
char result[200010];
bool can=true;

void push(int num){stack[++top]=num;result[resultIndex++]='+';}
int pop(){result[resultIndex++]='-';return stack[top--];}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int j=1;
    for(int i=0; i<n; i++){
        cin>>a;
        for(;a>=j;j++)push(j);
        if(pop()!=a)can=false;
    }
    if(can)for(int i=0; i<resultIndex; i++)cout<<result[i]<<'\n';
    else cout<<"NO";
    return 0;
}