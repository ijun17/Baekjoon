#include <iostream>
#include <queue>
using namespace std;

bool notPrime[4000001]={0}; //모두 소수로 설정

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,count=0,sum=0;
    queue<int> q; //연속된 소수
    cin>>N;
    
    for (long long i=2; i <= N; i++) {
		if (!notPrime[i]){
            for (long long j=i*i; j<=N; j+=i)notPrime[j] = 1;
            while(sum+i > N){
                sum-=q.front();
                q.pop();
            }
            q.push(i);
            sum+=i;
            if(sum == N)count++;
        }
	}
    cout<<count;
    return 0;
}