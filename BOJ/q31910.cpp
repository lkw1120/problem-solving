#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[31][31];
ll dp[31][31];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])*2;
            if(arr[i][j]) {
                dp[i][j]++;
            }
        }
    }
    ans = dp[N][N];
    cout<<ans<<"\n";
    return 0;
}