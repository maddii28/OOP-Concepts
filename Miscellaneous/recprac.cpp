
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void recurse(int a){
    if(a<20){
        cout <<'a';
        for (int i = a; i>1; i--) cout << 'b';
        recurse (a*2); 
        cout <<'c';
    }
}
/*
size_t len(const char* wrd){
    if (!wrd){return;}
    wrd = wrd[1];
    size_t result += 1;
}
*/

void foo(int x){
    if(x>1){
        cout<<x<<":";
        foo (x/2) ;
        for(int i = x; i>0; i--){
            cout << ":";
        }
        cout << ",";
        foo(x/2);
    }
}

int main() {
    recurse (5);
    foo(4);
}