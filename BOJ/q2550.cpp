#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int A[MAX] = {0};
int B[MAX] = {0};
int arr[MAX] = {0};
int dp[MAX] = {0};
int memo[MAX] = {0};
vector<int> res;
int N;
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
	memo[1] = 1;
	for(int i=2;i<=N;i++) {
		if(dp[len] < arr[i]) {
			dp[++len] = arr[i];
			memo[i] = len;
		}
		else {
			int idx = lower_bound(dp+1,dp+len+1,arr[i])-dp;
			dp[idx] = arr[i];
			memo[i] = idx;
		}
	}
	cout<<len<<"\n";
	for(int i=N;i>0;i--) {
		if(memo[i] == len) {
			res.push_back(A[i]);
			len--;
		}
	}
	sort(res.begin(),res.end());
	for(auto item: res) {
		cout<<item<<" ";
	}
	cout<<"\n";
	return 0;
}