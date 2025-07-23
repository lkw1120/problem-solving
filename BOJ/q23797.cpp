#include<bits/stdc++.h>
using namespace std;
string str;
int K,P,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    K = P = ans = 0;
    for(char ch: str) {
        if(ch == 'K') {
            if(0 < P) {
                P--;
                K++;
            }
            else {
                K++;
                ans++;
            }
        }
        else if(ch == 'P') {
            if(0 < K) {
                K--;
                P++;
            }
            else {
                P++;
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}