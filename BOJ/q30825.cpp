#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5+1;
ll arr[MAX];
ll dp[MAX];
ll N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    dp[1] = arr[1];
    for(int i=2;i<=N;i++) {
        dp[i] = max(arr[i],dp[i-1]+K);
    }
    ans = 0;
    for(int i=N;i>0;i--) {
        ans+=dp[N]-(N-i)*K-arr[i];
    }
    cout<<ans<<"\n";
    return 0;
}