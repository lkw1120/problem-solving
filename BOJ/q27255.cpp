#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1001];
ll dp[1001];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        ll tmp = 0;
        for(int j=0;j<i;j++) {
            if(arr[j] < arr[i]) {
                tmp = max(tmp,dp[j]);
            }
        }
        dp[i] = arr[i]+tmp;
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}