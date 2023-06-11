#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int facto[9] = {0};
int arr[MAX] = {0};
int dp[MAX] = {0};
int N, ans;
void preload() {
	facto[0] = 1;
	for(int i=1;i<=8;i++) {
		facto[i] = i*facto[i-1];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>N;
	for(int i=1;i<=N;i++) {
		dp[i] = i;	
	}
	for(int i=2;i<=N;i++) {
		for(int j=1;j<=8;j++) {
			if(0 <= i-facto[j]) {
				dp[i] = min(dp[i],dp[i-facto[j]]+1);	
			}
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;
}