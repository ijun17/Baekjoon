#include <iostream>
#include <algorithm>
#include <queue>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> card;
    int temp;
    int n,a,b;
    cin>>n;
    unsigned long long sum=0;
    if(n==1){
        cin>>temp;
        cout<<0;
        return 0;
    }
    loop(i,0,n){
        cin>>temp;
        card.push(temp);
    }
    while(true){
        a=card.top();
        card.pop();
        b=card.top();
        card.pop();
        sum+=a+b;
        if(card.empty())break;
        card.push(a+b);
    }
    cout<<sum;
    return 0;
}