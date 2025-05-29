#include <bits/stdc++.h>
using namespace std;
int N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>hex;
    ans = "";
    for(int i=0;i<N;i++) {
        int ch;
        cin>>ch;
        ans+=(ch < 0x20)? ".": "-";
    }
    cout<<ans<<"\n";
    return 0;
}