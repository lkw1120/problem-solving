#include<bits/stdc++.h>
#define MAX 10001
#define DIV 1000000000
using namespace std;
int dp[MAX] = {0};
int N,K;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	K = N+K-1;
	dp[0] = dp[1] = 1;
	for(int i=2;i<=K;i++) {
		dp[i] = 1;
		for(int j=i-1;j>0;j--) {
			dp[j] = (dp[j-1] + dp[j])%DIV;
		}
	}
	cout<<dp[N];
	return 0;
}