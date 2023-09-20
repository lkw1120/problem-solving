#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[26][26] = {0};
ll T,R,C;
void init() {
	for(int i=1;i<=25;i++) {
		dp[i][1] = dp[1][i] = 1;
	}
	for(int i=2;i<=25;i++) {
		for(int j=2;j<=25;j++) {
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>R>>C;
		cout<<"Case #"<<t<<": "<<dp[R][C]<<"\n";
	}
	return 0;
}