#include <iostream>
#include <list>
using namespace std;

class CList{
private:
    list<int> li;
    list<int>::iterator it;
public:
    CList(int num){
        for(int i=1,l=num+1; i<l; i++)li.push_back(i);
        it=li.begin();
    }
    int erase(){
        if(this->size()==0)return -1;
        int num=*it;
        it=li.erase(it);
        if(it==li.end())it=li.begin();
        return num;
    }
    void moveIter(int num){
        if(this->size()==0)return;
        for(int i=0,l=num%(this->size()); i<l; i++){
            if(++it==li.end())it=li.begin();
        }
    }
    int size(){return li.size();}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;
    CList cli(N);
    cout<<"<";
    for(int i=0; i<N; i++){
        cli.moveIter(K-1);
        cout<<cli.erase();
        if(i==N-1)cout<<">";
        else cout<<", ";
    }
    return 0;
}