#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 300001;
ll arr[MAX_N];
ll dp[MAX_N][2];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    dp[0][0] = arr[0];
    dp[N-1][1] = arr[N-1];
    for(int i=1;i<N;i++) {
        dp[i][0] = max(arr[i],dp[i-1][0]+arr[i]);
        dp[N-i-1][1] = max(arr[N-i-1],dp[N-i][1]+arr[N-i-1]);
    }
    for(int i=0;i<N;i++) {
        ans = dp[i][0]+dp[i][1]-arr[i];
        cout<<ans<<" ";
    }
    cout<<"\n";
    return 0;
}