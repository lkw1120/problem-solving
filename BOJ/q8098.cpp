#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
vector<pair<int,int>> v;
int dp[30001];
int N,M,P,K,ans;
bool compare(Pair a, Pair b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>P>>K;
        v.push_back({P,K});
        M = max(M,K);
    }
    sort(v.begin(),v.end(),compare);
    int t = 1;
    for(auto [a,b]: v) {
        while(t <= b) {
            dp[t] = max(dp[t],dp[t-1]);
            t++;
        }
        dp[b] = max(dp[b],dp[a]+(b-a));
    }
    ans = dp[M];
    cout<<ans<<"\n";
    return 0;
}