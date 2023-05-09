#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,n,num,head,tail;
    bool err,reverse;
    string p;
    char c;
    cin>>T;
    while(T--){
        cin>>p>>n;
        cin>>c;
        int *arr=new int[n];
        head=0;
        tail=n;
        err=false;
        reverse=false;
        for(int i=0; i<n; i++)cin>>arr[i]>>c;
        if(n==0)cin>>c;
        for(int i=0,l=p.length(); i<l; i++){
            if(p[i]=='R')reverse=!reverse;
            else{
                if(head==tail){
                    err=true;
                    break;
                }
                if(reverse)tail--;
                else head++;
            }
        }
        if(err)cout<<"error\n";
        else {
            cout<<'[';
            if(reverse) for(int i=tail-1; i>=head; i--){
                cout<<arr[i];
                if(i>head)cout<<',';
            }
            else for(int i=head; i<tail; i++){
                cout<<arr[i];
                if(i<tail-1)cout<<',';
            }
            cout<<"]\n";
        }
        delete[] arr;
    }   
    return 0;
}