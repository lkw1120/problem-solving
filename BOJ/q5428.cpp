#include<bits/stdc++.h>
using namespace std;
const double NEG_INF = -987654321.0;
vector<pair<int,double>> v;
double dp[151];
int T,N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        fill(dp,dp+151,NEG_INF);
        v.clear();
        cin>>N;
        for(int i=0;i<N;i++) {
            int p;
            double q;
            cin>>p>>q;
            v.push_back({p,log(q/100.0)});
        }
        dp[0] = 0;
        for(auto [p,q]: v) {
            for(int i=150-p;i>=0;i--) {
                if(dp[i] != NEG_INF) {
                    dp[i+p] = max(dp[i+p],dp[i]+q);
                }
            }
        }
        double tmp = NEG_INF;
        for(int i=76;i<=150;i++) {
            if(dp[i] == NEG_INF) continue;
            tmp = max(tmp,dp[i]);
        }
        ans = exp(tmp)*100;
        cout<<fixed<<setprecision(10)<<ans<<"\n";
    }
    return 0;
}