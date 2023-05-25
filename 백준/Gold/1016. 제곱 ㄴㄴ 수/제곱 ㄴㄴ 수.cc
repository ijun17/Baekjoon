#include <iostream>
using namespace std;
#define ll long long
#define SIZE 1100000

bool notnum[SIZE]={0}; //모두 제곱 ㄴㄴ수 0=MIN
bool notPrime[SIZE]={0}; //처음에 모두 소수  i=n;  0이면 소수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll MIN, MAX;
    cin>>MIN>>MAX;
    
    for (ll i=2; i*i <= MAX; i++) { //  2 <= i <= 100000
		if (!notPrime[i]){
            ll i2=i*i;
            ll temp=(MIN%i2==0 ? MIN : MIN-MIN%i2+i2); //temp는 MIN보다 크거나 같고 i2로 나누어 떨어지는 수
            for (ll j=i2; j<SIZE; j+=i)notPrime[j] = 1; // 4 < j < SIZE = 1100000
            for (ll j=temp; j<=MAX; j+=i2)notnum[j-MIN]=1;// 0 <= temp-MIN <= j-MIN < MAX-MIN <= 1000000 < SIZE
        }
	}
    ll count=0;
    for(ll i=MIN; i<=MAX; i++)if(!notnum[i-MIN])count++;
    cout<<count;
    return 0;
}