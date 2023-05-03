#include <iostream>
#include <string>
#include <list>
#define loop(i,s,e) for(int i=s; i<e; i++)
#define Loop(i,s,e) for(int i=s; i<=e; i++)
using namespace std;

//1406

class TextByLL{
private:
    list<char> text;
    list<char>::iterator it;
public:
    TextByLL(const string& text){
        for(char c : text)this->text.push_back(c);
        it=this->text.end();
    }
    void L(){if(this->it!=this->text.begin())this->it--;}
    void D(){if(this->it!=this->text.end())this->it++;}
    void B(){if(this->it!=this->text.begin())this->it=this->text.erase(--this->it);}
    void P(char c){this->text.insert(this->it, c);}
    void print(){for(char c : this->text)cout<<c;}
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string text;
    char query,c;
    int n;
    cin>>text>>n;
    TextByLL tbll(text);
    for(int i=0; i<n; i++){
        cin>>query;
        switch (query){
        case 'L':
            tbll.L();
            break;
        case 'D':
            tbll.D();
            break;
        case 'B':
            tbll.B();
            break;
        case 'P':
            cin>>c;
            tbll.P(c);
            break;
        default:
            break;
        }
    }
    tbll.print();
    return 0;
}