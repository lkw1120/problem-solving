#include<bits/stdc++.h>
#define MAX 41
using namespace std;
int dp[MAX] = {0};
int vip[MAX] = {0};
int N,M,ans;
void fibo() {
	dp[0] = dp[1] = 1;
	for(int i=2;i<MAX;i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fibo();
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>vip[i];
	}
	ans = 1;
	for(int i=1;i<=M;i++) {
		ans*=dp[vip[i]-(vip[i-1]+1)];
	}
	ans*=dp[N-vip[M]];
	cout<<ans<<"\n";
	return 0;
}