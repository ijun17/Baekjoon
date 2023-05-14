#include <iostream>
#include <algorithm>
using namespace std;

//1339번: 단어 수학

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N=0,sum=0,nums[26]={0};
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        int temp=1;
        for(int i=s.length()-1; i>=0; i--){
            nums[s[i]-'A']+=temp;
            temp*=10;
        }
    }
    sort(nums,nums+26);
    for(int i=0; i<10; i++)sum+=i*nums[i+16];
    cout<<sum;
    return 0;
}