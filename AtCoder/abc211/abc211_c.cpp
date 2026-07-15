#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
string S;
ll dp[9];
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S;
    string str = "chokudai";
    dp[0] = 1;
    for(char ch: S) {
        for(int i=7;i>=0;i--) {
            if(ch == str[i]) {
                dp[i+1] = (dp[i+1]+dp[i])%MOD;
            }
        }
    }
    ans = dp[8];
    cout<<ans<<"\n";
    return 0;
}