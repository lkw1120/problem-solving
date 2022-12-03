#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int dp[MAX] = {0};
int T,N;
void preload() {
	dp[0] = dp[1] = 1;
	for(int i=2;i<MAX;i++) {
		if(i%2) {
			dp[i] = dp[i-1];
		}
		else {
			dp[i] = dp[i-1]+dp[i/2];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>T;
	while(T--) {
		cin>>N;
		cout<<dp[N]<<"\n";
	}
	return 0;
}