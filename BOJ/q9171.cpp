#include<bits/stdc++.h>
using namespace std;
int dp[2001];
vector<pair<int,int>> v;
int T,N,X;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        fill(dp,dp+2001,-1);
        v.clear();
        cin>>N;
        for(int i=0;i<N;i++) {
            int a;
            double b;
            cin>>a>>b;
            v.push_back({a,(int)round(b*100)});
        }
        cin>>X;
        dp[0] = 0;
        for(auto [a,b]: v) {
            for(int i=X;i>=0;i--) {
                if(dp[i] != -1 && i+a <= X) {
                    dp[i+a] = max(dp[i+a],dp[i]+b);
                }
            }
        }
        int idx = 0;
        int sum = 0;
        for(int i=0;i<=X;i++) {
            if(sum < dp[i]) {
                sum = dp[i];
                idx = i;
            }
        }
        double ans = sum/100.0;
        cout<<"Problem "<<tc<<": "<<idx<<" seconds scheduled for $";
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
    return 0;
}