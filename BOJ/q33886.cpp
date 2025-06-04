#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int arr[3001];
int dp[3001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    fill(dp,dp+3001,INF);
    dp[0] = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=i;j++) {
            int len = i-j+1;
            if(len <= arr[j]) {
                dp[i] = min(dp[i],dp[j-1]+1);
            }
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}