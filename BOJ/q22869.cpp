#include<bits/stdc++.h>
using namespace std;
const int MAX = 5001;
int arr[MAX] = {0};
int dp[MAX] = {0};
int N,K;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];	
	}
	dp[1] = 1;
	for(int i=1;i<=N;i++) {
		if(dp[i]) {
			for(int j=i+1;j<=N;j++) {
				if(dp[j]) continue ;
				if((j-i)*(1+abs(arr[i]-arr[j])) <= K) {
					dp[j]++;
				}
			}
		}
	}
	ans = "NO";
	if(dp[N]) {
		ans = "YES";
	}
	cout<<ans<<"\n";
	return 0;
}