#include<bits/stdc++.h>
#define MAX 10001
#define DIV 1000000007
using namespace std;
int dp[MAX] = {0};
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		dp[i] = 1;	
	}
	for(int i=M;i<=N;i++) {
		dp[i] = (dp[i-1] + dp[i-M])%DIV;
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;
}