#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//1339번: 단어 수학

struct Bosuk{
    int M;
    int V;
    Bosuk(int M, int V) : M(M), V(V) {}
    bool operator<(const Bosuk& bs) const{
        return M>bs.M;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<Bosuk> bosuks; //무게로 오름차순
    priority_queue<int> canBosuksPrice; //내림차순
    priority_queue<int,vector<int>,greater<int>> gabangs; //오름차순
    int N,K,M,V,C;
    unsigned long long sum=0;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>M>>V;
        bosuks.emplace(M,V); //무게, 가격
    }
    for(int i=0; i<K; i++){
        cin>>C;
        gabangs.push(C);
    }
    while(true){
        if(gabangs.empty())break;
        else{
            C=gabangs.top();
            gabangs.pop();
        }
        while(!bosuks.empty() && bosuks.top().M<=C){
            canBosuksPrice.push(bosuks.top().V);
            bosuks.pop();
        }
        if(!canBosuksPrice.empty()){
            sum+=canBosuksPrice.top();
            canBosuksPrice.pop();
        }else if(bosuks.empty())break;
    }
    cout<<sum;
    return 0;
}