#include <bits/stdc++.h>
using namespace std;
char ch;
int S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>S>>ch) {
        if(ch == 'K') {
            ans = S == 1? 1: 4;
        }
        if(ch == 'N') {
            ans = S <= 2? 1: 2;
        }
        if(ch == 'B' || ch == 'R') {
            ans = S;
        }
        cout<<ans<<"\n";
    }
    return 0;
}