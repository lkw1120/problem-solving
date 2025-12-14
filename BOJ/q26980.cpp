#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2005][2005];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    vector<ll> v(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    for(int i=0;i<N;i++) {
        dp[i][i] = v[i]*N;
    }
    for(int i=1;i<N;i++) {
        for(int j=0;j+i<N;j++) {
            int r = j+i;
            ll day = N-(r-j);
            dp[j][r] = max(v[j]*day+dp[j+1][r],v[r]*day+dp[j][r-1]);
        }
    }
    ans = dp[0][N-1];
    cout<<ans<<"\n";
    return 0;
}