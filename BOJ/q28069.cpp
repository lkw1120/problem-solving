#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1e6+1;
int dp[MAX];
int N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    fill(dp,dp+MAX,INF);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=1;i<N;i++) {
        if(i+i/2 <= N) {
            dp[i+i/2] = min(dp[i+i/2],dp[i]+1);
        }
        if(i+1 <= N) {
            dp[i+1] = min(dp[i+1],dp[i]+1);
        }
    }
    if(dp[N] <= K) {
        cout<<"minigimbob"<<"\n";
    }
    else {
        cout<<"water"<<"\n";
    }
    return 0;
}