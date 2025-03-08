#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
double dp[MAX];
int N;
double ans;
double find(int n) {
    if(n <= 0) {
        return 0.0;
    }
    if(-0.5 < dp[n]) {
        return dp[n];
    }
    dp[n] = 0.0;
    for(int i=1;i<=6;i++) {
        dp[n]+=(find(n-i)+1)/6.0;
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    fill(dp,dp+MAX,-1);
    ans = find(N);
    cout.precision(10);
    cout<<fixed<<ans<<"\n";
    return 0;
}