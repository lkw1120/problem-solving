#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
vector<int> v[26];
int dp[2][26];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            if(N <= abs(i-j)) {
                v[i].push_back(j);
            }
        }
    }
    for(int j=0;j<26;j++) {
        dp[1][j] = 1;
    }
    for(int i=2;i<=M;i++) {
        int cur = i%2;
        int prev = 1-cur;
        fill(dp[cur],dp[cur]+26,0);
        for(int j=0;j<26;j++) {
            int tmp = dp[prev][j];
            if(!tmp) continue;
            for(auto k: v[j]) {
                dp[cur][k] = (dp[cur][k]+tmp)%MOD;
            }
        }
    }
    int tmp = M%2;
    ans = 0;
    for(int j=0;j<26;j++) {
        ans = (ans+dp[tmp][j])%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}