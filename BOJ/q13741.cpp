#include<bits/stdc++.h>
using namespace std;
string input;
int dp[51] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	N = input.size();
	ans = 25;
	for(int i=0;i<N;i++) {
		for(int j=i;j>=0;j--) {
			if(input[j] < input[i]) {
				dp[i] = max(dp[i],dp[j]+1);	
			}
		}
		ans = min(ans,25-dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}