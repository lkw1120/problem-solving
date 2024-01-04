#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int dp[MAX];
int T,N;
void init() {
	for(int i=1;i<MAX;i++) {
		int n = sqrt(i);
		if(n*n == i) {
			dp[i] = 1;	
		}
		else {
			dp[i] = dp[i-n*n]+1;
			for(int j=n;j>0;j--) {
				dp[i] = min(dp[i],dp[i-j*j]+dp[j*j]);	
			}
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
		cin>>N;
		cout<<"Case #"<<t<<": "<<dp[N]<<"\n";
	}
	return 0;
}