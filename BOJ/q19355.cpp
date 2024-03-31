#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+1;
ll arr[MAX];
ll dp[MAX];
ll T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        dp[1] = arr[1];
        dp[2] = arr[2];
        ans = max(arr[1],arr[2]);
        for(int i=3;i<=N;i++) {
            dp[i] = max(dp[i-2]+arr[i-1]+arr[i],arr[i]);
            ans = max(dp[i],ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}