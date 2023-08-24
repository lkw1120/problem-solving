#include<bits/stdc++.h>
using namespace std;
int mem[101] = {0};
int cost[101] = {0};
int dp[10001] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>mem[i];
	}
	for(int i=1;i<=N;i++) {
		cin>>cost[i];
	}
	for(int i=1;i<=N;i++) {
		for(int j=10000;j>0;j--) {
			if(cost[i] <= j) {
				dp[j] = max(dp[j],dp[j-cost[i]]+mem[i]);
			}
		}
	}
	for(int i=1;i<10001;i++) {
		if(M <= dp[i]) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}