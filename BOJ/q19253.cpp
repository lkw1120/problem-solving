#include<bits/stdc++.h>
using namespace std;
int T,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        if(N%2) {
            cout<<"B"<<"\n";
        }
        else {
            cout<<"A"<<"\n";
        }
    }
    return 0;
}