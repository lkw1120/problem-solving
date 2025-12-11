#include<bits/stdc++.h>
using namespace std;
int K,N,M;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    for(int tc=1;tc<=K;tc++) {
        cin>>N>>M;
        vector<pair<int,double>> v(M);
        for(int i=0;i<M;i++) {
            cin>>v[i].first>>v[i].second;
        }
        vector<double> dp(N+1,0.0);
        dp[0] = 1.0;
        for(int i=0;i<N;i++) {
            if(dp[i] == 0.0) continue;
            for(auto [g,p]: v) {
                int next = min(N,i+g);
                dp[next] = max(dp[next],dp[i]*p);
            }
        }
        ans = dp[N];
        cout<<"Data Set "<<tc<<":"<<"\n";
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
    return 0;
}