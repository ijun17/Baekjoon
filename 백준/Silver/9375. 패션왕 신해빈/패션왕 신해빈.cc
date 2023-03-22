#include <iostream>
#include <map>
#define loop(i,s,e) for(int i=s; i<e; i++)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string,int> cloth;
    int T,n,sol=1;
    string a,b;
    cin>>T;
    while(T-->0){
        cin>>n;
        while(n-->0){
            cin>>a>>b;
            auto itr=cloth.find(b);
            if(itr == cloth.end())cloth.insert({b,1});
            else (itr->second)++;
        }
        for(auto &itr : cloth){
            sol*=itr.second +1;
        }
        cout<<sol-1<<'\n';
        sol=1;
        cloth.clear();
    }
    return 0;
}