#include<bits/stdc++.h>
using namespace std;
vector<int> v[10002];
int dp[10002];
int N,K,P,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for(int i=0;i<K;i++) {
        cin>>P>>T;
        v[P].push_back(T);
    }
    dp[N+1] = 0;
    for(int i=N;i>=1;i--) {
        if(v[i].empty()) {
            dp[i] = dp[i+1]+1;
        }
        else {
            int tmp = 0;
            for(auto item: v[i]) {
                tmp = max(tmp,dp[i+item]);
            }
            dp[i] = tmp;
        }
    }
    ans = dp[1];
    cout<<ans<<"\n";
    return 0;
}