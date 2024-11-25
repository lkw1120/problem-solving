#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int arr[101];
ll dp[100001];
ll N,H,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>H;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    dp[0] = 1;
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[j] <= i) {
                dp[i] = (dp[i]+dp[i-arr[j]])%MOD;
            }
        }
    }
    ans = dp[H];
    cout<<ans<<"\n";
    return 0;
}