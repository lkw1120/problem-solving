#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>C;
    if(C%2 == 0) {
        A = abs(A);
        B = abs(B);
    }
    if(A > B) {
        cout<<">"<<"\n";
    }
    else if(A < B) {
        cout<<"<"<<"\n";   
    }
    else {
        cout<<"="<<"\n";
    }
    return 0;
}