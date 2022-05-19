#include<bits/stdc++.h>
#define MAX 1000001
#define DIV 1000000009
using namespace std;
int dp[MAX] = {0};
int T,N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int t=0;t<T;t++) {
		cin>>N;
		if(dp[N] == 0) {
			for(int i=4;i<=N;i++) {
				if(dp[i] != 0) continue;
				dp[i] = (((dp[i-1] + dp[i-2])%DIV) + dp[i-3])%DIV;
			}
		}
		cout<<dp[N]<<"\n";
	}
	return 0;
}