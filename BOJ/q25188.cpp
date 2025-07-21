#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG = LLONG_MIN/4;
ll arr[2001];
ll prefix[2001];
ll dp[7][2001];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        prefix[i] = prefix[i-1]+arr[i];
    }
    fill(&dp[0][0],&dp[0][0]+7*2001,NEG);
    dp[0][0] = 0;
    for(int k=1;k<=6;k++) {
        for(int i=0;i<=N;i++) {
            ll tmp = NEG;
            for(int j=0;j<=i;j++) {
                if(dp[k-1][j] == NEG) continue;
                ll score = (k%2 == 1)? prefix[i]-prefix[j]: 0;
                tmp = max(tmp,dp[k-1][j]+score);
            }
            dp[k][i] = tmp;
        }
    }
    ans = dp[6][N];
    cout<<ans<<"\n";
    return 0;
}