#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
using namespace std;

int gcd(int a, int b){
    int temp;
    if(b>a){
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0){
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ninePac=362880;//9!
    int result=1;
    int gcd_temp;
    cin>>n;
    loop(i,1,10){
        gcd_temp=gcd(ninePac, n+i);
        ninePac/=gcd_temp;
        result=(result*((n+i)/gcd_temp))%10007;
    }
    cout<<result;
    return 0;
}