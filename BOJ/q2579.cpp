#include<bits/stdc++.h>
#define FLOOR_MAX 300
#define SCORE_MAX 10000
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int dp[FLOOR_MAX+1] = {0};
    int score[SCORE_MAX+1] = {0};
    int N,ans;
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>score[i];
    }
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	for (int i=3;i<=N;i++) {
		dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i] + score[i-1]);
	}
	ans = dp[N];
    cout<<ans<<"\n";
    return 0;
}