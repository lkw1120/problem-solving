#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 200001;
ll arr[MAX][2];
ll dp[MAX][2];
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i][0];
    }
    for(int i=1;i<=N;i++) {
        cin>>arr[i][1];
    }
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    for(int i=2;i<=N;i++) {
        dp[i][0] = min(dp[i-1][0]+arr[i][0],dp[i-1][1]+arr[i][0]+K);
        dp[i][1] = min(dp[i-1][1]+arr[i][1],dp[i-1][0]+arr[i][1]+K);
    }
    ans = min(dp[N][0],dp[N][1]);
    cout<<ans<<"\n";
    return 0;
}