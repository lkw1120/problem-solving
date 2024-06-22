#include<bits/stdc++.h>
using namespace std;
int arr[21];
int dp[21][21][21];
int N,M,A,B,ans;
int find(int idx, int a, int b) {
    if(idx == M+1) {
        return 0;
    }
    if(dp[idx][a][b] != -1) {
        return dp[idx][a][b];
    }
    int aa = abs(b-arr[idx])+find(idx+1,a,arr[idx]);
    int bb = abs(a-arr[idx])+find(idx+1,arr[idx],b);
    dp[idx][a][b] = min(aa,bb);
    return dp[idx][a][b];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>A>>B;
    cin>>M;
    for(int i=1;i<=M;i++) {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    ans = find(1,A,B);
    cout<<ans<<"\n";
    return 0;
}