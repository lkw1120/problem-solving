#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[101][1001];
int arr[10];
int N,M,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++) {
        if(arr[i]) {
            dp[1][arr[i]%K] = (dp[1][arr[i]%K]+1)%MOD;
        }
    }
    for(int j=1;j<M;j++) {
        for(int k=0;k<K;k++) {
            if(dp[j][k]) {
                for (int i=0;i<N;i++){
                    int tmp = (k*10+arr[i])%K;
                    dp[j+1][tmp] = (dp[j+1][tmp]+dp[j][k])%MOD;
                }
            }
        }
    }
    ans = dp[M][0];
    cout<<ans<<"\n";
    return 0;
}