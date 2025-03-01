#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
const int INF = 987654321;
int dp[MAX][MAX];
bool rest[MAX];
int N,M,ans;
int find(int d, int cnt) {
    if(N < d) {
        return 0;
    }
    if(dp[d][cnt] != INF) {
        return dp[d][cnt];
    }
    if(rest[d]) {
        return dp[d][cnt] = find(d+1,cnt);
    }
    dp[d][cnt] = min(dp[d][cnt],find(d+1,cnt)+10000);
    dp[d][cnt] = min(dp[d][cnt],find(d+3,cnt+1)+25000);
    dp[d][cnt] = min(dp[d][cnt],find(d+5,cnt+2)+37000);
    if(3 <= cnt) {
        dp[d][cnt] = min(dp[d][cnt],find(d+1,cnt-3));
    }
    return dp[d][cnt];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    int d;
    for(int i=1;i<=M;i++) {
        cin>>d;
        rest[d] = true;
    }
    fill(&dp[0][0],&dp[MAX-1][MAX],INF);
    ans = find(1,0);
    cout<<ans<<"\n";
    return 0;
}