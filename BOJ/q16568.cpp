#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1000001;
int dp[MAX] = {0};
int N,A,B,ans;
void solve() {
	fill(dp,dp+MAX,INF);
	queue<int> q;
	q.push(N);
	dp[N] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(0 <= now-1 && dp[now]+1 < dp[now-1]) {
			dp[now-1] = dp[now]+1;
			q.push(now-1);
		}
		if(0 <= now-A && dp[now]+1 < dp[now-A]) {
			dp[now-A] = dp[now]+1;
			q.push(now-A);
		}
		if(0 <= now-B && dp[now]+1 < dp[now-B]) {
			dp[now-B] = dp[now]+1;
			q.push(now-B);
		}
	}
	ans = dp[0];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>A>>B;
	A++;
	B++;
	solve();
	cout<<ans<<"\n";
	return 0;
}