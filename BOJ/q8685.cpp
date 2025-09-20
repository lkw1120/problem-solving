#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6+1;
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
    fill(&dp[0][0],&dp[0][0]+MAX_N*2,1);
    for(int i=1;i<N;i++) {
        if(arr[i-1] <= arr[i]) {
            dp[i][0] = dp[i-1][0]+1;
        }
    }
    for(int i=N-2;i>=0;i--) {
        if(arr[i+1] <= arr[i]) {
            dp[i][1] = dp[i+1][1]+1;
        }
    }
    for(int i=0;i<N;i++) {
        ans = max(ans,dp[i][0]+dp[i][1]-1);
    }
    cout<<ans<<"\n";
    return 0;
}