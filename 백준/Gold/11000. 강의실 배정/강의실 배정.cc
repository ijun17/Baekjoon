#include <iostream>
#include <queue>
using namespace std;

struct Lecture{
    int S;//수업 시작시간
    int T;//수업 종료시간
    Lecture(int S, int T) : S(S), T(T) {}
    bool operator<(const Lecture& sb)const {
        return S>sb.S;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,T,S;
    priority_queue<Lecture> Lpq; //강의
    priority_queue<int,vector<int>,greater<int>> Tpq; //종료시간
    cin>>N;
    while(N--){
        cin>>S>>T;
        Lpq.emplace(S,T);
    }
    while(!Lpq.empty()){
        if(!Tpq.empty() && Tpq.top()<=Lpq.top().S)Tpq.pop();
        Tpq.push(Lpq.top().T);
        Lpq.pop();
    }
    cout<<Tpq.size();
    return 0;
}