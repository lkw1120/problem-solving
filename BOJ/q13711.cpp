#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int A[MAX] = {0};
int B[MAX] = {0};
int arr[MAX] = {0};
int dp[MAX] = {0};
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
    for(int i=1;i<=N;i++) {
		cin>>A[i];	
	}
	int tmp;
	for(int i=1;i<=N;i++) {
		cin>>tmp;
		B[tmp] = i;
	}
	for(int i=1;i<=N;i++) {
		arr[i] = B[A[i]];
	}
	int len = 1;
	dp[1] = arr[1];
	for(int i=2;i<=N;i++) {
		if(dp[len] < arr[i]) {
			dp[++len] = arr[i];
		}
		else {
			int idx = lower_bound(dp+1,dp+len+1,arr[i])-dp;
			dp[idx] = arr[i];
		}
	}
	ans = len;
	cout<<ans<<"\n";
	return 0;
}