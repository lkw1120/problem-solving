#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
const double NEG_INF = -1e100;
vector<double> v;
double dp[MAX_N][2];
int N;
double Q,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>Q;
    v.resize(N+1);
    for(int i=1;i<=N;i++) {
        cin>>v[i];
    }
    fill(&dp[0][0],&dp[0][0]+MAX_N*2,NEG_INF);
    dp[0][0] = 100.0;
    for(int i=1;i<=N;i++) {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]*v[i]-Q);
        dp[i][1] = dp[i-1][1];
        if(dp[i-1][0] >= Q) {
            dp[i][1] = max(dp[i][1],(dp[i-1][0]-Q)/v[i]);
        }
    }
    ans = dp[N][0];
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
}