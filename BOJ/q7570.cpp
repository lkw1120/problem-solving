#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int dp[MAX] = {0};
int N,k,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>k;
        dp[k] = dp[k-1]+1;
        ans = max(ans,dp[k]);
    }
    ans = N - ans;
    cout<<ans<<"\n";
    return 0;
}