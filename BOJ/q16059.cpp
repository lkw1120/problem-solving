#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 300001;
int arr[MAX_N];
int dp[MAX_N];
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++) {
        if(i <= M) {
            dp[i] = dp[i-1];
        }
        else {
            dp[i] = max(dp[i-1],dp[i-M]+arr[i]);
        }
    }
    ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}